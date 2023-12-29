using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class SnakeInformationState : MonoBehaviour, ITutorialState
{

	// References for transitions
	FinalInformationState _nextState;
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
		setter.SetTitle("Snakes");
		setter.SetTextPanel("Snakes spawn for every 5 dwarves you've eaten. They spin in place until you pass within their" +
			" line of sight, at which point they charge forward! If you get hit, you slow down. If dwarves get hit, they're eaten.");
		setter.SetButtonText("Continue");

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
		Debug.Log("Starting up Dwarf Continued state");
		_nextState = GetComponent<FinalInformationState>();
		if (_nextState == null)
		{
			_nextState = gameObject.AddComponent<FinalInformationState>();
		}
		_fsm = GetComponent<TutorialFSM>();
		if (_fsm == null)
		{
			_fsm = gameObject.AddComponent<TutorialFSM>();
		}

	}
}
