//const custom = require("./CustomModules")
//console.log(custom.message)

//console.log("Addition : "+cu  stom.add(10,20));
var student = require("./CustomModules")
var student1 = new student("James","Bond");
console.log("Name is : "+student1.fullname());