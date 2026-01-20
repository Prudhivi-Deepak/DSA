const { validationResult } = require('express-validator');
const Post = require('../models/post');
const fs = require('fs');
const path = require('path');
const User = require('../models/user');
const io = require('../socket');

exports.getPosts = async (req, res, next) => {

    const page = req.query.page || 1;
    const perPage = 1;
    let totalItems;

    const count = await Post.find().populate('creator').countDocuments()
        // .then(count => {
    totalItems = count;
    const posts =  await Post.find().sort({createdAt: -1}).skip((page - 1) * perPage).limit(perPage);
        // })
        // .then(posts => {
    if (!posts) {
        const newError = new Error("validation failed");
        newError.statusCode = 404;
        throw newError;
    }
    console.log("totalItems : ", totalItems);
    
    res.status(200).json({
        message: "Post fetched",
        posts: posts,
        totalItems: totalItems
    });
        // })
        // .catch(err => {
        //     if (!err.statusCode) {
        //         err.statusCode = 500;
        //     }
        //     next(err);
        // })

    // Post.find().countDocuments()
    //     .then(count => {
    //         totalItems = count;
    //         return Post.find().skip((page - 1) * perPage).limit(perPage);
    //     })
    //     .then(posts => {
    //         if (!posts) {
    //             const newError = new Error("validation failed");
    //             newError.statusCode = 404;
    //             throw newError;
    //         }
    //         console.log("totalItems : ", totalItems);
    //         res.status(200).json({
    //             message: "Post fetched",
    //             posts: posts,
    //             totalItems: totalItems
    //         });
    //     })
    //     .catch(err => {
    //         if (!err.statusCode) {
    //             err.statusCode = 500;
    //         }
    //         next(err);
    //     })

    // res.status(200).json({
    //     posts: [{
    //         _id: '1',
    //         title: 'First Post',
    //         content: 'This is the first post!',
    //         imageUrl: 'images/MESSI.jpg',
    //         creator: {
    //             name: 'JOHN',
    //         },
    //         createdAt: new Date()
    //     }]
    // });
};

exports.createPost = (req, res, next) => {
    const errors = validationResult(req);

    if (!errors.isEmpty() || !req.file) {
        const newError = new Error("validation failed or image not provided ");
        newError.statusCode = 422;
        throw newError;
    }

    const imageUrl = req.file.path.replace("\\", "/");

    console.log("req.userId : ", req.userId);

    const post = new Post({
        title: req.body.title,
        content: req.body.content,
        imageUrl: imageUrl,
        creator: req.userId
        // {_id : req.userId}
        // {
        //     name: "Yash",
        // },
    });
    let creator;
    post.save()
    .then(result => {
        console.log("result 1 : ", result);
        return User.findById(req.userId);
    })
    .then(user => {
        console.log("user : ", user);
        creator = user;
        user.posts.push(post);
        return user.save();
    })
    .then(result => {
        console.log("result : ", result);
        io.getIo().emit('posts', { action: 'create' , post : {...post._doc, creator: { _id: req.userId, name: result.name}} })

        res.status(201).json({
            message: 'Post created successfully!',
            post: post,
            creator: {_id: creator._id, name: creator.name}
        })
    })
    .catch(err => {
        // console.log(err)
        if (!err.statusCode) {
            err.statusCode = 500;
        }
        next(err);
    });
};

exports.getPost = (req, res, next) => {
    const postId = req.params.postId;
    Post.findById(postId).then(post => {
        if (!post) {
            const newError = new Error("validation failed");
            newError.statusCode = 404;
            throw newError;
        }
        res.status(200).json({
            message: "Post fetched",
            post: post
        });
    }).catch(err => {
        if (!err.statusCode) {
            err.statusCode = 500;
        }
        next(err);
    })
}

exports.updatePost = (req, res, next) => {
    const postId = req.params.postId;
    const errors = validationResult(req);
    if (!errors.isEmpty() || !req.file) {
        const newError = new Error("validation failed");
        newError.statusCode = 422;
        throw newError;
    }

    const title = req.body.title;
    const content = req.body.content;
    const imageUrl = req.file.path.replace("\\", "/");

    Post.findById(postId).populate('creator').then(post => {
        if (!post) {
            const newError = new Error("validation failed");
            newError.statusCode = 404;
            throw newError;
        }

        if(post.creator._id.toString() === req.userId ){
            const error = new Error("Not Authorized");
            error.statusCode =  403;
            throw error;
        }

        if (imageUrl !== post.imageUrl) {
            clearImage(post.imageUrl);
        }

        post.title = title;
        post.content = content;
        post.imageUrl = imageUrl;

        return post.save();

    })
        .then(result => {
            io.getIo().emit('posts', { action: 'update' , post : result })
            res.status(200).json({ message: 'post Updated', post: result });
        })
        .catch(err => {
            if (!err.statusCode) {
                err.statusCode = 500;
            }
            next(err);
        });
    // Post.findByIdAndUpdate(postId, updateData, { new: true })
    //     .then(post => {
    //         if (!post) {
    //             const newError = new Error("Post not found");
    //             newError.statusCode = 404;
    //             throw newError;
    //         }
    //         res.status(200).json({
    //             message: "Post updated successfully",
    //             post: post
    //         });
    //     })
    //     .catch(err => {
    //         if (!err.statusCode) {
    //             err.statusCode = 500;
    //         }
    //         next(err);
    //     });
};

exports.deletePost = (req, res, next) => {
    const postId = req.params.postId;

    Post.findById(postId).then(post => {
        if (!post) {
            const newError = new Error("validation failed");
            newError.statusCode = 404;
            throw newError;
        }

        console.log(post.creator.toString(), req.userId.toString());

        if(post.creator.toString() !== req.userId.toString() ){
            const error = new Error("Not Authorized");
            error.statusCode =  403;
            throw error;
        }

        clearImage(post.imageUrl);
        return post.deleteOne();

    })
        .then(result => {
            return User.findById(req.userId); 
        })
        .then(user=>{
            user.posts.pull(postId);
            return user.save();
        })
        .then(result=>{
            io.getIo().emit('posts', { action: 'delete' , post : postId  });
            res.status(200).json({ message: 'post Deleted' });
        })
        .catch(err => {
            if (!err.statusCode) {
                err.statusCode = 500;
            }
            next(err);
        });
}

const clearImage = filePath => {
    filepath = path.join(__dirname, '..', filePath);
    fs.unlink(filePath, (err) => {
        console.log(err);
    })
};