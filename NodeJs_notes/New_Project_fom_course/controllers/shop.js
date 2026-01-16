// const Cart = require('../models/cart');
const Product = require('../models/product');
const Order = require('../models/order');
const order = require('../models/order');

exports.getProducts = (req, res, next) => {
  console.log(req.session.isLoggedIn);
  // Product.findAll().
  Product.find()
    .then(products => {
      console.log(products);
      res.render('shop/product-list', {
        prods: products,
        pageTitle: 'All Products',
        path: '/products',
        isAuthenticated: req.session.isLoggedIn
      });
    }).catch(err => {
      console.log(err);
    });
  // Product.fetchAll().then(([rows, fieldsData])=>{
  //   res.render('shop/product-list', {
  //     prods: rows,
  //     pageTitle: 'All Products',
  //     path: '/products'
  //   });
  // }).catch(err=>console.log(err))
};

exports.getProduct = (req, res, next) => {
  const productId = req.params.productId;
  console.log(productId)
  // Product.findById().then(([product, fieldsData])=>{

  // Product.findByPk(productId).then((product) => {
  Product.findById(productId).then((product) => {
    // Product.findAll({
    //   where: {
    //     id: productId
    //   }
    // }).then((product) => {
    // console.log(product.title)
    // console.log(product[0].title)
    res.render('shop/product-detail', {
      // product: product[0],
      product: product,
      pageTitle: product ? product.title : 'Product Not Found',
      // pageTitle: product[0] ? product[0].title : 'Product Not Found',
      path: '/products',
      isAuthenticated: req.session.isLoggedIn
    });
  }).catch(err => console.log(err));
};

exports.getIndex = (req, res, next) => {
  // Product.findAll()
  // const csrfToken = req.csrfToken();
  Product.find()
    .then(products => {
      console.log(products);
      res.render('shop/index', {
        prods: products,
        pageTitle: 'Shop',
        path: '/',
        // isAuthenticated: req.session.isLoggedIn,
        // csrfToken: csrfToken
      });
    }).catch(err => {
      console.log(err);
    });
  // Product.fetchAll().then(([rows, fieldsData])=>{
  //   res.render('shop/index', {   
  //     prods: rows,
  //     pageTitle: 'Shop',
  //     path: '/'
  //   });
  // }).catch(err=>console.log(err))
};

exports.getCart = (req, res, next) => {
  console.log("get cart : user : ", req.user);
  req.user
  // req.session.user
  .populate('cart.items.productId')
    // .execPopulate() --> not present in the latest library
    // getCart()
    .then(cartProducts => {
      console.log(cartProducts);
      const products = cartProducts.cart.items;
      res.render('shop/cart', {
        path: '/cart',
        pageTitle: 'Your Cart',
        products: products,
        isAuthenticated: req.session.isLoggedIn
      });
    }).catch(err => console.log(err));
};

// exports.getCart = (req, res, next) => {
//   // req.user.cart ==> undefined we can't use it as a attribute here
//   req.user.getCart().then(cart => {
//     console.log(cart);
//     return cart.getProducts();
//   })
//     .then(cartProducts => {
//       console.log(cartProducts);
//       res.render('shop/cart', {
//         path: '/cart',
//         pageTitle: 'Your Cart',
//         products: cartProducts
//       });
//     })
//     .catch(err => console.log(err));
//   // Cart.getCart((cart) => {
//   //   Product.fetchAll((AllProducts) => {
//   //     const cartProducts = [];
//   //     for (iterProduct of AllProducts) {
//   //       if (cartProductData = cart.products.find(product => product.id === iterProduct.id)) {
//   //         cartProducts.push({ productData: iterProduct, qty: cartProductData.qty });
//   //       }
//   //     }

//   //     res.render('shop/cart', {
//   //       path: '/cart',
//   //       pageTitle: 'Your Cart',
//   //       products: cartProducts
//   //     });
//   //   });
//   // })
// };


exports.postCart = (req, res, next) => {
  const productId = req.body.productId;
  // Product.findByPk(productId)
  Product.findById(productId)
    .then(product => {
      return req.user.addToCart(product);
    })
    .then(result => {
      console.log("postcart : result : ", result);
      res.redirect('/cart');
    })
    .catch(err => console.log(err));
}

exports.postCartDeleteProduct = (req, res, next) => {
  const productId = req.body.productId;
  console.log('Product ID to be deleted from cart:', productId);
  // req.user.deleteItemFromCart(productId)
  req.session.user.deleteItemFromCart(productId)
    // .then(cart=>{
    //   return cart.getProducts({where : { id : productId}});
    // })
    // .then(products=>{
    //   const product = products[0];
    //   // magic field
    //   return product.cartItem.destroy();
    // })
    .then(result => {
      res.redirect('/cart');
    })
    .catch(err => console.log(err));
  // Product.findById(productId, product => {
  //   // Cart.addProduct(productId, product.price);
  //   Cart.deleteProduct(productId, product.price);
  //   res.redirect('/cart');
  // });
};

