const path = require('path');

const express = require('express');

const shopController = require('../controllers/shop');

const router = express.Router();

router.get('/', shopController.getIndex);

router.get('/products', shopController.getProducts);

router.get('/products/:productId', shopController.getProduct);

// router.get('/products/delete'); --> this route will never be used, because above route will catch it first

router.get('/cart', shopController.getCart);

router.post('/cart', shopController.postCart);

router.post('/cart-delte-item/:productId', shopController.postCartDeleteProduct);

router.get('/orders', shopController.getOrders);

router.get('/checkout', shopController.getCheckout);

module.exports = router;
