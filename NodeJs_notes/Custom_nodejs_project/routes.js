const fs = require('fs');

const routeHandler = (req, res) => {
    // console.log("Request received : " + req);
    // console.log(req.url, req.method, req.headers);

    const url = req.url;
    const method = req.method;

    if(url === '/'){
        res.setHeader('Content-Type', 'text/html');
        res.write('<html>');
        res.write('<head><title>Home Page</title></head>');
        res.write('<body>');
        res.write('<form action="/submit" method="POST">');
        res.write('<input type="text" name="username" placeholder="Enter username">');
        res.write('<button type="submit">Submit</button>');
        res.write('</form>');
        res.write('</body>');
        res.write('</html>');
        return res.end();
    }

    if(url === '/submit' && method === 'POST') {
        const body = [];
        req.on('data', (chunk)=>{
            body.push(chunk);
            console.log("chunk : ", chunk);
        });

        return req.on('end', ()=>{
            const response = Buffer.concat(body).toString();
            console.log("end : ",response);
            // fs.writeFileSync('./user_data.txt', response.split("=")[1]);
            fs.writeFile('/user', response.split("=")[1], ()=>{
                console.log("File written successfully");
                res.statusCode = 302; // redirect status code
                res.setHeader('Location', '/');
                return res.end();
            })
            // console.log("After file write");
            // res.statusCode = 302; // redirect status code
            // res.setHeader('Location', '/');
            // return res.end();
        });
        // res.statusCode = 302; // redirect status code
        // res.setHeader('Location', '/');
        // return res.end();
    }
        

    res.setHeader('Content-Type', 'text/html');
    res.write('<html>');
    res.write('<head><title>My First Page</title></head>');
    res.write('<h1>Welcome to Vessio</h1>');
    res.write('</html>');
    res.end();
}

// module.exports = routeHandler;

// module.exports = {
//     routeHandler: routeHandler
// }

// module.exports.handler = routeHandler;
// module.exports.someText = "This is some text";

exports.handler = routeHandler;
exports.someText = "This is some text";

