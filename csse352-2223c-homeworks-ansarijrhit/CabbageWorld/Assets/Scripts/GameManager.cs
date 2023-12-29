using System.Collections;
using System.Collections.Generic;
using TMPro;
using UnityEngine;
using UnityEngine.SceneManagement;

public class GameManager : Singleton<GameManager>
{

	[SerializeField] GameObject badgerPrefab, mainMenuButton;
	[SerializeField] TextMeshProUGUI scoreText, eatenDwarvesText, cabbagesRemainingText;
	GameObject badger;
	private CabbageManager cm;
	private DwarfManager dm;
	private SnakeManager sm;

	private int eatenDwarves = 0;
	private int timeSurvived = 0;
	private int finalScore = 0;

	// Start is called before the first frame update
	void Start()
	{
		badger = Instantiate(badgerPrefab);
		cm = FindObjectOfType<CabbageManager>();
		dm = FindObjectOfType<DwarfManager>();
		sm = FindObjectOfType<SnakeManager>();
		if (HomeScreenManager.tutorial)
		{
			print("Hello");
			StartTutorial();
		}
	}

	// Update is called once per frame
	void Update()
	{
		if (badger == null)
		{
			badger = Instantiate(badgerPrefab);
		}
		timeSurvived += 1;
	}

	public GameObject GetBadger()
	{
		return badger;
	}

	public Vector3 NearestCabbagePosition(Vector3 currentPos)
	{
		return cm.NearestCabbagePosition(currentPos);
	}

	public void BadgerEatsDwarf(GameObject dwarf)
	{
		badger.GetComponent<BadgerMovement>().IncreaseSpeed();
		eatenDwarves++;
		eatenDwarvesText.text = "Dwarves Eaten: " + eatenDwarves;
		Destroy(dwarf);
		if (eatenDwarves % 5 == 0)
		{
			sm.SpawnSnake();
		}
	}

	public void DwarfEatsCabbage(GameObject dwarf, GameObject cabbage)
	{
		dwarf.GetComponent<DwarfMovement>().BeginNap();
		cm.ConsumeCabbage(cabbage);
		badger.GetComponent<BadgerMovement>().DecreaseSpeed();
		cabbagesRemainingText.text = cm.GetCabbagesRemaining() + " cabbages remaining";

		if (cm.GetCabbagesRemaining() == 0)
		{
			badger.GetComponent<BadgerMovement>().speed = 0f;
			dm.DwarvesSuccess();
			sm.DwarvesSuccess();
			finalScore = timeSurvived * eatenDwarves;
			scoreText.gameObject.SetActive(true);
			scoreText.text = "Final score:\n" + finalScore;
			mainMenuButton.gameObject.SetActive(true);
			Debug.Log("You ate " + eatenDwarves + " dwarves before they got to your cabbages.");
		}
	}

	public void LoadMainScreen()
	{
		Destroy(gameObject);
		SceneManager.LoadScene("Main Menu");
	}

	private float badgerSpeed = 0f;

	public void Pause()
	{
		print("Paused");
		dm.PauseMovement();
		badgerSpeed = badger.GetComponent<BadgerMovement>().speed;
		badger.GetComponent<BadgerMovement>().speed = 0f;
	}

	public void Unpause(bool justPlayer)
	{
		if (!justPlayer)
		{
			dm.UnpauseMovement();
		}
		print(badgerSpeed);
		badger.GetComponent<BadgerMovement>().speed = badgerSpeed;
	}

	private void StartTutorial()
	{
		Pause();
		EventBus.Subscribe(EventBus.EventType.EndTutorial, EndTutorial);
	}

	private void EndTutorial()
	{
		Unpause(false);
	}
}
