
const path = require('path');
const express = require('express'); //exports a function
const router = express.Router();

const rootDir = require('../util/path');
const adminData = require('./admin');

router.use('/home', (req, res, next)=>{
    // res.sendFile(path.join(__dirname, '..', 'views', 'users.html'));
    // console.log("Users.js :: Admin Data Users :: ", adminData.users);
    // res.sendFile(path.join(rootDir, 'views', 'users.html'));
    const  allUsers = adminData.users;
    res.render('users', {users: allUsers, docTitle: 'Shop', path:'/home', hasUsers: allUsers.length > 0,
        activeShop: true, UsersCss: true,
        // layout: false
    });
});

// router.use('/home', (req, res, next)=>{
//     console.log("In the another middleware!");
//     res.send("Response from send");//utility function to send response
// });

module.exports = router;