using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class ControlsButton : MonoBehaviour
{
	[SerializeField] GameObject tutorialWindow;
    public void OpenTutorial()
	{
		tutorialWindow.SetActive(true);
	}

	public void CloseTutorial()
	{
		tutorialWindow.SetActive(false);
	}
}
