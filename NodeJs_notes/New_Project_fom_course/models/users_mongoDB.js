const mongodb = require('mongodb');
const getDb = require('../util/database').getDb

class User {
    constructor(name, email, cart, id) {
        this.name = name;
        this.email = email;
        this.cart = cart; //{items: []}
        this._id = id;
    }

    save() {
        const db = getDb();
        return db.collection('users').insertOne(this);

    }

    addToCart(product) {
        // get the products in cart with same product here using id
        const cartProductIndex = this.cart.items.findIndex(cartproduct => {
            return cartproduct.productId.toString() === product._id.toString();
        })
        const updatedCartItems = [...this.cart.items];

        let newQuantity = 1;
        if (cartProductIndex >= 0) {
            newQuantity = this.cart.items[cartProductIndex].quantity + 1;
            updatedCartItems[cartProductIndex].quantity = newQuantity;
        }
        else {
            updatedCartItems.push({ productId: new mongodb.ObjectId(product._id), quantity: newQuantity })
        }


        // const updatedCart = {items: {...product, quantity: 1}};
        // const updatedCart = {items: [{productId : new mongodb.ObjectId(product._id), quantity: 1}]};
        const updatedCart = { items: updatedCartItems };

        const db = getDb();
        return db.collection('users').updateOne(
            { _id: new mongodb.ObjectId(this._id) },
            { $set: { cart: updatedCart } }
        )

    }

    static findByPk(userId) {
        const db = getDb();
        // return db.collection('users').find({_id: new mongo.ObjectId(userId)}).next().then().catch();
        return db.collection('users').findOne({ _id: new mongodb.ObjectId(userId) });
    }

    getCart() {
        // return this.cart;// it is better to return all products in teh cart and not just the cart object
        const db = getDb();
        const productIds = this.cart.items.map(item => {
            return item.productId
        });

        return db.collection('products').find({ _id: { $in: productIds } }).toArray().then(products => {
            return products.map(product => {
                return { ...product, quantity: this.cart.items.find(item => { return item.productId.toString() === product._id.toString(); }).quantity }
            })
        }).catch(err => console.log(err));

    }

    deleteItemFromCart(productId) {
        const updatedCartItems = this.cart.items.filter(item => {
            return item.productId.toString() !== productId.toString();
        });
        const db = getDb();
        return db.collection('users').updateOne(
            { _id: new mongodb.ObjectId(this._id) },
            { $set: { cart: { items: updatedCartItems } } }
        );

    }

    addOrder() {
        const db = getDb();
        return this.getCart().then(products => {
            const order = {
                items: products,
                user: {
                    _id: new mongodb.ObjectId(this._id),
                    name: this.name
                }
            };

            return db.collection('orders').insertOne(order)
        })
        .then(result => {
            this.cart = { items: [] };
            return db.collection('users').updateOne(
                { _id: new mongodb.ObjectId(this._id) },
                { $set: { cart: { items: [] } } }
            );
        });

    }

    getOrders(){
        const db = getDb();
        return db.collection('orders').find({'user._id' :new mongodb.ObjectId(this._id)}).toArray()
        // .then(orders=>{
        //     console.log("orders : ", orders);
        // });
    }
}

module.exports = User;