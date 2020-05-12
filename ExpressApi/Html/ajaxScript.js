document.getElementById("normalApiButton").addEventListener("click",()=>{
    const url=document.getElementById("normalApiActionId").value;
    const xhr=new XMLHttpRequest();
    if(url==="http://localhost:3000/json"){
        xhr.responseType='json';
        xhr.onreadystatechange=()=>{
            if(xhr.readyState===XMLHttpRequest.DONE){
                console.log(typeof xhr.response);
                console.log(xhr.response);
                let jsonString=JSON.stringify(xhr.response);
                document.getElementById("normalApiOutputId").innerHTML=`<p><strong>Api Request Url:</strong> &nbsp;${url}<br><br>
                <strong>Api Output:</strong> &nbsp;${jsonString}</p>`;    
            }
        };
        xhr.open('GET',url);
        xhr.send();
    }else if(url==="http://localhost:3000/file"){
        xhr.onreadystatechange=()=>{
            if(xhr.readyState===XMLHttpRequest.DONE){
                let html="<xmp>"+xhr.response+"</xmp>";
                console.log(html);
                document.getElementById("normalApiOutputId").innerHTML=`<p><strong>Api Request Url:</strong> &nbsp;${url}<br><br>
                <strong>Api Output:</strong> &nbsp;${html}</p>`;
            }
        };
        xhr.open('GET',url);
        xhr.send();
    }else{
        xhr.onreadystatechange=()=>{
            if(xhr.readyState===XMLHttpRequest.DONE){
                console.log(typeof xhr.response);
                console.log(xhr.response);
                document.getElementById("normalApiOutputId").innerHTML=`<p><strong>Api Request Url:</strong> &nbsp;${url}<br><br>
                <strong>Api Output:</strong> &nbsp;${xhr.response}</p>`;
            }
        };
        xhr.open('GET',url);
        xhr.send();
    }
});
document.getElementById("routeParamButton").addEventListener("click",()=>{
    const url=`http://localhost:3000/name/${document.getElementById("routeParamNameId").value}/age/${document.getElementById("routeParamAgeId")
    .value}/gender/${document.getElementById("routeParamGenderId").value}`;
    const xhr=new XMLHttpRequest();
    xhr.responseType='json';
    xhr.onreadystatechange=()=>{
        if(xhr.readyState===XMLHttpRequest.DONE){
            console.log(xhr.response);  
            let jsonString=JSON.stringify(xhr.response);
            document.getElementById("routeParamOutputId").innerHTML=`<p><strong>Api Request Url:</strong> &nbsp;${url}<br><br>
            <strong>Api Output:</strong> &nbsp;${jsonString}</p>`;
        }
    };
    xhr.open('GET',url);
    xhr.send();
});
document.getElementById("queryParamButton").addEventListener("click",()=>{
    const url=`http://localhost:3000/queryParams?name=${document.getElementById("queryParamNameId").value}&age=${document.getElementById
    ("queryParamAgeId").value}&gender=${document.getElementById("queryParamGenderId").value}`;
    const xhr=new XMLHttpRequest();
    xhr.responseType='json';
    xhr.onreadystatechange=()=>{
        if(xhr.readyState===XMLHttpRequest.DONE){
            console.log(xhr.response);  
            let jsonString=JSON.stringify(xhr.response);
            document.getElementById("queryParamOutputId").innerHTML=`<p><strong>Api Request Url:</strong> &nbsp;${url}<br><br>
            <strong>Api Output:</strong> &nbsp;${jsonString}</p>`;
        }
    };
    xhr.open('GET',url);
    xhr.send();
})

/*fetch(url).then(response=>{
    if(response.ok){
        console.log(response);
        //return response.text();
        return response.json();
    }
},networkError=>{
    console.log(networkError.message);
}).then(jsonResponse=>{
    console.log(jsonResponse);
});*/