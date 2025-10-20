//gobal modules: doesnt have to be imported. Ex: console,timer module
//builtin modules: have to be imported using  require/import.
var valid = require("validator")    //npm install validator

var email = "abc@pes.edu";
console.log(valid.isEmail(email));

var chalk1 = require("chalk"); //npm install chalk@4.1.2
console.log(chalk1.blue("I'm blue"))


