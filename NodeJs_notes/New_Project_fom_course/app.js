const path = require('path');

const express = require('express');
const bodyParser = require('body-parser');

const errorController = require('./controllers/error');

const db = require('./util/database')

const app = express();

app.set('view engine', 'ejs');
app.set('views', 'views');

const adminRoutes = require('./routes/admin');
const shopRoutes = require('./routes/shop');

// execute the SQL cmd
db.execute('SELECT * From products')
// then-> get the anonymous function to execute
.then((result)=>{
    console.log(result[0], result[1]);
})
 // in case of any error
.catch((err)=>{
        console.log(err)
}); 

app.use(bodyParser.urlencoded({ extended: false }));
app.use(express.static(path.join(__dirname, 'public')));

app.use('/admin', adminRoutes);
app.use(shopRoutes);

app.use(errorController.get404);

app.listen(3000);
