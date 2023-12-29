using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class DwarfIntroState : MonoBehaviour, ITutorialState
{
	// References for transitions
	DwarfElaborationState _nextState;
	TutorialFSM _fsm;
	private bool _isUISetup = false;

	public void Handle(TutorialFSM context)
	{
		if (!_isUISetup)
		{
			SetupUI(context.StateUIPrefab.GetComponent<UISetter>());
		}
	}

	public void SetupUI(UISetter setter)
	{
		setter.SetTitle("Dwarves");
		setter.SetTextPanel("Dwarves are represented by brown squares. The dwarves will make a beeline" +
			" towards your cabbages and eat them if they reach one. Once eating one, they will take a 1-second nap.");
		setter.SetButtonText("Next");

		EventBus.Subscribe(EventBus.EventType.NextTutorial, NextTutorialState);
		_isUISetup = true;
	}

	public void NextTutorialState()
	{
		EventBus.Unsubscribe(EventBus.EventType.NextTutorial, NextTutorialState);
		_fsm.SetNextState(_nextState);
	}

	// Start is called before the first frame update
	void Start()
	{
		Debug.Log("Starting up Dwarf Explanation state");
		_nextState = GetComponent<DwarfElaborationState>();
		if (_nextState == null)
		{
			_nextState = gameObject.AddComponent<DwarfElaborationState>();
		}
		_fsm = GetComponent<TutorialFSM>();
		if (_fsm == null)
		{
			_fsm = gameObject.AddComponent<TutorialFSM>();
		}

	}
}
