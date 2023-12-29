/**
 * @fileoverview
 * Provides interactions for all pages in the UI.
 *
 * @author
 */

/** namespace. */
var rh = rh || {};

/** globals */

rh.FamilyMember = class {
    constructor(name, imageUrl) {
    	this.name = name;
    	this.imageUrl = imageUrl;
    }
}

rh.FbFamilyMemberManager = class {
    constructor() {
        this.members = [
            // A prepopulated list of family members, to get things started:
            new rh.FamilyMember('Dad', 'images/dad.jpg'),
            new rh.FamilyMember('Mom', 'images/mom.jpg'),
            new rh.FamilyMember('McKinley', 'images/girl.jpg'),
            new rh.FamilyMember('Bobby', 'images/boy.jpg'),
            new rh.FamilyMember('Rover', 'images/dog.jpg')
        ];
    }

    get length() {
        return this.members.length;
    }

    getFamilyMemberAtIndex(index) {
      return this.members[index];
    }

    add(name, imageUrl) {
        console.log("Attempting to save ", name);
        return new Promise((resolve, reject) => {
            let theWork = () => {
                if( name == "" || imageUrl == "" ) {
                  reject("Invalid form data! Please correct it and try again");
                  console.log("Failure! Invalid data!");
                } else {
                  let didItWork = Math.random() >= 0.5;
                  if (didItWork) {
                      let newMember = new rh.FamilyMember(name, imageUrl);
                      this.members.push(newMember);
                      resolve(newMember);
                      console.log("Success!")
                  } else {
                      reject("There was an error creating that person. Please try again!");
                      console.log("Failure! Bad luck ;)");
                  }
                }
            }
            setTimeout(theWork, 500, name, imageUrl);
        })
    }
};

rh.ListPageController = class {
    constructor() {
        let formSubmitted = (event) => {
            /*
             Instructions:
             * Remove any error messages from `#errors` which may have been added from failed adds (read below)
             * Call `rh.fbFamilyMemberManager.add` with the appropriate values from the form
                * `rh.fbFamilyMemberManager.add` returns a Promise
                * The Promise will simulate whether the person was succesfully saved or not.
             * If the person was added succesfully:
                * Blank out the name input
                * Return the picture input to its default value
                * Calls `updateView` to show the new family member
             * If there was an error adding the person:
                * Add the error message from the promise to "#errors"
                * Do not reset the picture input
                * Do not reset the name input
            */

            //Problems: I couldn't figure out how to get the correct error message to display, and it was displaying
            //an error whether or not the addition succeeded. Also, the view does not update unless "Submit" is pressed twice.
           
            const nameInput = document.querySelector("#nameInput");
            const pictureInput = document.querySelector("#pictureInput");
            const errors = document.querySelector("#errors");
            errors.innerHTML = "";

            var promise = rh.fbFamilyMemberManager.add(nameInput.value, pictureInput.value);
            promise.then(() => {
                nameInput.value = "";
                pictureInput.value = "";
                this.updateView();
            })
            .catch(function (error) {
                errors.innerHTML = "" + error;
                return;
            })
            // promise.catch();

        }

        

        document.querySelector("#submit").addEventListener("click", formSubmitted);
        this.updateView();
    }

    
    clearForm = (nameInput, pictureInput) => {
        
        this.updateView();
    }

    updateView() {
        console.log("Update the family on the page.");
        $("#familyList").removeAttr("id").hide();
        let $familyList = $(`<div id="familyList" class="row justify-content-center">`);
        for (let k = 0; k < rh.fbFamilyMemberManager.length; k++) {
            console.log("rendering ", rh.fbFamilyMemberManager.getFamilyMemberAtIndex(k));
            const familyMember = rh.fbFamilyMemberManager.getFamilyMemberAtIndex(k);
            const $newCard = $(`
    			<div class="col-3 col-md-2">
    			<img src="${familyMember.imageUrl}" class="img-fluid" alt="${familyMember.name}">
    			<div class="text-center">${familyMember.name}</div>
    			</div>
            `);
            $newCard.click((event) => {
                console.log("Deleting " + familyMember);
                /*
                 Instructions:
                 * Implement the delete functionality, using proper OO techniques.
                   This means that you'll be writing some code here, and some code
                   elsewhere.
                 */

                 rh.fbFamilyMemberManager.members.splice(k, 1);
                 this.updateView();
                // TODO: Add your modifications here
            })
            $familyList.append($newCard);
        }
        $("#familyListContainer").append($familyList);
    }
};

/* Main */
$(document).ready(function () {
    rh.fbFamilyMemberManager = new rh.FbFamilyMemberManager();
    new rh.ListPageController();
});

