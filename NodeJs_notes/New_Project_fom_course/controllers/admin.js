const Product = require('../models/product');
const mongodb = require('mongodb');
const { validationResult } = require('express-validator');

exports.getAddProduct = (req, res, next) => {
  if (!req.session.isLoggedIn) {
    return res.redirect('/login');
  }

  // res.render('admin/add-product', /{
  res.render('admin/edit-product', {
    pageTitle: 'Add Product',
    path: '/admin/add-product',
    editing: false,
    hasError: false,
    errorMessage: null,
    isAuthenticated: req.session.isLoggedIn,
    validationErrors: []
    // formsCSS: true,
    // productCSS: true,
    // activeAddProduct: true
  });
};

exports.postAddProduct = (req, res, next) => {
  const title = req.body.title;
  const imageUrl = req.body.imageUrl;
  const price = req.body.price;
  const description = req.body.description;

  const errors = validationResult(req);
  if (!errors.isEmpty()) {
    console.log(errors.array());
    return res.status(422).render('admin/edit-product', {
      path: '/admin/edit-product',
      pageTitle: 'Add Product',
      editing: false,
      hasError: true,
      product: {
        title: title,
        price: price,
        description: description,
        imageUrl: imageUrl
      },
      errorMessage: errors.array()[0].msg,
      validationErrors: errors.array()
    })
  }


  // const product = new Product(null, title, imageUrl, description, price);
  // product.save()
  // product.save().then(()=>{
  //   res.redirect('/');
  // }).catch(err=>console.log(err));

  // Product.create({
  // req.user.createProduct({
  //   title: title,
  //   price: price,
  //   imageUrl: imageUrl,
  //   description: description,
  //   // user: req.user.id
  // })
  const product = new Product({ title: title, price: price, description: description, imageUrl: imageUrl, userId: req.user });
  product.save().then(result => {
    console.log(result);
    res.redirect('/admin/products');
  }).catch(err => {
    console.log(err);
  });
};

exports.getEditProduct = (req, res, next) => {
  // res.render('admin/add-product', /{
  const editMode = req.query.edit; //all the extracted values from the url are strings
  if (!editMode) {
    return res.redirect('/');
  }
  const productId = req.params.productId;

  // Product.findById().then(([product, fieldsData])=>{
  //   if (!product) {
  //     return res.redirect('/');
  //   }

  //   res.render('admin/edit-product', {
  //     pageTitle: 'Edit Product',
  //     path: '/admin/edit-product',
  //     editing: editMode, // to differentiate between add and edit & we also include a query parameter in the url to set this value
  //     product: product, //pass the product to the edit-product view to pre-fill the form
  //     // formsCSS: true,
  //     // productCSS: true,
  //     // activeAddProduct: true
  //   });

  // }).catch(err=>console.log(err));

  // Product.findById(productId, product => {
  // Product.findByPk(productId).then(product => {
  // req.user.getProducts({ where : { id : productId}})

  // Product.findByPk(productId)
  Product.findById(productId)
    .then(product => {
      if (!product) {
        return res.redirect('/');
      }
      // product = product[0];
      res.render('admin/edit-product', {
        pageTitle: 'Edit Product',
        path: '/admin/edit-product',
        editing: editMode, // to differentiate between add and edit & we also include a query parameter in the url to set this value
        product: product, //pass the product to the edit-product view to pre-fill the form
        isAuthenticated: req.session.isLoggedIn,
        hasError: false,
        errorMessage: null,
        validationErrors: []
        // formsCSS: true,
        // productCSS: true,
        // activeAddProduct: true
      })
    })
    .catch(err => console.log(err));
};

exports.postEditProduct = (req, res, next) => {
  const productId = req.body.productId;
  const updatedTitle = req.body.title;
  const updatedImageUrl = req.body.imageUrl;
  const updatedPrice = req.body.price;
  const updatedDescription = req.body.description;

  const errors = validationResult(req);
  if (!errors.isEmpty()) {
    console.log(errors.array());
    return res.status(422).render('admin/edit-product', {
      path: '/admin/edit-product',
      pageTitle: 'Edit Product',
      editing: true,
      hasError: true,
      product: {
        title: updatedTitle,
        price: updatedPrice,
        description: updatedDescription,
        imageUrl: updatedImageUrl,
        _id: productId
      },
      errorMessage: errors.array()[0].msg,
      validationErrors: errors.array()
    })
  }


  // const updateProduct = new Product(
  //   productId,
  //   updatedTitle,
  //   updatedImageUrl,
  //   updatedDescription,
  //   updatedPrice
  // );
  // updateProduct.save();

  // Product.findByPk(productId).then(product => {
  // product.title = updatedTitle;
  // product.price = updatedPrice;
  // product.description = updatedDescription;
  // product.imageUrl = updatedImageUrl;
  // const newProduct = new Product(updatedTitle, updatedPrice, updatedDescription, updatedImageUrl, productId);
  // new mongodb.ObjectId(productId));
  // return 
  // newProduct.save()
  Product.findById(productId).then(product => {

    if (product.userId.toString() !== req.user._id.toString()) {
      return res.redirect('/');
    }

    product.title = updatedTitle;
    product.price = updatedPrice;
    product.description = updatedDescription;
    product.imageUrl = updatedImageUrl;
    return product.save().then(result => {
      console.log("updated product : ", result);
      res.redirect('/admin/products');
      // return the page after all promises are done
    });
  })
    .catch(err => console.log(err));
};

exports.getProducts = (req, res, next) => {
  // Product.fetchAll(products => {
  // Product.findAll().then(products => {
  // req.user.getProducts()

  // Product.fetchAll()
  // Product.find().select('title price -_id').populate('userId', 'name -_id')
  // Product.find({userId: req.user._id}).populate('userId')
  Product.find().populate('userId')
    .then(products => {
      console.log("req.user._id : ", req.user._id);
      console.log(products);
      res.render('admin/products', {
        prods: products,
        pageTitle: 'Admin Products',
        path: '/admin/products',
        isAuthenticated: req.session.isLoggedIn,
      })
    })
    .catch(err => console.log(err));
};


exports.postDeleteProduct = (req, res, next) => {
  const productId = req.params.productId;
  // console.log(productId);
  // better to have a callback delete, so it would update adn then redirect
  // Product.deleteById(productId)
  // Product.findByPk(productId)
  // Product.deleteById(productId)
  // Product.findByIdAndDelete(productId)
  Product.deleteOne({ _id: productId, userId: req.user._id })
    // Product.findByIdAndRemove(productId)
    // .then(product => {
    //   console.log(product);
    //   return product.destroy();
    // })
    .then(result => {
      console.log(result, "updated");
      res.redirect('/admin/products');
    })
    .catch(err => console.log(err));
};