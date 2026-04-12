const jwt = require('jsonwebtoken');

module.exports = (req, res, next)=>{
    const authHeader =  req.get('Authorization');
    if(!authHeader){
        // const error = new Error("no Authorization key");
        // error.statusCode = 401;
        // throw error;
        req.isAuth = false;
        return next
    }


    const token =  req.get('Authorization').split(' ')[1];
    let decodedToken;
    try{
        decodedToken = jwt.verify(token, 'superLongStringSecret');
    }
    catch(err){
        err.statusCode = 500;
        throw err;
    }

    if(!decodedToken){
        const error = new Error("not Authenticated");
        error.statusCode = 401;
        throw error;
    }

    req.userId = decodedToken.userId;
    next();
}