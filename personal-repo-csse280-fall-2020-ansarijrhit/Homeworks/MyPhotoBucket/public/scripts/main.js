var rhit = rhit || {};

rhit.FB_COLLECTION_PHOTOS = "Photos";
rhit.FB_KEY_PHOTO = "photo";
rhit.FB_KEY_CAPTION = "caption";
rhit.FB_KEY_LAST_TOUCHED = "lastTouched";
rhit.FB_KEY_AUTHOR = "author";
rhit.fbPhotoManager = null;
rhit.fbSinglePhotoManager = null;
rhit.fbAuthManager = null;

function htmlToElement(html){
	var template = document.createElement('template');
	html = html.trim();
	template.innerHTML = html;
	return template.content.firstChild;
}


rhit.ListPageController = class {
	constructor() {
		document.querySelector("#submitPhoto").onclick = (event) => {
			console.log("You clicked Create!");
			const image = document.querySelector("#inputImage").value;
			const caption = document.querySelector("#inputCaption").value;
			rhit.fbPhotoManager.add(image, caption);
		}

		document.querySelector("#menuShowAllPhotos").onclick = (event) => {
			window.location.href = "/list.html";
		}
		document.querySelector("#menuShowMyPhotos").onclick = (event) => {
			window.location.href = `/list.html?uid=${rhit.fbAuthManager.uid}`;
		}
		document.querySelector("#menuSignOut").onclick = (event) => {
			rhit.fbAuthManager.signOut();
		}

		$('#addPhoto').on("show.bs.modal", (event) => {
			document.querySelector("#inputImage").value = "";
			document.querySelector("#inputCaption").value = "";
		});
		$('#addPhoto').on("shown.bs.modal", (event) => {
			document.querySelector("#inputImage").focus();
		});

		rhit.fbPhotoManager.beginListening(this.updateList.bind(this));
	}

	_createCard(photo) {
		return htmlToElement(`<div class="pin" id="${photo.id}">
		<img src="${photo.photoURL}" alt="${photo.caption}">
		<p class="caption">${photo.caption}</p>
	  </div>`);
	}

	updateList() {
		console.log("update List!");

		const newList = htmlToElement('<div id = "columns"></div>');

		for(let i = 0; i < rhit.fbPhotoManager.length; i++){
			const photo = rhit.fbPhotoManager.getPhotoAtIndex(i);
			const newCard = this._createCard(photo);

			newCard.onclick = (event) => {
				window.location.href = `/photo.html?id=${photo.id}`;
			};

			newList.appendChild(newCard);	
		}
		//Remove old container
		const oldList = document.querySelector("#columns");
		oldList.removeAttribute("id");
		oldList.hidden = true;
		//Put in the new container
		oldList.parentElement.appendChild(newList);
	}
}

rhit.Photo = class {
	constructor(id, photoURL, caption){
		this.id = id;
		this.photoURL = photoURL;
		this.caption = caption;
	}
}

rhit.fbPhotoManager = class {
	constructor(uid) {
		this._uid = uid;
		this._documentSnapshots = [];
		this._ref = firebase.firestore().collection(rhit.FB_COLLECTION_PHOTOS);
		this._unsubscribe = null;
	}
	add(photo, caption) {
		console.log(photo);
		console.log(caption);
		this._ref.add({
			[rhit.FB_KEY_PHOTO]: photo,
			[rhit.FB_KEY_CAPTION]: caption,
			[rhit.FB_KEY_AUTHOR]: rhit.fbAuthManager.uid,
			[rhit.FB_KEY_LAST_TOUCHED]: firebase.firestore.Timestamp.now()
		})
		.then(function (docRef) {
			console.log("boi");
		})
		.catch(function (error) {
			console.log("errrrrror");
		});
	}
	beginListening(changeListener){
		let query = this._ref.orderBy(rhit.FB_KEY_LAST_TOUCHED, 'desc').limit(50);

		if(this._uid){
			query = query.where(rhit.FB_KEY_AUTHOR, "==", this._uid);
		}

		this._unsubscribe = query
		.onSnapshot((querySnapshot) => {
			this._documentSnapshots = querySnapshot.docs;
			changeListener();
		});
	}
	stopListening(){
		this._unsubscribe();
	}
	
	get length(){
		return this._documentSnapshots.length;
	}
	getPhotoAtIndex(index){
		const docSnapshot = this._documentSnapshots[index];
		const photo = new rhit.Photo(
			docSnapshot.id,
			docSnapshot.get(rhit.FB_KEY_PHOTO),
			docSnapshot.get(rhit.FB_KEY_CAPTION)
		);
		return photo;
	}
}

rhit.DetailPageController = class {
	constructor(){
		document.querySelector("#editCaption").onclick = (event) => {
			const caption = document.querySelector("#caption").value;
			rhit.fbSinglePhotoManager.update(caption);
		}

		document.querySelector("#menuSignOut").onclick = (event) => {
			rhit.fbAuthManager.signOut();
		}

		$('#editPhotoCaption').on("show.bs.modal", (event) => {
			document.querySelector("#caption").value = rhit.fbSinglePhotoManager.caption;
		});
		$('#editPhotoCaption').on("shown.bs.modal", (event) => {
			document.querySelector("#caption").focus();
		});

		document.querySelector("#deletePhoto").onclick = (event) => {
			rhit.fbSinglePhotoManager.delete().then(function () {
				window.location.href = "/";
			}).catch(function (error) {
				console.log("Error removing document: ", error);
			});
		}

		rhit.fbSinglePhotoManager.beginListening(this.updateView.bind(this));
	}
	updateView(){
		document.querySelector(".img-fluid").src = rhit.fbSinglePhotoManager.photo;
		document.querySelector(".caption").innerHTML = rhit.fbSinglePhotoManager.caption;
		if(rhit.fbSinglePhotoManager.author == rhit.fbAuthManager.uid){
			document.querySelector("#menuEdit").style.display = "flex";
			document.querySelector("#menuDelete").style.display = "flex";
		}
	}
}

