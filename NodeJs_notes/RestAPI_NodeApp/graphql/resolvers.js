const User = require('../models/user');
const Post = require('../models/post');
const bcrypt = require('bcrypt');
const validator = require('validator');
const jwt = require('jsonwebtoken');

module.exports = {
    hello(){
        // return "Hello world!";
        return {
            text: 'Hello world!',
            views: 100
        };
    },
    // createUser(args, req){
    // const  email = args.userInput.email;

    createUser: async function({ userInput }, req){

        const errors = [];

        if(!validator.isEmail(userInput.email)){
            errors.push({message : "Email is not valid"});
        }

        if(validator.isEmpty(userInput.password) || !validator.isLength(userInput.password, {min: 5})){
            errors.push({message : "Password is too short"});
        }

        if(errors.length > 0){
            const error = new Error("Invalid Input");
            error.data = errors;
            error.code = 422;
            throw error;
        }

        const email = userInput.email;
        const existingUser = await User.findOne({email : email});
        if(existingUser){
            const newError = new Error("User already Exists");
            throw newError;
        }

        const hashPwd = await bcrypt.hash(userInput.password, 12);

        const user = new User({
            email: email,
            name: userInput.name,
            password: hashPwd
        });

        const creatorUser = await user.save();
        return { ...creatorUser._doc, _id: creatorUser._id.toString()};
    },

    login: async function({email, password}){
        const user = await User.findOne({email: email});
        if(!user){
            const error = new Error("User Not Found");
            error.code = 401;
            throw error;
        }
        const isEqual = await bcrypt.compare(password, user.password);

        if(!isEqual){
            const error = new Error("Password is incorrect");
            error.code = 401;
            throw error;
        }

        const token = jwt.sign({
            userId: user._id.toString(),
            email: user.email
        }, 'SuperLongSecret', {expiresIn: '1h'});

        return {token: token, userId: user._id.toString()};
    },

    createPost: async function({ postInput }, req){
        if(!req.isAuth){
            const error = new Error("Unauthenticated User !");
            // error.data = errors;
            error.code = 401;
            throw error;
        }
        const errors = [];

        if(validator.isEmpty(postInput.title) || !validator.isLength(postInput.title, {min: 5})){
            errors.push({message : "Title is too short"});
        }

        if(validator.isEmpty(postInput.content) || !validator.isLength(postInput.content, {min: 5})){
            errors.push({message : "Content is too short"});
        }

        if(errors.length > 0){
            const error = new Error("Invalid Input");
            error.data = errors;
            error.code = 422;
            throw error;
        }

        const user = await User.findById(req.userId);

        if(!user){
            const error = new Error("Invalid User !");
            error.data = errors;
            error.code = 401;
            throw error;
        }

        const post = new Post({
            title: postInput.title,
            content: postInput.content,
            imageUrl: postInput.imageUrl,
            creator: user
        });

        const createdPost = await post.save();

        user.posts.push(createdPost);
        await user.save();

        // await User.findByIdAndUpdate(req.userId, { $push: { posts: createdPost._id } });

        return { ...createdPost._doc, _id: createdPost._id.toString(), createdAt: createdPost.createdAt.toString(), 
            updatedAt: createdPost.updatedAt.toString()
         };

    },

    posts: async function({page}, req){
        if(!req.isAuth){
            const error = new Error("Unauthenticated User !");
            // error.data = errors;
            error.code = 401;
            throw error;
        }
        if(!page){
            page = 1;
        }
        const perPage = 2;

        const totalPosts = await Post.find().countDocuments();
        const posts = await Post.find().sort({createdAt: -1})
        .skip((page-1)*perPage)
        .limit(perPage)
        .populate('creator');

        return {posts: posts.map(p=>{
            return {...p._doc, _id: p._id.toString(), createdAt: p.createdAt.toString(), updatedAt: p.updatedAt.toString()};
        }), totalPosts: totalPosts};

    }

};