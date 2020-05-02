function loadFunction(){
	console.log('loaded');
	const xhr=new XMLHttpRequest();
	const url="https://api.covid19api.com/countries";
	xhr.responseType="json";
	xhr.onreadystatechange=()=>{
    	if(xhr.readyState===XMLHttpRequest.DONE){
        	//console.log(xhr.response);
        	let newArr=[];
        	xhr.response.forEach((item)=>{
        		newArr.push(Object.values(item)[0]);
        	});
        	newArr.sort();
        	//console.log(newArr);
        	let html="";
        	newArr.forEach((item)=>{
        		html+="<li>"+item+"</li>";
        	});
        	document.getElementById("countryList").innerHTML=html;
    	}
	};
	xhr.open('GET',url);
	xhr.send();
}
document.getElementById('button').addEventListener("click",()=>{
	let countryName=document.getElementById("countryNameId").value;
	const xhr=new XMLHttpRequest();
	//const url="https://api.covid19api.com/total/country/"+countryName;
	const url="https://api.covid19api.com/total/dayone/country/"+countryName;
	xhr.responseType="json";
	xhr.onreadystatechange=()=>{
    	if(xhr.readyState===XMLHttpRequest.DONE){
        	//console.log(xhr.response);
        	//console.log(xhr.response.pop());
        	let countryResult=xhr.response.pop();
        	document.getElementById("result").innerHTML=`<p>Country Name: ${countryResult.Country}<br>
        	Confirmed Cases: ${countryResult.Confirmed}<br>Deaths: ${countryResult.Deaths}<br>Recovered: ${countryResult.Recovered}</p>`;
    	}
	};
	xhr.open('GET',url);
	xhr.send();	
})

const xhr=new XMLHttpRequest();
	const url="https://api.covid19api.com/summary";
	xhr.responseType="json";
	xhr.onreadystatechange=()=>{
    	if(xhr.readyState===XMLHttpRequest.DONE){
        	console.log(xhr.response.Global);
        	console.log(xhr.response.Global["TotalConfirmed"]);
        	let html="";
        	html=`<p>New Confirmed: ${xhr.response.Global["NewConfirmed"]}<br>New Deaths: ${xhr.response.Global["NewDeaths"]}<br>
        	New Recovered: ${xhr.response.Global["NewRecovered"]}<br>Total Confirmed: ${xhr.response.Global["TotalConfirmed"]}<br>
        	Total Deaths: ${xhr.response.Global["TotalDeaths"]}<br>Total Recovered: ${xhr.response.Global["TotalRecovered"]}</p>`;
        	document.getElementById("totalResult").innerHTML=html;
    	}
	};
	xhr.open('GET',url);
	xhr.send();