rhit.FbSinglePhotoManager = class {
	constructor(id) {
		this._documentSnapshot = {};
		this._unsubscribe = null;
		this._ref = firebase.firestore().collection(rhit.FB_COLLECTION_PHOTOS).doc(id);
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
	update(caption) {
		this._ref.update({
			[rhit.FB_KEY_CAPTION]: caption,
			[rhit.FB_KEY_LAST_TOUCHED]: firebase.firestore.Timestamp.now()
		})
		.then(function () {
			console.log("sucess");
		})
		.catch(function (error) {
			console.log("u failed smh");
		});
	}
	delete() {
		return this._ref.delete();
	}
	get photo() {
		return this._documentSnapshot.get(rhit.FB_KEY_PHOTO);
	}
	get caption() {
		return this._documentSnapshot.get(rhit.FB_KEY_CAPTION);
	}
	get author() {
		return this._documentSnapshot.get(rhit.FB_KEY_AUTHOR);
	}
}

rhit.FbAuthManager = class {
	constructor() {
		this._user = null;
	}
	beginListening(changeListener) {
		console.log("FBAuthManager Begin Listening");

		firebase.auth().onAuthStateChanged((user) => {
			console.log(this._user);
			this._user = user;
			changeListener();
		  });
	}
	signIn() {
		// Please note this needs to be the result of a user interaction
		// (like a button click) otherwise it will get blocked as a popup
		Rosefire.signIn("799f0544-3b1c-4886-8f80-890bd23c28a4", (err, rfUser) => {
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

rhit.initializePage = function() {
	const urlParams = new URLSearchParams(window.location.search);
	if(document.querySelector("#listPage")){
		console.log("You are on the list page.");
		const uid = urlParams.get("uid");
		console.log(uid);
		rhit.fbPhotoManager = new rhit.fbPhotoManager(uid);
		new rhit.ListPageController();
	}

	else if(document.querySelector("#detailPage")){

		const queryString = window.location.search
		const urlParams = new URLSearchParams(queryString);
		const photoId = urlParams.get("id");

		if(!photoId){
			console.log("Error: Missing photo id.");
			window.location.href = "/";
		}
		rhit.fbSinglePhotoManager = new rhit.FbSinglePhotoManager(photoId);
		new rhit.DetailPageController();
	}

	if(document.querySelector("#mainPage")) {
		console.log("You are on the login page.");
		new rhit.LoginPageController();
	}
}

rhit.checkForRedirects = function() {
	if(document.querySelector("#mainPage") && rhit.fbAuthManager.isSignedIn){
		window.location.href = "/list.html";
	}
	if(!document.querySelector("#mainPage") && !rhit.fbAuthManager.isSignedIn){
		window.location.href = "/";
	}
};

rhit.main = function () {

	// if(document.querySelector("#listPage")){
	// 	console.log("You are on the list page.");
	// 	rhit.fbPhotoManager = new rhit.fbPhotoManager();
	// 	new rhit.ListPageController();
	// }

	// else if(document.querySelector("#detailPage")){

	// 	const queryString = window.location.search
	// 	const urlParams = new URLSearchParams(queryString);
	// 	const id = urlParams.get("id");

	// 	if(!id){
	// 		console.log("Error: Missing photo id.");
	// 		window.location.href = "/";
	// 	}
	// 	rhit.fbSinglePhotoManager = new rhit.FbSinglePhotoManager(id);
	// 	new rhit.DetailPageController();
	// }
	// else if(document.querySelector("#mainPage")){
	// 	console.log("You are on the main page.");
	// 	new rhit.LoginPageController();
	// }

	rhit.fbAuthManager = new rhit.FbAuthManager();
	rhit.fbAuthManager.beginListening(() => {

		rhit.checkForRedirects();

		rhit.initializePage();


	});
};

rhit.startFirebaseUI = function() {
	// FirebaseUI config.
	var uiConfig = {
        signInSuccessUrl: '/',
        signInOptions: [
          // Leave the lines as is for the providers you want to offer your users.
          firebase.auth.GoogleAuthProvider.PROVIDER_ID,
          firebase.auth.EmailAuthProvider.PROVIDER_ID,
          firebase.auth.PhoneAuthProvider.PROVIDER_ID,
          firebaseui.auth.AnonymousAuthProvider.PROVIDER_ID
        ],
      };

      // Initialize the FirebaseUI Widget using Firebase.
      const ui = new firebaseui.auth.AuthUI(firebase.auth());
      // The start method will wait until the DOM is loaded.
      ui.start('#firebaseui-auth-container', uiConfig);
}

rhit.LoginPageController = class {
	constructor() {
		rhit.startFirebaseUI();
		document.querySelector("#roseFireButton").onclick = (event) => {
			rhit.fbAuthManager.signIn();
		};
	}
}

rhit.main();