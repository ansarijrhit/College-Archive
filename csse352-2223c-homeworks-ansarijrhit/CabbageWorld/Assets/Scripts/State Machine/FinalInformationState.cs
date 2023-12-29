using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class FinalInformationState : MonoBehaviour, ITutorialState
{
	// References for transitions
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
		setter.SetTitle("Conclusion");
		setter.SetTextPanel("Get ready to defend your farm! If dwarves eat your cabbages, your speed decreases" +
			" proportionally to how many cabbages remain. If 0 are left, the game ends. Good luck!");
		setter.SetButtonText("Begin");
		EventBus.Subscribe(EventBus.EventType.NextTutorial, NextTutorialState);

		setter.SetButtonBus(EventBus.EventType.EndTutorial);
		_isUISetup = true;
		this.setter = setter;
	}

	public void NextTutorialState()
	{
		EventBus.Unsubscribe(EventBus.EventType.NextTutorial, NextTutorialState);
		this.setter.SetInactive();
	}

	// Start is called before the first frame update
	void Start()
	{
		Debug.Log("Starting up Final Information state");
		_fsm = GetComponent<TutorialFSM>();
		if (_fsm == null)
		{
			_fsm = gameObject.AddComponent<TutorialFSM>();
		}

	}
}
