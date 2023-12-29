/**
 * @fileoverview
 * Provides the JavaScript interactions for all pages.
 *
 * @author 
 * PUT_YOUR_NAME_HERE
 */

/** namespace. */
var rhit = rhit || {};

/** globals */
rhit.date = new Date();



rhit.changeDate = function(type, amount){
	if(type == "reset"){
		rhit.date.setTime(Date.now());
	}
	else if(type == "year"){
		rhit.date.setFullYear(rhit.date.getFullYear()+amount);
	}
	else if(type == "month"){
		rhit.date.setMonth(rhit.date.getMonth()+amount);
	}
	else if(type == "hour"){
		rhit.date.setHours(rhit.date.getHours()+amount);
	}
	$("#dateContainer").html(rhit.date.toLocaleTimeString('en-US', { weekday: 'short', year: 'numeric',
	month: 'long', day: 'numeric', hour12: false, hour:
	'2-digit', minute:'2-digit'}));
}

/* Main */
/** function and class syntax examples */
rhit.main = function () {
	rhit.changeDate("reset", 0);
	$(".btn").click((event) => {
		const dataType = $(event.target).data("type");
		const dataAmount = $(event.target).data("amount");
		rhit.changeDate(dataType, dataAmount);
	});

};

rhit.main();
