var express=require('express');
var cors=require('cors');
var dotenv=require('dotenv');
var app=express();

dotenv.config();
app.use(cors());

var obj={
    carName: 'Rolls Royce Phantom',
    color: 'dark red',
    price: 600000
};

//This will execute for any route path and req.path will print the route parameter/route path which is requesting from the server
app.use((req,res,next)=>{
    console.log(req.method+" "+req.path+" "+req.ip);
    next();
})

app.get("/",(req,res)=>{
    res.send("Use 1.'/file' to get Html file 2.'/json' to get a JSON obj response");
});
app.get("/file",(req,res)=>{
    res.sendFile(__dirname+"/Html/index.html");
});
app.get("/json",(req,res)=>{
    res.json(obj);
});
app.get("/env",(req,res)=>{
    if(process.env.MESSAGE_STYLE==="uppercase"){
        res.send("Uppercase".toUpperCase());
    }else{
        res.send("Not Uppercase");
    }
});
app.get("/time",(req,res,next)=>{
    req.time=new Date().toString();
    next();
},(req,res)=>{
    res.send(req.time);
});
app.get("/test",(req,res,next)=>{
    req.test="Just for test";
    next();
},(req,res)=>{
    res.send(req.test);
});
app.get("/name/:name/age/:age/gender/:gender",(req,res)=>{
    var {name,age,gender}=req.params;
    res.json({Name: name,Age: age,Gender: gender});
});
app.get("/queryParams",(req,res)=>{
    var {name,age,gender}=req.query;
    res.json({Name: name,Age: age,Gender: gender});
});
app.listen(3000,()=>{
    console.log("Express API app is listening to port 3000");
})