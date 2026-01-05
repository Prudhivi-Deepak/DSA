const fs = require('fs');
const path = require('path');

const rootDir = require('../util/path');

const p = path.join(rootDir, 'data', 'cart.json');
module.exports = class Cart {

    // constructor() {
    //     this.products = [];
    //     this.totalPrice = 0;
    // }

    static addProduct(id, productPrice) {
        // Fetch the previous cart
        fs.readFile(p, (err, fileContent) => {
            let cart = {products: [], totalPrice: 0};
            if (!err) {
                cart = JSON.parse(fileContent);
            }
            // else {

            // }

            const existingProduct = cart.products.find(prod => prod.id === id);
            if (existingProduct) {
                existingProduct.qty += 1;
                cart.products = cart.products.map(prod => {
                    if (prod.id === id) {
                        return existingProduct;
                    }
                    return prod;
                });
            } else {
                cart.products.push({id: id, qty: 1});
            }
            cart.totalPrice += +productPrice;

            fs.writeFile(p, JSON.stringify(cart), err => {
                console.log(err);
            });
        });
        // Analyze the cart => Find existing product
        // Add new product / increase quantity
    }

    static deleteProduct(id, productPrice){
        fs.readFile(p, (err, fileContent)=>{
            if(!err){
                let cart = JSON.parse(fileContent);
                console.log(id);
                const updatedCartProducts = cart.products.filter(cartItem => cartItem.id !== id);

                console.log("updatedCartProducts : ",updatedCartProducts);

                const deletingProduct = cart.products.filter(cartItem => cartItem.id === id);

                if(!deletingProduct) return;

                const updatedTotalPrice = cart.totalPrice - (deletingProduct[0].qty)*(productPrice);

                cart.products = updatedCartProducts;
                cart.totalPrice = updatedTotalPrice;

                fs.writeFile(p, JSON.stringify(cart), (err)=>{
                    console.log(err);
                })
            }
        })
    }

    static getCart(cb){
        fs.readFile(p, (err, fileContent)=>{
            const cart = JSON.parse(fileContent);
            if(err){
                cb(null);
            }
            else{
                cb(cart);
            }
        })
    }
}