const http = require('http');
const fs = require('fs');
const route = require('./routes');

// create sever object using http (createServer() method) 
    // createServer take IncomingResponse and sends back Reponse
    // IncomingRequest - request from client to server
    // Response - response from server to client
    // we are using arrow functions here
console.log("Route.someText ::  ", route.someText);
const server = http.createServer(route.handler);

server.listen(3000)
