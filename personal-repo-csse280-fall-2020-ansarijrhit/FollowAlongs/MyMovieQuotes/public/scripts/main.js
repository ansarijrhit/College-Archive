
var rhit = rhit || {};

rhit.FB_COLLECTION_MOVIEQUOTES = "MovieQuotes";
rhit.FB_KEY_QUOTE = "quote";
rhit.FB_KEY_MOVIE = "movie";
rhit.FB_KEY_LAST_TOUCHED = "lastTouched";
rhit.FB_KEY_AUTHOR = "author";
rhit.fbMovieQuotesManager = null;
rhit.fbSingleQuoteManager = null;
rhit.fbAuthManager = null;

function htmlToElement(html){
	var template = document.createElement('template');
	html = html.trim();
	template.innerHTML = html;
	return template.content.firstChild;
}


rhit.ListPageController = class {
	constructor() {
		
		document.querySelector("#menuShowAllQuotes").onclick = (event) => {
			window.location.href = "/list.html";
		}
		document.querySelector("#menuShowMyQuotes").onclick = (event) => {
			window.location.href = `/list.html?uid=${rhit.fbAuthManager.uid}`;
		}
		document.querySelector("#menuSignOut").onclick = (event) => {
			rhit.fbAuthManager.signOut();
		}
		document.querySelector("#submitAddQuote").onclick = (event) => {
			console.log("You clikced submit!");
			const quote = document.querySelector("#inputQuote").value;
			const movie = document.querySelector("#inputMovie").value;
			rhit.fbMovieQuotesManager.add(quote, movie);
		}

		$('#addQuoteDialog').on("show.bs.modal", (event) => {
			document.querySelector("#inputQuote").value = "";
			document.querySelector("#inputMovie").value = "";
		});
		$('#addQuoteDialog').on("shown.bs.modal", (event) => {
			document.querySelector("#inputQuote").focus();
		});

		rhit.fbMovieQuotesManager.beginListening(this.updateList.bind(this));
	}

	_createCard(movieQuote) {
		return htmlToElement(`<div class = "card">
        <div class = "card-body">
          <h5 class = "card-title">${movieQuote.quote}</h5>
          <h6 class = "card-subtitle mb-2 text-muted">${movieQuote.movie}</h6>
        </div>
      </div>`);
	}

	updateList() {
		console.log("update List!");

		//Make a new quoteListContainer
		const newList = htmlToElement('<div id = "quoteListContainer"></div>');

		//Fill quoteListContainer with loop
		for(let i = 0; i < rhit.fbMovieQuotesManager.length; i++){
			const mq = rhit.fbMovieQuotesManager.getMovieQuoteAtIndex(i);
			const newCard = this._createCard(mq);

			newCard.onclick = (event) => {
				//rhit.storage.setMovieQuoteId(mq.id);

				window.location.href = `/moviequote.html?id=${mq.id}`;
			};

			newList.appendChild(newCard);	
		}
		//Remove old quoteListContainer
		const oldList = document.querySelector("#quoteListContainer");
		oldList.removeAttribute("id");
		oldList.hidden = true;
		//Put in the new quoteListContainer
		oldList.parentElement.appendChild(newList);
	}
}

rhit.MovieQuote = class {
	constructor(id, quote, movie){
		this.id = id;
		this.quote = quote;
		this.movie = movie;
	}
}

rhit.FbMovieQuotesManager = class {
	constructor(uid) {
		this._uid = uid;
		this._documentSnapshots = [];
		this._ref = firebase.firestore().collection(rhit.FB_COLLECTION_MOVIEQUOTES);
		this._unsubscribe = null;
	}
	add(quote, movie) {
		console.log(quote);
		console.log(movie);
		this._ref.add({
			[rhit.FB_KEY_QUOTE]: quote,
			[rhit.FB_KEY_MOVIE]: movie,
			[rhit.FB_KEY_AUTHOR]: rhit.fbAuthManager.uid,
			[rhit.FB_KEY_LAST_TOUCHED]: firebase.firestore.Timestamp.now()
		})
		.then(function (docRef) {
			console.log("hi");
		})
		.catch(function (error) {
			console.log("hi2");
		});
	}
	beginListening(changeListener){
		let query = this._ref.orderBy(rhit.FB_KEY_LAST_TOUCHED, 'desc').limit(50);

		if(this._uid){
			query = query.where(rhit.FB_KEY_AUTHOR, "==", this._uid);
		}

		this._unsubscribe = query.onSnapshot((querySnapshot) => {

			this._documentSnapshots = querySnapshot.docs;

			changeListener();

		});
	}
	stopListening(){
		this._unsubscribe();
	}
	// update(id, quote, movie){

	// }
	// delete(id){

	// }
	get length(){
		return this._documentSnapshots.length;
	}
	getMovieQuoteAtIndex(index){
		const docSnapshot = this._documentSnapshots[index];
		const movieQuote = new rhit.MovieQuote(
			docSnapshot.id,
			docSnapshot.get(rhit.FB_KEY_QUOTE),
			docSnapshot.get(rhit.FB_KEY_MOVIE)
		);
		return movieQuote;
	}
}

