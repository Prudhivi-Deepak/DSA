// const http = require('http');
// const fs = require('fs');
const route = require('./routes'); 
const bodyParser = require('body-parser');
const express = require('express'); //exports a function

const adminRouter = require('./routes/admin');
const usersRouter = require('./routes/users');

const app = express(); //app is a valid request handler
app.use(bodyParser.urlencoded({ extended: false })); //parsing url encoded data

console.log("Route.someText ::  ", route.someText);

app.use(adminRouter);
app.use(usersRouter);

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


