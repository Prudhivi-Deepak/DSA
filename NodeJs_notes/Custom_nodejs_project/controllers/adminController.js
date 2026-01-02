
const User = require('../models/userModel');

exports.getAddUser = (req, res, next) => {
    console.log("In the add-user middleware!");
    // res.send("Add user response from send");//utility function to send response
    // res.send(`<form action="/store-user" method="POST">
    // res.send(`<form action="/admin/add-user" method="POST">
    //             <input type="text" name="username" placeholder="Enter username">
    //             <button type="submit">Submit</button>
    //           </form>`);

    // res.sendFile(path.join(__dirname, '..', 'views', 'add-user.html'));
    // res.sendFile(path.join(rootDir, 'views', 'add-user.html'));
    res.render('admin/add-user', {
        docTitle: 'Add User Page', path: 'adminpath',
        UsersCss: true, FormsCss: true, activeAddUser: true,
    });
}

exports.postAddUser = (req, res, next) => {
    // console.log("In the store-user middleware!");
    // console.log("Req method : ", req.method);
    // console.log("Req url : ", req.url);
    // console.log(req.body);
    // users.push({title: req.body.title});
    const title = req.body.title;
    const imageUrl = req.body.imageUrl;
    const description = req.body.description;
    const price = req.body.price;
    const user = new User(title, imageUrl, description, price);
    user.save();
    res.redirect('/home'); //sets status code 302 and Location header
}

exports.getUsers = (req, res, next) => {
    User.fetchAll((users) => {
        // users will be available here
        res.render('admin/users', {
            users: users, docTitle: 'Admin Products', path: '/admin/users'
        });
    });

}