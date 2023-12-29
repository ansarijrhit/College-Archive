/**
 * @fileoverview
 * Provides the JavaScript interactions for all pages.
 *
 * @author 
 * Jordan Ansari
 */

/** namespace. */
var rhit = rhit || {};

/** globals */
rhit.counter = 0;

rhit.updateCounter = function (amount, isMultiplication) {
	if(isMultiplication){
		rhit.counter *= amount;
	}
	else{
		rhit.counter += amount;
	}
	//document.querySelector("#counterText").innerHTML = `Count = ${rhit.counter}`;
	$("#counterText").html(`Count = ${rhit.counter}`);
};

/* Main */
/** function and class syntax examples */
rhit.main = function () {
	console.log("Ready");
	
	//  const buttons = document.querySelectorAll("#counterButtons button");
	// for(let i = 0; i < buttons.length; i++){
	// 	const button = buttons[i];

	// 	button.onclick = (event) => {
	// 		console.log('You pressed', button);
	// 	}
	// }
	// for(const button of buttons){
	// 	button.onclick = (event) => {
	// 		const dataAmount = parseInt(button.dataset.amount);
	// 		const dataIsMultiplication = button.dataset.isMultiplication;
	// 		rhit.updateCounter(dataAmount, dataIsMultiplication);
	// 	}
	// }

	$("#counterButtons button").click((event) => {
		console.log("Button", event.target);
		const dataAmount = $(event.target).data("amount");
		const dataIsMultiplication = $(event.target).data("isMultiplication");
		rhit.updateCounter(dataAmount, dataIsMultiplication);
	});
};

rhit.main();
