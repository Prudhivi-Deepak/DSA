const mongoose = require('mongoose');
const schema = mongoose.Schema;

const postSchema = new schema({
    title: {
        type: String,
        required: true
    },
    imageUrl: {
        type: String,
        required: true
    },
    content: {
        type: String,
        required: true
    },
    creator: {
        type: schema.Types.ObjectId,
        ref: 'user',
        required: true
    },


}, {timestamp: true});


module.exports = mongoose.model('post', postSchema);