rhit.DetailPageController = class {
	constructor(){
		document.querySelector("#submitEditQuote").onclick = (event) => {
			const quote = document.querySelector("#inputQuote").value;
			const movie = document.querySelector("#inputMovie").value;
			rhit.fbSingleQuoteManager.update(quote, movie);
		}

		document.querySelector("#menuSignOut").onclick = (event) => {
			rhit.fbAuthManager.signOut();
		}

		$('#editQuoteDialog').on("show.bs.modal", (event) => {
			document.querySelector("#inputQuote").value = rhit.fbSingleQuoteManager.quote;
			document.querySelector("#inputMovie").value = rhit.fbSingleQuoteManager.movie;
		});
		$('#editQuoteDialog').on("shown.bs.modal", (event) => {
			document.querySelector("#inputQuote").focus();
		});
		

		document.querySelector("#submitDeleteQuote").onclick = (event) => {
			rhit.fbSingleQuoteManager.delete().then(function () {
				window.location.href = "/list.html";
			}).catch(function (error) {
				console.log("Error removing document: ", error);
			});
		}

		rhit.fbSingleQuoteManager.beginListening(this.updateView.bind(this));
	}
	updateView(){
		document.querySelector("#cardQuote").innerHTML = rhit.fbSingleQuoteManager.quote;
		document.querySelector("#cardMovie").innerHTML = rhit.fbSingleQuoteManager.movie;

		if(rhit.fbSingleQuoteManager.author == rhit.fbAuthManager.uid){
			document.querySelector("#menuEdit").style.display = "flex";
			document.querySelector("#menuDelete").style.display = "flex";
		}
	}
}

rhit.FbSingleQuoteManager = class {
	constructor(movieQuoteId) {
		this._documentSnapshot = {};
		this._unsubscribe = null;
		this._ref = firebase.firestore().collection(rhit.FB_COLLECTION_MOVIEQUOTES).doc(movieQuoteId);
	}
	beginListening(changeListener) {
		this._unsubscribe = this._ref.onSnapshot((doc) => {
			if(doc.exists) {
				this._documentSnapshot = doc;
				console.log("Document data:", doc.data());
				changeListener();
			} else {
				console.log("No such document!");
			}
		});
	}
	stopListening() {
		this._unsubscribe();
	}
	update(quote, movie) {
		this._ref.update({
			[rhit.FB_KEY_QUOTE]: quote,
			[rhit.FB_KEY_MOVIE]: movie,
			[rhit.FB_KEY_LAST_TOUCHED]: firebase.firestore.Timestamp.now()
		})
		.then(function () {
			console.log("hi");
		})
		.catch(function (error) {
			console.log("hi2");
		});
	}
	delete() {
		return this._ref.delete();
	}
	get quote() {
		return this._documentSnapshot.get(rhit.FB_KEY_QUOTE);
	}
	get movie() {
		return this._documentSnapshot.get(rhit.FB_KEY_MOVIE);
	}

	get author() {
		return this._documentSnapshot.get(rhit.FB_KEY_AUTHOR);
	}
}


rhit.LoginPageController = class {
	constructor() {
		document.querySelector("#roseFireButton").onclick = (event) => {
			rhit.fbAuthManager.signIn();
		};
	}
}

rhit.FbAuthManager = class {
	constructor() {
		this._user = null;
	}
	beginListening(changeListener) {
		

		firebase.auth().onAuthStateChanged((user) => {
			this._user = user;
			changeListener();
		  });
	}
	signIn() {
		// Please note this needs to be the result of a user interaction
		// (like a button click) otherwise it will get blocked as a popup
		Rosefire.signIn("34fd0d0f-c77f-4afd-b41d-8e4386f6d6aa", (err, rfUser) => {
			if (err) {
				console.log("Rosefire error!", err);
				return;
			}
			console.log("Rosefire success!", rfUser);
			
			// TODO: Use the rfUser.token with your server.
			firebase.auth().signInWithCustomToken(rfUser.token).catch((error) => {
				const errorCode = error.code;
				const errorMessage = error.message;
				if(errorCode === 'auth/invalid-custom-token'){
					alert('The token you provided is not valid');
				}
				else{
					console.error("Custom auth error", errorCode, errorMessage)
				}
			});
		});

  
	}
	signOut() {
		firebase.auth().signOut().catch((error) => {
			console.log("Sign out error");
		});
	}
	get isSignedIn() {
		return !!this._user;
	}
	get uid() {
		return this._user.uid;
	}
}

rhit.checkForRedirects = function() {
	if(document.querySelector("#loginPage") && rhit.fbAuthManager.isSignedIn){
		window.location.href = "/list.html";
	}
	if(!document.querySelector("#loginPage") && !rhit.fbAuthManager.isSignedIn){
		window.location.href = "/";
	}
};

rhit.initializePage = function() {
	const urlParams = new URLSearchParams(window.location.search);
	if(document.querySelector("#listPage")){
		console.log("You are on the list page.");
		const uid = urlParams.get("uid");
		console.log(uid);
		rhit.fbMovieQuotesManager = new rhit.FbMovieQuotesManager(uid);
		new rhit.ListPageController();
	}

	else if(document.querySelector("#detailPage")){
		//const movieQuoteId = rhit.storage.getMovieQuoteId();

		const queryString = window.location.search
		const urlParams = new URLSearchParams(queryString);
		const movieQuoteId = urlParams.get("id");

		if(!movieQuoteId){
			console.log("Error: Missing movie quote id.");
			window.location.href = "/";
		}
		rhit.fbSingleQuoteManager = new rhit.FbSingleQuoteManager(movieQuoteId);
		new rhit.DetailPageController();
	}

	if(document.querySelector("#loginPage")) {
		console.log("You are on the login page.");
		new rhit.LoginPageController();
	}
}

/* Main */
/** function and class syntax examples */
rhit.main = function () {

	rhit.fbAuthManager = new rhit.FbAuthManager();
	rhit.fbAuthManager.beginListening(() => {

		rhit.checkForRedirects();

		rhit.initializePage();


	});

	

	//const ref = firebase.firestore().collection("MovieQuotes");
	
	// ref.onSnapshot((querySnapshot) => {
	// 	var cities = [];
	// 	querySnapshot.forEach((doc) => {
	// 		console.log(doc.data());
	// 	});
	// });
};

rhit.main();
