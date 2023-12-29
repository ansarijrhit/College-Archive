using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.SceneManagement;

public class HomeScreenManager : MonoBehaviour
{

	[SerializeField] GameObject attributions;
	[SerializeField] GameObject tutorial;

	public void StartGame()
	{
		SceneManager.LoadScene("Game");
	}

	public void ShowAttributions()
	{
		attributions.SetActive(true);
	}

	public void HideAttributions()
	{
		attributions.SetActive(false);
	}

	public void ShowTutorial()
	{
		tutorial.SetActive(true);
	}

	public void HideTutorial()
	{
		tutorial.SetActive(false);
	}
}
