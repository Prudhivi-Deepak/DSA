const User = require('../models/user');
const { validationResult, Result } = require('express-validator');
const bcrypt = require('bcrypt');
const jwt = require('jsonwebtoken');

exports.signup = (req, res, next) => {

    const errors = validationResult(req);
    if (!errors.isEmpty()) {
        const error = new Error("Validation failed");
        error.statusCode = 422;
        error.data = errors.array();
        throw error;
        // return res.status(422).json({ errors: errors.array() });
    }

    bcrypt.hash(req.body.password, 12)
    .then(hashedPassword => {
        const user = new User({
            email: req.body.email,
            name: req.body.name,
            password: hashedPassword
        })

        return user.save();
    })
    .then(result=>{
        res.status(201).json({message: "USer created", userId: result._id});
    })
    .catch(err => {
        if (!err.statusCode) {
            err.statusCode = 500;
        }
        next(err);
    });
};

exports.login = (req, res, next)=>{
    const email = req.body.email;
    const password = req.body.password;
    let loadedUser;

    User.findOne({email : email}).
    then(user=>{
        if (!user) {
            const newError = new Error("User not found");
            newError.statusCode = 401;
            throw newError;
        }
        loadedUser = user;
        return bcrypt.compare(password, user.password);
    })
    .then(isEqual=>{
        if(!isEqual){
            const newError = new Error("Wrong Password");
            newError.statusCode = 401;
            throw newError;
        }

        const token = jwt.sign({
            email: loadedUser.email,
            userId: loadedUser._id.toString()
        }, 'superLongStringSecret', {expiresIn: '1h'});

        return res.status(200).json({
            token: token,
            userId: loadedUser._id.toString(),
        })
    })
    .catch(err=>{
         if (!err.statusCode) {
            err.statusCode = 500;
        }
        next(err);
    })

};