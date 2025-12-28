
const path = require('path');
const express = require('express'); //exports a function
const router = express.Router();

const rootDir = require('../util/path');

router.use('/home', (req, res, next)=>{
    // res.sendFile(path.join(__dirname, '..', 'views', 'users.html'));
    res.sendFile(path.join(rootDir, 'views', 'users.html'));
});

// router.use('/home', (req, res, next)=>{
//     console.log("In the another middleware!");
//     res.send("Response from send");//utility function to send response
// });

module.exports = router;