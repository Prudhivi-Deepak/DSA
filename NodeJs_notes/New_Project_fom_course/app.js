const path = require('path');

const express = require('express');
const bodyParser = require('body-parser');
const session = require('express-session');
const MongoDBStore = require('connect-mongodb-session')(session);

const csrf = require('csurf');
const flash = require('connect-flash');
const multer = require('multer');

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

const MONGODB_URI = "mongodb://localhost:27017/mongooseTest";

const app = express();

app.set('view engine', 'ejs');
app.set('views', 'views');

const store = new MongoDBStore({
    uri: MONGODB_URI,
    collection: 'sessions',

});

const csrfProtection = csrf();

const adminRoutes = require('./routes/admin');
const shopRoutes = require('./routes/shop');
const authRoutes = require('./routes/auth');

app.use(bodyParser.urlencoded({ extended: false }));
const fileStorage = multer.diskStorage({
    destination: (req, file, cb)=>{
        cb(null, 'images'); //--> null says multer to okay to store it
    },
    filename: (req, file, cb)=>{
        // cb(null, file.filename+'-'+file.originalname);
        // cb(null, new Date().toISOString()+'-'+file.originalname);
        cb(null, Date.now()+'-'+file.originalname);
    }
}); 

const fileFilter = (req, file, cb)=>{
    if(file.mimetype === 'image/png' || file.mimetype === 'image/jpg'  || file.mimetype === 'image/jpeg'){
        console.log("filter : ", file.mimetype);
        cb(null, true); //--> to store the file
    }
    else{
        cb(null, false); //--> to not store the file
    }
};


app.use(multer({storage: fileStorage, fileFilter: fileFilter}).single('image'));
// app.use(multer().single('image'));
app.use(express.static(path.join(__dirname, 'public')));
app.use('/images', express.static(path.join(__dirname, 'images')));

app.use(session({
    secret: 'secret-in-app',
    resave: false,
    saveUninitialized: false,
    store: store
}));

app.use(csrfProtection);
app.use(flash());

// middle ware for incoming requests that's it
app.use((req, res, next) => {

    if (!req.session.userId) {
        next();
        return;
    }

    User.findById(req.session.userId).then(user => {
        // User.findById("6967a06ca54808445526127e").then(user => {
        if (!user) {
            return next();
        }
        console.log("user in app : ", user);
        req.user = user; //we are storing the sequelize/User class object
        // req.session.isLoggedIn = true;
        // req.session.user = user; //we are storing the sequelize/User class object
        // req.user = new User(user.name, user.email, user.cart, user._id); 
        next();
    }).catch(err => {
        // console.log(err);
        // next();
        throw new Error(err);

    });
});

app.use((req, res, next) => {
    // locals --> because used in only the views we renderend
    res.locals.isAuthenticated = req.session.isLoggedIn;
    res.locals.csrfToken = req.csrfToken();
    next();
});

app.use('/admin', adminRoutes);
app.use(shopRoutes);
app.use(authRoutes);

app.use(errorController.get404);

mongoose.connect(MONGODB_URI).then(result => {
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