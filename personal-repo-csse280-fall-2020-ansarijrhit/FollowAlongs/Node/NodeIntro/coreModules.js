const path = require("path");
const util = require("util");
const fs = require("fs");

const filesDirectory = path.join(__dirname, "Files");

console.log(filesDirectory);
util.log("Hello");

fs.writeFile(path.join(filesDirectory, "test.txt"), "H-Hewwo? Node.js-chan?", (err) => {
    if(err) {
        console.log("Error", err);
        return;
    }
    console.log("Success");
});

const fileContents = fs.readFileSync(path.join(filesDirectory, "test.txt"), "UTF-8");
console.log("From file: ", fileContents);