var express = require("express");
var app = express();

let data = [];

const logger = require("morgan");
app.use(logger('dev'));

const fs = require("fs");
const serverSideStorage = "../data/db.json";

fs.readFile(serverSideStorage, function(err, buf) {
    if(err) {
        console.log("Error: ", err);
    }
    else{
        data = JSON.parse(buf.toString());
    }
    console.log("Data read from file");
});

function saveToServer(data) {
    fs.writeFile(serverSideStorage, JSON.stringify(data), function(err, buf) {
        if(err) {
            console.log("Error: ", err);
        }
        else{
            console.log("Data saved successfully.");
        }
    });
}


app.use('/static', express.static("public"));


var bodyParser = require("body-parser");
app.use('/api/', bodyParser.urlencoded({extended:true}));
app.use('/api/', bodyParser.json());

app.get("/api/", function (req, res) {
    res.send(data);
    res.end();
});


app.post("/api/", function (req, res) {
    let name = req.body.name;
    let count = req.body.count;
    data.push({"name": name, "count": count});
    saveToServer(data);
    res.send("Post successful");
    res.end();
});

app.get("/api/id/:id", function (req, res) {
    let id = parseInt(req.params.id);
    let result = data[id];
    res.send(result);
    res.end();
}).put("/api/id/:id", function (req, res) {
    let id = parseInt(req.params.id);
    let name = req.body.name;
    let count = req.body.count;
    data[id] = {"name": name, "count": count};
    saveToServer(data);
    res.send("Put successful");
    res.end();
}).delete("/api/id/:id", function (req, res) {
    let id = parseInt(req.params.id);
    data.splice(id, 1);
    saveToServer(data);
    res.send(result);
    res.end();
});



app.listen(3000);