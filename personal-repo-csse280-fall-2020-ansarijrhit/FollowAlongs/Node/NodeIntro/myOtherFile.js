name = "Jordan Ansari";

let count = 0;
inc = () => { count++; };
dec = () => {count--; };
getCount = () => { return count; };

module.exports = {
    name, inc, dec, getCount
}