// exports.postCart = (req, res, next) => {
//   const productId = req.body.productId;
//   let fetchedCart;
//   let newQuantity = 1;
//   console.log('Product ID to add to cart:', productId);
//   req.user.getCart().then(cart => {
//     fetchedCart = cart;
//     return cart.getProducts({ where: { id: productId } });
//   })
//     .then(products => {
//       let product;
//       if (products.length > 0) {
//         product = products[0];
//       }
//       if (product) {
//         const oldQuantity = product.cartItem.quantity;
//         newQuantity = oldQuantity + 1;
//         return product;
//         // return fetchedCart.addProduct(product, {
//         //   through: { quantity: newQuantity }
//         // })
//       }
//       return Product.findByPk(productId)
//       // .then(currProduct => {
//       //   return fetchedCart.addProduct(currProduct, {
//       //     through: { quantity: newQuantity }
//       //   })
//       // })
//         // .catch(err => console.log(err));
//     })
//     .then(product => {
//       return fetchedCart.addProduct(product, {
//         through: { quantity: newQuantity }
//       })
//     })
//     .then(() => {
//       res.redirect('/cart');
//     })
//     .catch(err => console.log(err));
//   // Product.findById(productId, product => {
//   //   Cart.addProduct(productId, product.price);
//   // });
//   // res.redirect('/cart');
// };

// exports.postCartDeleteProduct = (req, res, next) => {
//   const productId = req.body.productId;
//   console.log('Product ID to be deleted from cart:', productId);
//   req.user.getCart().then(cart=>{
//     return cart.getProducts({where : { id : productId}});
//   })
//   .then(products=>{
//     const product = products[0];
//     // magic field
//     return product.cartItem.destroy();
//   })
//   .then(result => {
//     res.redirect('/cart');
//   })
//   .catch(err=>console.log(err));
//   // Product.findById(productId, product => {
//   //   // Cart.addProduct(productId, product.price);
//   //   Cart.deleteProduct(productId, product.price);
//   //   res.redirect('/cart');
//   // });
// };

exports.postOrder = (req, res, next) => {
  req.user.populate('cart.items.productId')
    .then(cartProducts => {
      const products = cartProducts.cart.items.map(item=>{
        return {quantity: item.quantity, product: {...item.productId._doc}};
      });
      const order = new Order({
        user: {
          // name: req.user.name,
          email: req.user.email,
          userId: req.user
        },
        products: products
      })
      return order.save();
    })

  // req.user.addOrder()
    .then(result => {
      return req.user.clearCart();
    })
    .then(result=>{
      res.redirect('/orders');
    })
    .catch(err => console.log(err));
};

// exports.postOrder = (req, res, next) => {
//   let fetchedCart;
//   req.user.getCart().then(cart=>{
//     fetchedCart = cart;
//     return cart.getProducts();
//   })
//   .then(products => {
//     // console.log(products);
//     return req.user.createOrder().then(order => {
//       order.addProducts(
//         products.map(product=>{
//           // add products need quantity in orderItem, it searchs for it,
//           // so add it to the products then add it and return
//           product.orderItem = { quantity: product.cartItem.quantity};
//           return product;
//         })
//       );
//     }).catch(err=>console.log(err));
//   })
//   .then(result=>{
//     return fetchedCart.setProducts(null);
//   })
//   .then(result=>{
//     res.redirect('/orders');
//   })
//   .catch(err=>console.log(err));
// };

exports.getOrders = (req, res, next) => {

  Order.find({'user.userId': req.user._id})
  // req.user.getOrders()
    .then(orders => {
      console.log("orders : ", orders);
      console.log(orders[0]._id);
      console.log(orders[0].products)
      res.render('shop/orders', {
        path: '/orders',
        pageTitle: 'Your Orders',
        orders: orders,
        isAuthenticated: req.session.isLoggedIn
      });
    }).catch(err => console.log(err));
};

// exports.getOrders = (req, res, next) => {
//   req.user.getOrders({include: ['products']})
//   .then(orders=>{
//     // console.log(orders);
//     console.log(orders[0]);
//     console.log(orders[0].id);
//     console.log(orders[0].products[0].title);
//     console.log(orders[0].products[0].orderItem.quantity);
//     res.render('shop/orders', {
//       path: '/orders',
//       pageTitle: 'Your Orders',
//       orders: orders
//     });
//   }).catch(err=>console.log(err));

//   // res.render('shop/orders', {
//   //   path: '/orders',
//   //   pageTitle: 'Your Orders'
//   // });
// };

// exports.getCheckout = (req, res, next) => {
//   res.render('shop/checkout', {
//     path: '/checkout',
//     pageTitle: 'Checkout'
//   });
// };
