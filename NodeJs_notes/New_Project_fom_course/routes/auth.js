const express = require('express');
// const {check} = require('express-validator/check'); //gives us a check function whihc returns a middleware
const {check, body} = require('express-validator'); //gives us a check function whihc returns a middleware
const User = require('../models/users');

const authController = require('../controllers/auth');

const router = express.Router();

router.get('/login', authController.getLogin);

router.get('/signup', authController.getSignup);

router.post('/login', [
    check('email').isEmail().normalizeEmail(),
    body('password', 'this second argument is default error message for all checks here for password 5 chars & alph numeric').isLength({min: 2}).isAlphanumeric(),
],authController.postLogin);

router.post('/signup', 
    [
    check('email').isEmail().withMessage("Invalid email").custom((value, {req})=>{
        if(value=="test@test.com"){
            throw new Error("This email address is forbidden");
        }

        return User.findOne({email: value})
        .then(user=>{
            if(user){
                // req.flash('error', 'Email already exisits');
                // return res.redirect('/signup');
                return Promise.reject('Email already exisits');
            }
        })
        // .catch(err=>{

        // })
    }),

    body('password', 'this second argument is default error message for all checks here for password 5 chars & alph numeric').isLength({min: 5}).isAlphanumeric(),
    body('confirmPassword', 'passwords are not same, please enter same passwords').custom((value, {req})=>{
        if(value !== req.body.password){
            throw new Error("Password have to match");
        }
        return true;
    })

    ], 

authController.postSignup);

router.post('/logout', authController.postLogout);

router.get('/reset', authController.getReset);

router.get('/reset/:token', authController.getNewPassword);

router.post('/reset', authController.postReset);

router.post('/new-password', authController.postNewPassword);

module.exports = router;