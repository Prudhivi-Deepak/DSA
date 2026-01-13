const path = require('path');

const express = require('express');
const bodyParser = require('body-parser');

const errorController = require('./controllers/error');

// const db = require('./util/database')
const Sequelize = require('./util/database')
const Product = require('./models/product');
const User = require('./models/users')
const Cart = require('./models/cart')
const CartItem = require('./models/cartItem')
const Order = require('./models/order')
const OrderItem = require('./models/orderItem')

const app = express();

app.set('view engine', 'ejs');
app.set('views', 'views');

// middle ware for incoming requests that's it
app.use((req, res, next)=>{
    User.findByPk(1).then(user => {
        req.user = user; //we are storing the sequelize object
        next();
    }).catch(err=>console.log(err));
});

const adminRoutes = require('./routes/admin');
const shopRoutes = require('./routes/shop');

// execute the SQL cmd
// db.execute('SELECT * From products')
// then-> get the anonymous function to execute
// .then((result)=>{
//     console.log(result[0], result[1]);
// })
 // in case of any error
// .catch((err)=>{
//         console.log(err)
// }); 

app.use(bodyParser.urlencoded({ extended: false }));
app.use(express.static(path.join(__dirname, 'public')));

app.use('/admin', adminRoutes);
app.use(shopRoutes);

app.use(errorController.get404);


Product.belongsTo(User, {constraints: true, onDelete: 'CASCADE'});
User.hasMany(Product); //optional
User.hasOne(Cart);
Cart.belongsTo(User);//optional
Cart.belongsToMany(Product, {through: CartItem});
Product.belongsToMany(Cart, {through: CartItem});
Order.belongsTo(User);
User.hasMany(Order);
Order.belongsToMany(Product, {through: OrderItem});


Sequelize.sync(
    // {force: true}
).
then(result => {
    return User.findByPk(1);
})
.then(user=>{
    if(!user){ 
       return  User.create({name:'will', email:'st@will.com'});
    }
    // return Promise.resolve(user);
    // technically we don't need Promise because if we use then block, it automatically wraps it under promise
    return user;
})
// .then(user=>{
//     return user.createCart();
// })
.then(result => {
    console.log(result);
    app.listen(3000);
})
.catch(err=>console.log(err))

// app.listen(3000);
