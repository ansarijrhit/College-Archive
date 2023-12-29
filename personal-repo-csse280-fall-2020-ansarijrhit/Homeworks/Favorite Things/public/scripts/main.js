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
rhit.value = 0;

/** function and class syntax examples */
rhit.updateCounter = function (amount) {
	if(amount != 0){
		rhit.value += amount;
	}
	else{
		rhit.value = 0;
	}
	$(".counterText").html(`${rhit.value}`);
};

rhit.updateColor = function (color) {
	$("#favoriteColorBox").html(`${color}`);
	document.getElementById("favoriteColorBox").style.backgroundColor = color;
}

/* Main */
/** function and class syntax examples */
rhit.main = function () {
	$("#number button").click((event) => {
		console.log("Number Button", event.target);
		const dataAmount = $(event.target).data("amount");
		rhit.updateCounter(dataAmount);
	});
	$("#color button").click((event) => {
		console.log("Color Button", event.target);
		const dataColor = $(event.target).data("color");
		rhit.updateColor(dataColor);
	});
};

rhit.main();
