using System;
using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class TutorialFSM : MonoBehaviour
{

	[SerializeField] GameObject _stateUI_prefab;

	ITutorialState currentState;
	bool tutorial = false;

	public GameObject StateUIPrefab { get => _stateUI_prefab; set => _stateUI_prefab = value; }

	// Start is called before the first frame update
	void Start()
	{
		tutorial = HomeScreenManager.tutorial;
		if (tutorial)
		{
			StateUIPrefab.SetActive(true);
			currentState = GetComponent<IntroState>();
			if (currentState == null)
			{
				currentState = gameObject.AddComponent<IntroState>();
			}
		}
	}

	public void RestartTutorial(ITutorialState newState)
	{
		StateUIPrefab.SetActive(true);
		currentState = newState;
	}

	// Update is called once per frame
	void Update()
	{
		if (tutorial)
		{
			Transition();
		}
	}

	public void Transition()
	{
		currentState.Handle(this);
	}

	public void SetNextState(ITutorialState state)
	{
		currentState = state;
	}
}
