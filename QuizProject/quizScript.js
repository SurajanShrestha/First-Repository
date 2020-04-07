let answer={
	youngChampAnswer: "",
	twoDivChampAnswer: "",
	fastKoAnswer: "",
	winStreakAnswer: "",
	mostSubmissionAnswer: "",
	points: 0
};
function youngChampClk(value){
	answer.youngChampAnswer=value;
	if(answer.youngChampAnswer==='Jon Jones'){
		answer.points++;
		//alert(answer.points);
	}
	//alert(answer.young);
};
function twoDivChampClk(value){
	answer.twoDivChampAnswer=value;
	if(answer.twoDivChampAnswer==='Conor Mcgregor'){
		answer.points++;
		//alert(answer.points);
	}
	//alert(answer.twoDivChampAnswer);
};
function fastKoClk(value){
	answer.fastKoAnswer=value;
	if(answer.fastKoAnswer==='Jorge Masvidal'){
		answer.points++;
		//alert(answer.points);
	}
	//alert(answer.fastKoAnswer);	
};
function winStreakClk(value){
	answer.winStreakAnswer=value;
	if(answer.winStreakAnswer==='Anderson Silva'){
		answer.points++;
		//alert(answer.points);
	}
	//alert(answer.winStreakAnswer);
};
function mostSubmissionClk(value){
	answer.mostSubmissionAnswer=value;
	if(answer.mostSubmissionAnswer==='Charles Oliveira'){
		answer.points++;
		//alert(answer.points);
	}
	//alert(answer.mostSubmissionAnswer);
};
function onSubmit(){
	if(answer.points>=3){
		alert("You Scored: "+answer.points);
		alert("You Win");
	}else{
		alert("You Scored: "+answer.points);
		alert("You Lost");
	}
};
