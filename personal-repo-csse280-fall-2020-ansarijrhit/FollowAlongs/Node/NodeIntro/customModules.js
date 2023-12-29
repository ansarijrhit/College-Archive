console.clear();

const myModule = require("./myOtherFile.js");

// console.log(myModule.name);
console.log("Counter = ", myModule.getCount());
myModule.inc();
myModule.inc();
console.log("Counter = ", myModule.getCount());