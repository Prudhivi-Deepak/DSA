// const users = [];
const User = require('../models/userModel');

exports.getUsers = (req, res, next) => {
    // res.sendFile(path.join(__dirname, '..', 'views', 'users.html'));
    // console.log("Users.js :: Admin Data Users :: ", adminData.users);
    // res.sendFile(path.join(rootDir, 'views', 'users.html'));
    // const  allUsers = adminData.users;

    // we send a function to fetchAll which will be called with data when data is ready
    const users = User.fetchAll((users) => {
        // users will be available here
        res.render('shop/users', {
            users: users, docTitle: 'All Users', path: '/users'
            // layout: false
        });
    });
}

exports.getIndex = (req, res, next) => {
    User.fetchAll((users) => {
        // users will be available here
        res.render('shop/index', {
            users: users, docTitle: 'Shop', path: '/home', 
            // hasUsers: users.length > 0,
            // activeShop: true, UsersCss: true,
            // layout: false
        });
    });
}

exports.getCart = (req, res, next) => {
    res.render('shop/cart', {
        docTitle: 'Your Cart', path: '/cart',
        // layout: false
    });
}

exports.getOrders = (req, res, next) => {
    res.render('shop/orders', {
        docTitle: 'Your Orders', path: '/orders',
        // layout: false
    });
}

exports.checkout = (req, res, next) => {
    res.render('shop/checkout', {
        docTitle: 'Checkout', path: '/checkout',
        // layout: false
    });
}