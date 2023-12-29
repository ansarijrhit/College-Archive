var rhit = rhit || {};

rhit.FB_COLLECTION_PHOTOS = "Photos";
rhit.FB_KEY_PHOTO = "photo";
rhit.FB_KEY_CAPTION = "caption";
rhit.FB_KEY_LAST_TOUCHED = "lastTouched";
rhit.fbPhotoManager = null;
rhit.fbSinglePhotoManager = null;

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
	constructor() {
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
		this._unsubscribe = this._ref
		.orderBy(rhit.FB_KEY_LAST_TOUCHED, 'desc')
		.onSnapshot((querySnapshot) => {

			this._documentSnapshots = querySnapshot.docs;

			// querySnapshot.forEach((doc) => {
			// 	console.log(doc.data());
			// });

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
}

rhit.main = function () {

	if(document.querySelector("#listPage")){
		console.log("You are on the list page.");
		rhit.fbPhotoManager = new rhit.fbPhotoManager();
		new rhit.ListPageController();
	}

	else if(document.querySelector("#detailPage")){

		const queryString = window.location.search
		const urlParams = new URLSearchParams(queryString);
		const id = urlParams.get("id");

		if(!id){
			console.log("Error: Missing photo id.");
			window.location.href = "/";
		}
		rhit.fbSinglePhotoManager = new rhit.FbSinglePhotoManager(id);
		new rhit.DetailPageController();
	}
};

rhit.main();
