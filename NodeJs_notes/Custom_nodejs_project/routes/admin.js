const express = require('express'); //exports a function
const router = express.Router();

router.use('/add-user',(req, res, next)=>{
    console.log("In the add-user middleware!");
    // res.send("Add user response from send");//utility function to send response
    res.send(`<form action="/store-user" method="POST">
                <input type="text" name="username" placeholder="Enter username">
                <button type="submit">Submit</button>
              </form>`);
});

// app.use('/store-user',(req, res, next)=>{
router.post('/store-user',(req, res, next)=>{
    console.log("In the store-user middleware!");
    console.log("Req method : ", req.method);
    console.log("Req url : ", req.url);
    console.log(req.body);
    res.redirect('/home'); //sets status code 302 and Location header
});

module.exports = router;