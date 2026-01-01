const path = require('path');
const express = require('express'); //exports a function
const router = express.Router();

const rootDir = require('../util/path');

const users = [];

// router.use('/admin/add-user',(req, res, next)=>{
// router.get('/admin/add-user',(req, res, next)=>{
router.get('/add-user',(req, res, next)=>{
    console.log("In the add-user middleware!");
    // res.send("Add user response from send");//utility function to send response
    // res.send(`<form action="/store-user" method="POST">
    // res.send(`<form action="/admin/add-user" method="POST">
    //             <input type="text" name="username" placeholder="Enter username">
    //             <button type="submit">Submit</button>
    //           </form>`);

    // res.sendFile(path.join(__dirname, '..', 'views', 'add-user.html'));
    // res.sendFile(path.join(rootDir, 'views', 'add-user.html'));
    res.render('add-user', {docTitle: 'Add User Page', path: 'adminpath',
        UsersCss: true, FormsCss: true, activeAddUser: true,
    });
});

// app.use('/store-user',(req, res, next)=>{
// router.post('/admin/store-user',(req, res, next)=>{
// router.post('/admin/add-user',(req, res, next)=>{
router.post('/add-user',(req, res, next)=>{
    console.log("In the store-user middleware!");
    console.log("Req method : ", req.method);
    console.log("Req url : ", req.url);
    console.log(req.body);
    users.push({title: req.body.title});
    res.redirect('/home'); //sets status code 302 and Location header
});

// module.exports = router;
exports.routes = router;
exports.users = users;