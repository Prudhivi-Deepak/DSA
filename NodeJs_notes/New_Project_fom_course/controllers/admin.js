const Product = require('../models/product');

exports.getAddProduct = (req, res, next) => {
  // res.render('admin/add-product', /{
  res.render('admin/edit-product', {
    pageTitle: 'Add Product',
    path: '/admin/add-product',
    editing: false,
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
  const product = new Product(null, title, imageUrl, description, price);
  product.save();
  res.redirect('/');
};

exports.getEditProduct = (req, res, next) => {
  // res.render('admin/add-product', /{
  const editMode = req.query.edit; //all the extracted values from the url are strings
  if (!editMode) {
    return res.redirect('/');
  }
  const productId = req.params.productId;
  Product.findById(productId, product => {
    if (!product) {
      return res.redirect('/');
    }
    res.render('admin/edit-product', {
      pageTitle: 'Edit Product',
      path: '/admin/edit-product',
      editing: editMode, // to differentiate between add and edit & we also include a query parameter in the url to set this value
      product: product, //pass the product to the edit-product view to pre-fill the form
      // formsCSS: true,
      // productCSS: true,
      // activeAddProduct: true
    });
  });
};

exports.postEditProduct = (req, res, next) => {
  const productId = req.body.productId;
  const updatedTitle = req.body.title;
  const updatedImageUrl = req.body.imageUrl;
  const updatedPrice = req.body.price;
  const updatedDescription = req.body.description;

  const updateProduct = new Product(
    productId,
    updatedTitle,
    updatedImageUrl,
    updatedDescription,
    updatedPrice
  );
  updateProduct.save();
  res.redirect('/admin/products');

};

exports.getProducts = (req, res, next) => {
  Product.fetchAll(products => {
    res.render('admin/products', {
      prods: products,
      pageTitle: 'Admin Products',
      path: '/admin/products'
    });
  });
};


exports.postDeleteProduct = (req, res, next) => {
  const productId = req.params.productId;
  // better to have a callback delete, so it would update adn then redirect
  Product.deleteById(productId)
  res.redirect('/admin/products');
};