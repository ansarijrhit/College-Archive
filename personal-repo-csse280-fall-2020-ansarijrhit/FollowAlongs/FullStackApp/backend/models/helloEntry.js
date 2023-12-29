const mongoose = require("mongoose");

const helloEntrySchema = new mongoose.Schema( {
    name: String,
    count: Number
});
const HelloEntry = mongoose.model('HelloEntry', helloEntrySchema, 'helloentry');
module.exports = HelloEntry;