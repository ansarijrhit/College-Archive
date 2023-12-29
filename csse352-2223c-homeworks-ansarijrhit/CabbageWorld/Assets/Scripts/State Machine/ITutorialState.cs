using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public interface ITutorialState
{
	void Handle(TutorialFSM context);

	void SetupUI(UISetter setter);

	void NextTutorialState();
}
