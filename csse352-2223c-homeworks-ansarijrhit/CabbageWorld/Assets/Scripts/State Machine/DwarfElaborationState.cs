using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class DwarfElaborationState : MonoBehaviour, ITutorialState
{
	// References for transitions
	SnakeInformationState _nextState;
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
		setter.SetTitle("Dwarves (cont.)");
		setter.SetTextPanel("Fend off the dwarves by moving the badger over to them. They will try to run away, but" +
			" you're faster! If you reach them, you will eat the dwarf and gain a 10% speed increase.");
		setter.SetButtonText("Defend!");

		EventBus.Subscribe(EventBus.EventType.NextTutorial, NextTutorialState);
		_isUISetup = true;
		this.setter = setter;
	}

	bool playerMoving = false;
	public void NextTutorialState()
	{
		EventBus.Unsubscribe(EventBus.EventType.NextTutorial, NextTutorialState);
		GetComponent<GameManager>().Unpause(false);
		this.setter.SetInactive();
		playerMoving = true;
	}

	float timeElapsed = 0f;
	IEnumerator MovementTimer()
	{
		timeElapsed += Time.deltaTime;
		yield return null;
		if (timeElapsed > 7f && playerMoving)
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
		Debug.Log("Starting up Dwarf Continued state");
		_nextState = GetComponent<SnakeInformationState>();
		if (_nextState == null)
		{
			_nextState = gameObject.AddComponent<SnakeInformationState>();
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
