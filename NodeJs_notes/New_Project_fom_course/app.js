const path = require('path');

const express = require('express');
const bodyParser = require('body-parser');

const errorController = require('./controllers/error');

// const mongoConnect = require('./util/database');
const mongoose = require('mongoose');

const User = require('./models/users')

// const db = require('./util/database')
// const Sequelize = require('./util/database')
// const Product = require('./models/product');
// const User = require('./models/users')
// const Cart = require('./models/cart')
// const CartItem = require('./models/cartItem')
// const Order = require('./models/order')
// const OrderItem = require('./models/orderItem')

const app = express();

app.set('view engine', 'ejs');
app.set('views', 'views');

// middle ware for incoming requests that's it
app.use((req, res, next)=>{
    User.findById("6967a06ca54808445526127e").then(user => {
        req.user = user; //we are storing the sequelize/User class object
        // req.user = new User(user.name, user.email, user.cart, user._id); 
        next();
    }).catch(err=>console.log(err));
});

const adminRoutes = require('./routes/admin');
const shopRoutes = require('./routes/shop');

app.use(bodyParser.urlencoded({ extended: false }));
app.use(express.static(path.join(__dirname, 'public')));

app.use('/admin', adminRoutes);
app.use(shopRoutes);

app.use(errorController.get404);

mongoose.connect("mongodb://localhost:27017/mongooseTest").then(result=>{
    // const user = new User({
    //     name: 'Will',
    //     email: 'st@will.com',
    //     cart: {
    //         items:[]
    //     }
    // })
    // user.save();
    app.listen(3000);
});

// mongoConnect.mongoConnect(()=>{
//     // console.log(client);

//     app.listen(3000);
// });