using System;
using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class FirstExplanationState : MonoBehaviour, ITutorialState
{
	// References for transitions
	DwarfIntroState _nextState;
	TutorialFSM _fsm;
	private bool _isUISetup = false;
	private UISetter setter;

	public void Handle(TutorialFSM context)
	{
		if (!_isUISetup)
		{
			SetupUI(context.StateUIPrefab.GetComponent<UISetter>());
		}
	}

	public void SetupUI(UISetter setter)
	{
		setter.SetTitle("Controls");
		setter.SetTextPanel("The badger is represented by a white circle. Control its movement with W/A/S/D or the arrow keys." +
			" Try it out for yourself!");
		setter.SetButtonText("Let's go!");

		EventBus.Subscribe(EventBus.EventType.NextTutorial, NextTutorialState);
		_isUISetup = true;
		this.setter = setter;
	}

	bool playerMoving = false;

	public void NextTutorialState()
	{
		EventBus.Unsubscribe(EventBus.EventType.NextTutorial, NextTutorialState);
		GetComponent<GameManager>().Unpause(true);
		this.setter.SetInactive();
		playerMoving = true;
	}

	float timeElapsed = 0f;
	IEnumerator MovementTimer()
	{
		timeElapsed += Time.deltaTime;
		yield return null;
		if (timeElapsed > 4f && playerMoving)
		{
			this.setter.SetActive();
			GetComponent<GameManager>().Pause();
			playerMoving = false;
			_fsm.SetNextState(_nextState);
		}
	}

	// Start is called before the first frame update
	void Start()
	{
		Debug.Log("Starting up First Explanation state");
		_nextState = GetComponent<DwarfIntroState>();
		if (_nextState == null)
		{
			_nextState = gameObject.AddComponent<DwarfIntroState>();
		}
		_fsm = GetComponent<TutorialFSM>();
		if (_fsm == null)
		{
			_fsm = gameObject.AddComponent<TutorialFSM>();
		}

	}

	void Update()
	{
		if (playerMoving)
		{
			StartCoroutine(MovementTimer());
		}
	}
}
