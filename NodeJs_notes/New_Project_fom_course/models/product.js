const fs = require('fs');
const path = require('path');
// https://tinyurl.com/4knpbcns
const Cart = require('./cart')

const p = path.join(
  path.dirname(process.mainModule.filename),
  'data',
  'products.json'
);

const getProductsFromFile = cb => {
  fs.readFile(p, (err, fileContent) => {
    if (err) {
      cb([]);
    } else {
      cb(JSON.parse(fileContent));
    }
  });
};

module.exports = class Product {
  constructor(id, title, imageUrl, description, price) {
    this.id = id;
    this.title = title;
    this.imageUrl = imageUrl;
    this.description = description;
    this.price = price;
  }

  save() {
    getProductsFromFile(products => {

      if (this.id) {
        const existingProductIndex = products.findIndex(prod => prod.id === this.id);
        const updatedProducts = [...products];
        updatedProducts[existingProductIndex] = this;
        fs.writeFile(p, JSON.stringify(updatedProducts), err => {
          console.log(err);
        });
      }
      else {

        this.id = Math.random().toString();
        products.push(this);
        fs.writeFile(p, JSON.stringify(products), err => {
          console.log(err);
        });
      }
    });
  }

  static deleteById(productId){
    getProductsFromFile(products => {
      // const product = products.find(p => p.id === id);
      // const productIndextobeDeleted = products.findIndex(p => p.id === productId);
      const updatedProducts = products.filter(p => p.id !== productId);
      const deletingProduct = products.filter(p => p.id === productId);
      console.log("deletingProduct : ", deletingProduct);
      fs.writeFile(p, JSON.stringify(updatedProducts), err=>{
        if(!err){
          // we delete the items from cart if it's present there
          
          Cart.deleteProduct(productId, deletingProduct[0].price);
        }
      });
    });
  }

  static fetchAll(cb) {
    getProductsFromFile(cb);
  }

  static findById(id, cb) {
    getProductsFromFile(products => {
      const product = products.find(p => p.id === id);
      cb(product);
    });
  }
};
