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
rhit.moves = 0;

rhit.PageController = class {
	constructor() {
		this.game = new rhit.Game();

		const lights = document.querySelectorAll(".light");

		for(const light of lights){
			light.onclick = (event) => {
				const buttonIndex = parseInt(light.dataset.buttonIndex);
				this.game.pressButtonAtIndex(buttonIndex);
				this.updateView();
			};
		}


		document.querySelector(".btn-new").onclick = (event) => {
			this.game = new rhit.Game();
			this.updateView();
		}

		this.updateView();
		document.querySelector("#header").innerHTML = "Make the buttons match.";
	}

	updateView() {
		
		const lights = document.querySelectorAll(".light");
		lights.forEach((light, index) => {
			if(!this.game.getMarkAtIndex(index)){
				light.innerHTML = "0";
				light.style.backgroundColor = "#343A40";
				light.style.color = "white";
			}
			else{
				light.innerHTML = "1";
				light.style.backgroundColor = "#F8C02E";
				light.style.color = "black";
			}
		});
			
		if(this.game.checkForWin()){
			document.querySelector("#header").innerHTML = "You won in " + rhit.moves + " moves!";
		}
		else{
			document.querySelector("#header").innerHTML = "You have taken " +rhit.moves + " moves so far.";
		}
	}
}

rhit.Game = class {

	static State = {
		PLAY: "PLAY",
		WON: "WON"
	}

	constructor() {
		this.state = rhit.Game.State.PLAY
		this.board = [];
		for(let k = 0; k < 7; k++){
			this.board.push(true);
		}

		for(let k = 0; k < 7; k++){
			if(Math.round(Math.random()) == 1){
				this.pressButtonAtIndex(k);
			}

		}
		if(this.checkForWin()){
			this.pressButtonAtIndex(3);
		}
		rhit.moves = 0;
	}

	pressButtonAtIndex(buttonIndex) {
		if(this.state == rhit.Game.State.WON){
			return;
		}
		else{
			rhit.moves++;
			this.board[buttonIndex] = !this.board[buttonIndex];
			if(buttonIndex != 0){
				this.board[buttonIndex - 1] = !this.board[buttonIndex - 1];
			}
			if(buttonIndex != 6){
				this.board[buttonIndex + 1] = !this.board[buttonIndex + 1];
			}
		}
		if(this.checkForWin()){
			this.state = rhit.Game.State.WON;
		}
		
	}

	checkForWin(){
		for(let i = 0; i < this.board.length-1; i++){
			if(this.board[i] !== this.board[i+1]){
				return false;
			}
		}
		return true;
	}

	getMarkAtIndex(buttonIndex){
		return this.board[buttonIndex];
	}

	getState(){
		return this.state;
	}
}

/* Main */
/** function and class syntax examples */
rhit.main = function () {
	console.log("Ready");
	new rhit.PageController();
};

rhit.main();
