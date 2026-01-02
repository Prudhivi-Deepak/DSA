const path = require('path');
const express = require('express'); //exports a function
const router = express.Router();

const rootDir = require('../util/path');
const adminController  = require('../controllers/adminController');

// router.use('/admin/add-user',(req, res, next)=>{
// router.get('/admin/add-user',(req, res, next)=>{
// admin/add-user
router.get('/add-user', adminController.getAddUser);

// admin/users
router.get('/users', adminController.getUsers);

// app.use('/store-user',(req, res, next)=>{
// router.post('/admin/store-user',(req, res, next)=>{
// router.post('/admin/add-user',(req, res, next)=>{
router.post('/add-user', adminController.postAddUser);

module.exports = router;
// exports.routes = router;
// exports.users = users;