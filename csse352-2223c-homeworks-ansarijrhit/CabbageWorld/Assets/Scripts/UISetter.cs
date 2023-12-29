using System.Collections;
using System.Collections.Generic;
using TMPro;
using UnityEngine;
using UnityEngine.SceneManagement;
using UnityEngine.UI;
using UnityEngine.UIElements;
using Image = UnityEngine.UIElements.Image;

public class UISetter : MonoBehaviour
{
	[SerializeField] UnityEngine.UI.Button _nextButton;
	[SerializeField] TMP_Text _title;
	[SerializeField] TMP_Text _text_panel;

	// Start is called before the first frame update
	void Start()
	{
	}

	// Update is called once per frame
	void Update()
	{
	}

	public void SetButtonBus(EventBus.EventType eventType)
	{
		_nextButton.onClick.AddListener(() => { EventBus.Publish(eventType); });
	}

	public void SetButtonText(string text)
	{
		_nextButton.GetComponentInChildren<TextMeshProUGUI>().SetText(text);
	}

	public void SetTitle(string title)
	{
		_title.text = title;
	}

	public void SetTextPanel(string information)
	{
		_text_panel.text = information;
	}

	public void SetInactive()
	{
		gameObject.SetActive(false);
	}

	public void SetActive()
	{
		gameObject.SetActive(true);
	}
}
