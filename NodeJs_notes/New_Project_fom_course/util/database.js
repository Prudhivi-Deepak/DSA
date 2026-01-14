const mongoDB = require('mongodb');
const MongoClient = mongoDB.MongoClient;

let _db;

const mongoConnect= (callback) =>{
    MongoClient.connect(
        // "mongodb+srv://mongoDBUser:fXlPOiyRbmFQtiQc@cluster0.xzodcmu.mongodb.net/?appName=Cluster0"
        "mongodb://localhost:27017/"
    ).then(client=>{
        console.log("connected : ");
            // client);
        _db = client.db();
        callback(client);
    }).catch(err=>console.log(err));
};

const getDb = ()=>{
    if(_db){
        return _db;
    }
    throw "No DB found";
}


// module.exports = mongoConnect;
exports.mongoConnect = mongoConnect;
exports.getDb = getDb;


// const { MongoClient, ServerApiVersion } = require('mongodb');
// const uri = "mongodb+srv://mongoDBUser:fXlPOiyRbmFQtiQc@cluster0.xzodcmu.mongodb.net/?appName=Cluster0";
// // Create a MongoClient with a MongoClientOptions object to set the Stable API version
// const client = new MongoClient(uri, {
//   serverApi: {
//     version: ServerApiVersion.v1,
//     strict: true,
//     deprecationErrors: true,
//   }
// });
// async function run() {
//   try {
//     // Connect the client to the server	(optional starting in v4.7)
//     await client.connect();
//     // Send a ping to confirm a successful connection
//     await client.db("admin").command({ ping: 1 });
//     console.log("Pinged your deployment. You successfully connected to MongoDB!");
//   } finally {
//     // Ensures that the client will close when you finish/error
//     await client.close();
//   }
// }
// run().catch(console.dir);