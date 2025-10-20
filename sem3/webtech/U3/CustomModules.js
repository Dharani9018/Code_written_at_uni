//export as a literal
//exports.message = "hello this is custom module"

//export as a function

/*
function add(a,b)
{
    return a+b;
}

function sub(a,b)
{
    return a-b;
}
function mydate()
{
    return Date()
}
module.exports = {add,sub,mydate};
*/
//exporting as objects:

module.exports = function(fname,lname)
{
    this.fname = fname;
    this.lname = lname;
    this.fullname = function()
    {
        return this.fname+" "+ this.lname;
    }
}