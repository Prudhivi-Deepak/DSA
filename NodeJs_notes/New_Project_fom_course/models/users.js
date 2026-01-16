const mongoose = require('mongoose');
const schema = mongoose.Schema;
const userSchema = new schema({
    name: {
        type: String,
        required: false
    },
    email: {
        type: String,
        required: true
    },
    password: {
        type: String,
        required: true
    },
    resetToken: String,
    resetTokenExpiration: Date,
    cart: {
        items: [
            {
                productId: { type: schema.Types.ObjectId, ref: 'product', required: true },
                quantity: { type: Number, required: true }
            }
        ]
    },
});

userSchema.methods.addToCart = function (product) {
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
        // updatedCartItems.push({ productId: new mongodb.ObjectId(product._id), quantity: newQuantity })
        updatedCartItems.push({ productId: product._id, quantity: newQuantity })
        // mongoose able to detect the id and convert to objectID
    }


    // const updatedCart = {items: {...product, quantity: 1}};
    // const updatedCart = {items: [{productId : new mongodb.ObjectId(product._id), quantity: 1}]};
    const updatedCart = { items: updatedCartItems };

    // const db = getDb();
    // return db.collection('users').updateOne(
    //     { _id: new mongodb.ObjectId(this._id) },
    //     { $set: { cart: updatedCart } }
    // )
    this.cart = updatedCart;
    return this.save();
}

userSchema.methods.deleteItemFromCart = function (productId) {
    const updatedCartItems = this.cart.items.filter(item => {
        console.log(item.productId.toString(),  productId.toString());
        return item.productId.toString() !== productId.toString();
    });
    console.log("updatedCartItems : ",updatedCartItems);

    this.cart.items = updatedCartItems;
    return this.save();
    // const db = getDb();
    // return db.collection('users').updateOne(
    //     { _id: new mongodb.ObjectId(this._id) },
    //     { $set: { cart: { items: updatedCartItems } } }
    // );
}

userSchema.methods.clearCart = function(){
    this.cart = {items:[]};
    return this.save();
}

// userSchema.methods.getCart = function () {
// const db = getDb();
// const productIds = this.cart.items.map(item => {
//     return item.productId
// });

// return db.collection('products').find({ _id: { $in: productIds } }).toArray().then(products => {
//     return products.map(product => {
//         return { ...product, quantity: this.cart.items.find(item => { return item.productId.toString() === product._id.toString(); }).quantity }
//     })
// }).catch(err => console.log(err));
// return this.cart;
// }

module.exports = mongoose.model('User', userSchema);