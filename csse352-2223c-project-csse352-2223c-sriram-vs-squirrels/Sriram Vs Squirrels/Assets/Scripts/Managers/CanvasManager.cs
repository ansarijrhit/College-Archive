using System;
using System.Collections;
using System.Collections.Generic;
using TMPro;
using UnityEngine;
using UnityEngine.UI;

public class CanvasManager : MonoBehaviour
{

	[SerializeField] GameObject blackScreen;
	[SerializeField] GameObject textbox;
	[SerializeField] GameObject tryAgainButton;
	[SerializeField] GameObject nextLevelButton;
	[SerializeField] GameObject mainMenuButton;
	[SerializeField] GameObject deliveredText;
	[SerializeField] GameObject mailboxLocationsText;

	private int totalGrades = 0, gradesDelivered = 0;


	// Start is called before the first frame update
	void Start()
    {
		EventBus.Subscribe(EventBus.EventType.PlayerEaten, EatenFade);
		EventBus.Subscribe(EventBus.EventType.LevelComplete, LevelEndFade);
		EventBus.Subscribe(EventBus.EventType.MailPlaced, updateMailDelivered);
	}

	public void SetTotalGrades(int totalGrades)
	{
		this.totalGrades = totalGrades;
		deliveredText.GetComponent<TMP_Text>().text = "Grades Delivered: 0/" + totalGrades;
	}

	private void updateMailDelivered()
	{
		gradesDelivered++;
		deliveredText.GetComponent<TMP_Text>().text = "Grades Delivered: " + gradesDelivered + "/" + totalGrades;
	}

	private void EatenFade()
	{
		gradesDelivered = 0;
		deliveredText.SetActive(false);
		StartCoroutine(Fade(text: "Sriram was eaten...", after: setDeathButtonsActive));
	}

	private void LevelEndFade()
	{
		gradesDelivered = 0;
		deliveredText.SetActive(false);
		StartCoroutine(Fade(text: "Sriram survived...", after: setNextLevelButtonsActive));
	}

	public void GameEndFade()
	{
		StopAllCoroutines();
		gradesDelivered = 0;
		deliveredText.SetActive(false);
		StartCoroutine(Fade(text: "You Win", after: setMainMenuButtonActive));
	}

	public void FadeOut()
	{
		textbox.SetActive(false);
		tryAgainButton.SetActive(false);
		nextLevelButton.SetActive(false);
		mainMenuButton.SetActive(false);
		deliveredText.SetActive(true);
		StartCoroutine(Fade(false));
	}

	private IEnumerator Fade(bool fadeOut = true, string text = "", Action after = null)
	{
		Color color = blackScreen.GetComponent<Image>().color;
		float fadeAmount;
		if (fadeOut)
		{
			while (color.a < 1)
			{
				fadeAmount = color.a + (6 * Time.deltaTime);
				color = new Color(0, 0, 0, fadeAmount);
				blackScreen.GetComponent<Image>().color = color;
				yield return null;
			}
			StartCoroutine(typeTextbox(textbox, text, after));
		}
		else
		{
			while (color.a > 0)
			{
				fadeAmount = color.a - (10 * Time.deltaTime);
				color = new Color(0, 0, 0, fadeAmount);
				blackScreen.GetComponent<Image>().color = color;
				yield return null;
			}
		}
	}

	private IEnumerator typeTextbox(GameObject textBox, string text, Action after)
	{
		textBox.SetActive(true);
		textBox.GetComponent<TMP_Text>().text = "";
		for (int i = 0; i < text.Length; i++)
		{
			textBox.GetComponent<TMP_Text>().text += text[i];
			if (text[i] == ' ')
			{
				yield return new WaitForSeconds(0.5f);
			}
			else
			{
				yield return new WaitForSeconds(0.2f);
			}
		}
		yield return new WaitForSeconds(0.5f);
		if (after != null)
		{
			after();
		}
	}

	private void setDeathButtonsActive()
	{ 
		tryAgainButton.SetActive(true);
		mainMenuButton.SetActive(true);
	}

	private void setNextLevelButtonsActive()
	{
		nextLevelButton.SetActive(true);
		mainMenuButton.SetActive(true);
	}

	private void setMainMenuButtonActive()
	{
		mainMenuButton.SetActive(true);
	}

	public void SetMailboxLocationsText(string locationsString)
	{
		string[] locations = locationsString.Split(',');
		string builtString = "Mailbox Locations:\n";
		for (int i = 0; i < locations.Length; i++)
		{
			builtString += locations[i] + "\n";
		}
		mailboxLocationsText.GetComponent<TMP_Text>().text = builtString;
	}

	public void Pause()
	{
		StartCoroutine(Fade());
		mailboxLocationsText.SetActive(true);
		mainMenuButton.SetActive(true);
	}

	public void Unpause()
	{
		StartCoroutine(Fade(false));
		mailboxLocationsText.SetActive(false);
		mainMenuButton.SetActive(false);
	}
}
