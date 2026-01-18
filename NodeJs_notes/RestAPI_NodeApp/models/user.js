const mongoose = require('mongoose');
const post = require('./post');
const schema = mongoose.Schema;

const userSchema = new schema({
    email: {
        type: String,
        required: true
    },
    password: {
        type: String,
        required: true
    },
    name: {
        type: String,
        required: true
    },
    status: {
        type: Object,
        default: 'I am new!'
    },
    posts : [
        {
            type: schema.Types.ObjectId,
            ref: 'post'
        }
    ]


}, {timestamp: true});


module.exports = mongoose.model('user', userSchema);