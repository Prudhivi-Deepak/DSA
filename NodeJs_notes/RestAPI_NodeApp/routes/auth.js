const express = require('express');
const { body } = require('express-validator');
const router = express.Router();
const User = require('../models/user');

const authController = require('../controllers/auth');

router.put('/signup', [
    body('email').isEmail().withMessage('Please enter a valid email address.')
    .custom((value, {req})=>{
        return User.findOne({email: value}).then(userDoc=>{
            if(userDoc){
                console.log("user found : ", userDoc);
                return Promise.reject("Email address already exists");
            }
            return true;
        })
    })
    .normalizeEmail(),
    body('password').trim().isLength({ min: 5 }).withMessage('Password must be at least 6 characters long.'),
    body('name').trim().not().isEmpty()
    // Add your validation middleware here, e.g., check('email').isEmail()
], authController.signup);

router.post('/login', authController.login);

module.exports = router;