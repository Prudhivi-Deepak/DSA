// const http = require('http');
// const fs = require('fs');
const route = require('./routes'); 
const bodyParser = require('body-parser');
const express = require('express'); //exports a function
const path = require('path');

// const adminRouter = require('./routes/admin');
const adminData = require('./routes/admin');
const usersRouter = require('./routes/users');

const app = express(); //app is a valid request handler

app.set('view engine', 'pug');
app.set('views', 'views'); //default value, can be skipped

app.use(bodyParser.urlencoded({ extended: false })); //parsing url encoded data
app.use(express.static(path.join(__dirname, 'public')));

console.log("Route.someText ::  ", route.someText);

// app.use('/admin',adminRouter);
app.use('/admin',adminData.routes);
app.use(usersRouter);

// error - 404 page when user enters invalid url
// request search from top to bottom, so if req comes here that means no valid route found
app.use((req, res, next)=>{
    // res.status(404).send('<h1>Page Not Found</h1>');
    // res.status(404).sendFile(path.join(__dirname, 'views', 'error404-page.html'));
    res.render('error404-page', {docTitle: 'Page Not Found'});
});

// const server = http.createServer(route.handler);
// create sever object using http (createServer() method) 
    // createServer take IncomingResponse and sends back Reponse
    // IncomingRequest - request from client to server
    // Response - response from server to client
    // we are using arrow functions here

// app.use([path,] middlewareFunction/callback...)
// app.use('/', (req, res, next)=>{
//     console.log("In the middleware!");
//     next(); //to move to the next middleware in line
// });

// app.use('/',(req, res, next)=>{
//     console.log("In the first middleware!");
//     next(); //to move to the next middleware in line
// });
// ---------------------------------------------------------------
// const server = http.createServer(app);//pass app to server
// server.listen(3000)
app.listen(3000); //shortcut to create server and listen on port 3000
// ---------------------------------------------------------------


