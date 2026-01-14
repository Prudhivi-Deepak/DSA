const mongodb = require('mongodb');
const getDb = require('../util/database').getDb

class Product {
    constructor(title, price, description, imageUrl, id, userId) {
        this.title = title;
        this.price = price;
        this.description = description;
        this.imageUrl = imageUrl;
        this._id = id ? new mongodb.ObjectId(id) : null;
        this.userId = userId;
    }

    save(){
        const db = getDb();
        let dbOps;
        if(this._id){
            dbOps = db.collection('products').updateOne({_id: new mongodb.ObjectId(this._id)},{ $set: this});
        }
        else{
            dbOps = db.collection('products').insertOne(this);
        }
        // db.collection('products').insertMany
        return dbOps
        .then(result=>{
            console.log(result); 
        }).catch(err=>console.log(err));
    }

    static fetchAll(){
        // return db.collection('products').find({title: 'flash'});
        const db = getDb();
        return db.collection('products').find().toArray().then(products=>{
            console.log(products);
            return products;
        }).catch(err=>console.log(err));
    }

    static findByPk(productId){
        const db = getDb();
        return db.collection('products').find({_id : new mongodb.ObjectId(productId)}).next().then(product=>{
            console.log(product);
            return product;
        }).catch() 
    }

    static deleteById(productId){
        const db = getDb();
        return db.collection('products').deleteOne({_id : new mongodb.ObjectId(productId)}).then(product=>{
            console.log("Deleted");
        }).catch(err=>console.log(err)) ;
    }
}

module.exports = Product;