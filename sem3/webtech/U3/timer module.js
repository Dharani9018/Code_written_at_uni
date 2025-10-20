// timer module

setTimeout(() => {
    console.log("This message will appear after 2 seconds")
},2000)

let counter = 0;
const timer = setInterval(()=>
{
    counter++;
    console.log(counter);
    if(counter===5)
    {
        clearInterval(timer)
        console.log("stopped");
    }
},1222.32144)
