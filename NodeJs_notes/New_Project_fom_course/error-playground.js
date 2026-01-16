const sum = (a,b)=>{
    if(a && b){
        return a+b;
    }
    throw new Error("new eereo ");
}

try{
console.log(sum(1)); 
}
catch(err){
    console.log(err);
}