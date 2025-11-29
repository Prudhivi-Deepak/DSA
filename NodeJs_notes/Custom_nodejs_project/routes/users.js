
const express = require('express'); //exports a function
const router = express.Router();

router.use('/home', (req, res, next)=>{
    console.log("In the another middleware!");
    res.send("Response from send");//utility function to send response
});

module.exports = router;