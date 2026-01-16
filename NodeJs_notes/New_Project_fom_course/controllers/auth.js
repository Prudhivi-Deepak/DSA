const User = require('../models/users');
const bcrypt = require('bcryptjs');
const crypto = require('crypto');
const nodemailer = require('nodemailer');
const sendgridTransport = require('nodemailer-sendgrid-transport');
// const { validationResult } = require('express-validator/check');
const { validationResult } = require('express-validator');

const transporter = nodemailer.createTransport(sendgridTransport({
  auth: {
    api_key: '' //-- > configure
  }
}));

exports.getLogin = (req, res, next) => {
  res.render('auth/login', {
    path: '/login',
    pageTitle: 'Login',
    // isAuthenticated: false
    errorMessage: req.flash('error'),
    oldInput: {email: "", password: ""},
    validationErrors: []
    
  });
};

exports.getSignup = (req, res, next) => {
  res.render('auth/signup', {
    path: '/signup',
    pageTitle: 'Signup',
    errorMessage: req.flash('error'),
    oldInput: {email: "", password: "", confirmPassword: ""},
    validationErrors: []
  });
};

exports.postLogin = (req, res, next) => {
  const email = req.body.email;
  const password = req.body.password;
  // User.findById('5bab316ce0a7c75f783cb8a8')

  const errors = validationResult(req);
  if (!errors.isEmpty()) {
    console.log(errors.array());
    return res.status(422).render('auth/login', {
      path: '/login',
      pageTitle: 'login',
      errorMessage: errors.array()[0].msg,
      oldInput: {email: email, password: password},
      validationErrors: errors.array()
    })
  }

  User.findOne({ email: email })
    .then(user => {
      if (!user) {
        req.flash('error', 'Invalid email or password!');
        return res.redirect('/login');
      }
      return bcrypt.compare(password, user.password).then(doMatch => {
        if (doMatch) {
          req.session.isLoggedIn = true;
          req.session.userId = user._id.toString();
          return req.session.save(err => {
            console.log(err);
            res.redirect('/');
            const mailOptions = {
              to: email,
              from: 'shop@comp.com',
              subject: 'mail subject',
              html: '<h1>success</h1>'
            }
            console.log("mailOptions ; ", mailOptions);
            transporter.sendMail(mailOptions).then(result => {
              console.log(result);
            }).catch(err => console.log(err));
          });
        }
        res.redirect('/login');
      }).catch(err => {
        console.log(err);
        res.redirect('/login');
      });
    })
    .catch(err => console.log(err));
};

exports.postSignup = (req, res, next) => {
  const email = req.body.email;
  const password = req.body.password;
  const confirmPassword = req.body.confirmPassword;

  const errors = validationResult(req);
  if (!errors.isEmpty()) {
    console.log(errors.array());
    return res.status(422).render('auth/signup', {
      path: '/signup',
      pageTitle: 'Signup',
      errorMessage: errors.array()[0].msg,
      oldInput: {email: email, password: password, confirmPassword: req.body.confirmPassword},
      validationErrors: errors.array()
    })
  }



  User.findOne({ email: email }).then(xuser => {
    if (xuser) {
      return res.redirect('/');
    }

    return bcrypt.hash(password, 12).then(hashPassword => {
      const user = new User({
        email: email,
        password: hashPassword,
        cart: { items: [] }
      });
      return user.save();
    })
      .then(result => {
        res.redirect('/login');
        return transporter.sendMail({
          to: email,
          from: 'shop@comp.com',
          subject: 'mail subject',
          html: '<h1>success</h1>'
        });
      })
      .catch(err => console.log(err));
  })
};

exports.postLogout = (req, res, next) => {
  req.session.destroy(err => {
    console.log(err);
    res.redirect('/');
  });
};

exports.getReset = (req, res, next) => {
  res.render('auth/reset', {
    path: '/reset',
    pageTitle: 'Reset Password',
    // isAuthenticated: false,
    errorMessage: req.flash('error')
  });
};

exports.postReset = (req, res, next) => {
  crypto.randomBytes(32, (err, buffer) => {
    if (err) {
      console.log(err);
      return res.redirect('/reset');
    }
    const token = buffer.toString('hex');
    // find user with that email
    User.findOne({ email: req.body.email })
      .then(user => {
        if (!user) {
          req.flash('Error: No account wiht that email found');
          return res.redirect('/reset');
        }
        user.resetToken = token;
        user.resetTokenExpiration = Date.now() + 3600000;
        return user.save();
      })
      .then(result => {
        res.redirect('/');
        const mailOptions = {
          to: req.body.email,
          from: 'shop@comp.com',
          subject: 'mail subject',
          html: `<h1>Password reset <a href="http://localhost:3000/reset/${token} ">Link</a></h1>`
        };
        console.log("mailOptions : ", mailOptions);
        transporter.sendMail(mailOptions);
      })
      .catch(err => console.log(err));

  })
};


exports.getNewPassword = (req, res, next) => {

  const token = req.params.token;
  User.findOne({ resetToken: token, resetTokenExpiration: { $gt: Date.now() } }).then(user => {
    res.render('auth/newPassword', {
      path: '/new-password',
      pageTitle: 'New Password',
      // isAuthenticated: false,
      errorMessage: req.flash('error'),
      userId: user._id.toString(),
      passwordToken: token
    });
  }).catch(err => console.log(err));
};

exports.postNewPassword = (req, res, next) => {
  const newPassword = req.body.password;
  const userId = req.body.userId;
  const passwordToken = req.body.passwordToken;
  let resetUser;

  User.findOne({ resetToken: passwordToken, resetTokenExpiration: { $gt: Date.now() }, _id: userId }).then(user => {
    resetUser = user;
    return bcrypt.hash(newPassword, 12);
  })
    .then(hashedPassword => {
      resetUser.password = hashedPassword;
      resetUser.resetToken = undefined;
      resetUser.resetTokenExpiration = undefined;
      return resetUser.save();
    })
    .then(result => {
      res.redirect('/login');
    })
    .catch(err => console.log(err));


};