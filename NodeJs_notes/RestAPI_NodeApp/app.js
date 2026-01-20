const express = require('express');
const feedRoutes = require('./routes/feed');
const authRoutes = require('./routes/auth');
const bodyParser = require('body-parser');
const mongoose = require('mongoose');
const path = require('path');
const { error } = require('console');
const { v4: uuidv4 } = require('uuid');
const multer = require('multer');

const app = express();
// app.use(bodyParser.urlencoded()); //x-www-form-urlencoded <form> --> json format parser

app.use(bodyParser.json()); //application/json --> json format parser
app.use('/images', express.static(path.join(__dirname, 'images')))

const fileStorage = multer.diskStorage({
    destination: function (req, file, cb) {
        cb(null, 'images');
    },
    filename: function (req, file, cb) {
        cb(null, uuidv4())
    }
});

const fileFilter = (req, file, cb) => {
    if (file.mimetype === 'image/png' || file.mimetype === 'image/jpg' || file.mimetype === 'image/jpeg') {
        console.log("filter : ", file.mimetype);
        cb(null, true); //--> to store the file
    }
    else {
        cb(null, false); //--> to not store the file
    }
};


app.use(multer({ storage: fileStorage, fileFilter: fileFilter }).single('image'));

const MONGODB_URI = "mongodb://localhost:27017/RestAPI";

app.use((req, res, next) => {
    res.setHeader('Access-Control-Allow-Origin', '*'); //--> allow any client to access the server response (*) instead we can set to specific Domain
    res.setHeader('Access-Control-Allow-Methods', 'GET, POST, PUT, PATCH, DELETE'); //--> we also need to tell which methods to be used for origins
    res.setHeader('Access-Control-Allow-Headers', 'Content-Type, Authorization'); //--> allow the headers that our client might set on their request, we can mention * as well
    next();
});

app.use('/feed', feedRoutes);
app.use('/auth', authRoutes);

app.use((error, req, res, next) => {
    console.log(error);
    const statusCode = error.statusCode || 500;
    const message = error.message;
    const data = error.data;
    res.status(statusCode).json({ message: message, data: data });
})

mongoose.connect(MONGODB_URI).then(result => {
    // const user = new User({
    //     name: 'Will',
    //     email: 'st@will.com',
    //     cart: {
    //         items:[]
    //     }
    // })
    // user.save();
    // app.listen(8080);
    const server = app.listen(8080) //--> this returns the node server app
    // const io = require('socket.io')(server, {
    const io = require('./socket').init(server, {
        cors: {
            origin: "http://localhost:3000",
            methods: ["GET", "POST"]
        }
    }) //--> pass server as arugment as websockets us build on http

    io.on('connection', socket => {
        console.log("client connected", socket.id);
    });
});

// app.listen(8080);