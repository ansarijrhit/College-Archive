var express = require("express");
var app = express();
var cors = require("cors");

app.use(cors());

require('./models/db');

const HelloEntry = require('./models/helloEntry');


const logger = require("morgan");
app.use(logger('dev'));

var bodyParser = require("body-parser");
const { isBuffer } = require("util");
app.use('/api/', bodyParser.urlencoded({extended:true}));
app.use('/api/', bodyParser.json());

app.get("/api/", function (req, res) {
    HelloEntry.find({}, (err, entries) => {
        if(err) {
            res.json(err);
            res.status(404);
        }
        else {
            res.status(200);
            res.json(entries);
        }
    });
    
    // res.send(data);
    // res.end();
});


app.post("/api/", function (req, res) {
    let name = req.body.name;
    let count = req.body.count;
    HelloEntry.create({
        name: name,
        count: count
    }, (err, entry) => {
        if(err) {
            res.status(400);
            res.json(err);
        }
        else {
            res.status(201);
            res.json(entry);
        }
    });
});

app.get("/api/id/:id", function (req, res) {
    let id = req.params.id;
    HelloEntry.findById(id, (err, entry) => {
        if(err) {
            res.status(404);
            res.json(err);
        }
        else{
            res.status(200);
            res.json(entry);
        }
    });

}).put("/api/id/:id", function (req, res) {
    let id = req.params.id;
    HelloEntry.findById(id, (err, helloEntry) => {
        helloEntry.name = req.body.name || helloEntry.name;
        helloEntry.count = req.body.count || helloEntry.count;
        helloEntry.save( (err, entry) => {
            if(err) {
                res.status(404);
                res.json(err);
            }
            else{
                res.status(201);
                res.json(entry);
            }
        });
    });

    // let name = req.body.name;
    // let count = req.body.count;
    // data[id] = {"name": name, "count": count};
    // saveToServer(data);
    // res.send("Put successful");
    // res.end();
}).delete("/api/id/:id", function (req, res) {
    let id = req.params.id;

    HelloEntry.findByIdAndDelete(id, (err, helloEntry) => {
        if(err) {
            res.status(404);
            res.json(err);
        }
        else {
            res.status(204);
            res.json(null);
        }
    });
});



app.listen(3000);