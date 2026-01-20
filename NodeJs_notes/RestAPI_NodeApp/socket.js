let io;

module.exports = {
    init: (httpServer, configure) => {
        io = require('socket.io')(httpServer, configure);
        return io;
    },
    getIo: ()=>{
        if(!io){
            throw new Error("Socket Io not initialized");
        }
        return io;
    }
};