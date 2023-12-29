var rhit = rhit || {};

rhit.variableName = "";




rhit.main = function () {
	console.log("Ready");

	firebase.auth().onAuthStateChanged(function(user) {
		if (user) {
		  // User is signed in.
		  const displayName = user.displayName;
		  const email = user.email;
		  const photoURL = user.photoURL;
		  const phoneNumber = user.phoneNumber;
		  const isAnonymous = user.isAnonymous;
		  const uid = user.uid;
		  console.log('displayName :>> ', displayName);
		  console.log('email :>> ', email);
		  console.log('photoURL :>> ', photoURL);
		  console.log('phoneNumber :>> ', phoneNumber);
		  console.log('isAnonymous :>> ', isAnonymous);
		  console.log('uid :>> ', uid);
		} else {
			console.log("No user signed in");
		}
	  });


	const inputEmail = document.querySelector("#inputEmail");
	const inputPassword = document.querySelector("#inputPassword");

	document.querySelector("#signOutButton").onclick = (event) => {
		firebase.auth().signOut().then(function() {
			console.log("Sign Out Successful");
		  }).catch(function(error) {
			console.log("Sign Out Error");
		  });
	}
	document.querySelector("#createAccountButton").onclick = (event) => {
		console.log("Create account for email");

		firebase.auth().createUserWithEmailAndPassword(inputEmail.value, inputPassword.value).catch(function(error) {
			// Handle Errors here.
			var errorCode = error.code;
			var errorMessage = error.message;
			console.log("Create Account error", errorCode, errorMessage);
			// ...
		  });
	}
	document.querySelector("#loginButton").onclick = (event) => {
		console.log("Login for " + inputEmail.value + " " + inputPassword.value);

		firebase.auth().signInWithEmailAndPassword(inputEmail.value, inputPassword.value).catch(function(error) {
			// Handle Errors here.
			var errorCode = error.code;
			var errorMessage = error.message;
			console.log("Existing account login error", errorCode, errorMessage);
		  });
	}

	document.querySelector("#anonymousAuthButton").onclick = (event) => {
		firebase.auth().signInAnonymously().catch(function (error) { 
			var errorCode = error.code;
			var errorMessage = error.message;
			console.log("Anonymous auth error", errorCode, errorMessage);
		})
	}

	rhit.startFirebaseUI();

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

rhit.main();
