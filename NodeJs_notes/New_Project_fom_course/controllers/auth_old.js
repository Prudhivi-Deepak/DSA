
const User = require('../models/users')

exports.getLogin = (req, res, next) => {
    // const isLoggedIn = req.get('Cookie').split("=")[1] === 'true';
    // console.log(isLoggedIn);
    console.log(req.session);
    console.log(req.session.isLoggedIn);
    const isLoggedIn = req.session.isLoggedIn;
    res.render('auth/login', {
        path: '/login',
        pageTitle: 'Login',
        // isAuthenticated: false
        isAuthenticated: isLoggedIn
    });
};

exports.postLogin = (req, res, next) => {
    // req.isLoggedIn = true; // setting this before the response doesn't have any use
    // res.setHeader('Set-Cookie', 'loggedIn=true')

    User.findById("6967a06ca54808445526127e")
    .then(user=>{
        console.log("user : ", user);
        req.session.isLoggedIn = true;
        req.session.userId = user._id.toString();
        req.session.save((err)=>{
            console.log(err);
            res.redirect('/'); // this si a brand new request, so the above info is already lost
        }); // --> to make sure save first then redirect
    }).catch(err=>console.log(err));
};

exports.postLogOut = (req, res, next) => {
    // req.isLoggedIn = true; // setting this before the response doesn't have any use
    // res.setHeader('Set-Cookie', 'loggedIn=true')
    req.session.destroy(() => {
        res.redirect('/'); // this si a brand new request, so the above info is already lost
    });
};