
const path = require('path');
const express = require('express'); //exports a function
const router = express.Router();
const userController  = require('../controllers/usersController');
// const rootDir = require('../util/path');
// const adminData = require('./admin');

router.get('/home', userController.getIndex);

router.get('/users', userController.getUsers);
router.get('/cart', userController.getCart);
router.get('/orders', userController.getOrders);
router.get('/checkout', userController.checkout);
// router.use('/home', (req, res, next)=>{
//     console.log("In the another middleware!");
//     res.send("Response from send");//utility function to send response
// });

module.exports = router;