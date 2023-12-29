using System;
using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class IntroState : MonoBehaviour, ITutorialState
{
	// References for transitions
	FirstExplanationState _nextState;
	TutorialFSM _fsm;
	private bool _isUISetup = false;

	public void Handle(TutorialFSM context)
	{
		if (!_isUISetup) { 
			SetupUI(context.StateUIPrefab.GetComponent<UISetter>());
		}
	}

	public void SetupUI(UISetter setter)
	{
		setter.SetTitle("Welcome to Cabbage World!");
		setter.SetTextPanel("This is a 10/10 game (per IGN) developed by Jordan Ansari, where you play as a harmless" +
			" badger just trying to defend your cabbages from the dwarves.");

		setter.SetButtonBus(EventBus.EventType.NextTutorial);
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
		Debug.Log("Starting up Beginning state");
		_nextState = GetComponent<FirstExplanationState>();
		if (_nextState == null)
		{
			_nextState = gameObject.AddComponent<FirstExplanationState>();
		}
		_fsm = GetComponent<TutorialFSM>();
		if (_fsm == null)
		{
			_fsm = gameObject.AddComponent<TutorialFSM>();
		}
	}
}
