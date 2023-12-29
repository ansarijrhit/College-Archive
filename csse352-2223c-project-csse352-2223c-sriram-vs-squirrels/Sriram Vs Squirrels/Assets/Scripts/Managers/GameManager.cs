using System;
using System.Collections;
using System.Collections.Generic;
using System.IO;
using UnityEditor;
using UnityEngine;
using UnityEngine.SceneManagement;

public class GameManager : Singleton<GameManager>
{
	[SerializeField] GameObject playerPrefab;
	GameObject player;
	[SerializeField] LevelInfo[] levelInfo;
	[SerializeField] CanvasManager canvasManager;
	[SerializeField] SquirrelManager squirrelManager;
	MailboxManager mailboxManager;
	[SerializeField] SoundManager soundManager;

	GameObject tileMap;

	private int currentLevel = 0;
	private bool sriramDead = false;

	// Start is called before the first frame update
	void Start()
	{
		if (canvasManager == null)
		{
			canvasManager = FindObjectOfType<Canvas>().GetComponent<CanvasManager>();
		}
		if (squirrelManager == null)
		{
			squirrelManager = FindObjectOfType<SquirrelManager>();
		}
		if (soundManager == null)
		{
			soundManager = FindObjectOfType<SoundManager>();
		}
		mailboxManager = GetComponent<MailboxManager>();
		EventBus.Subscribe(EventBus.EventType.PlayerEaten, PlayerDeath);
		EventBus.Subscribe(EventBus.EventType.LevelComplete, EndLevel);
		SetupLevel();
	}

	public void SetupLevel()
	{
		// Setup tilemap
		if (tileMap != null)
		{
			Destroy(tileMap);
		}
		tileMap = Instantiate(levelInfo[currentLevel].tilemap);
		tileMap.transform.position = new Vector2(0, 0);
		tileMap.transform.localScale = new Vector2(11.72f, 11.72f);

		// Setup Player
		sriramDead = false;
		Destroy(player);
		player = Instantiate(playerPrefab);
		player.GetComponent<SriramMovement>().speed = 4.5f;
		player.transform.position = new Vector2(levelInfo[currentLevel].playerX, levelInfo[currentLevel].playerY);

		// Set camera bounds
		player.GetComponentInChildren<Camera>().GetComponent<CameraClamp>().SetBounds(levelInfo[currentLevel].minCameraX, levelInfo[currentLevel].minCameraY, 
			levelInfo[currentLevel].maxCameraX, levelInfo[currentLevel].maxCameraY);

		// Spawn squirrels
		squirrelManager.InstantiateSquirrels(levelInfo[currentLevel].squirrelSpawns);

		// Instantiate Mailboxes
		int totalMailboxes = mailboxManager.InstantiateMailboxes();

		// Setup Canvas
		canvasManager.FadeOut();
		canvasManager.SetTotalGrades(totalMailboxes);
		canvasManager.SetMailboxLocationsText(levelInfo[currentLevel].MailLocations);

		soundManager.StartMusic();
	}

	private bool paused = false;

	private void Update()
	{
		if (Input.GetKeyDown(KeyCode.Escape) && !sriramDead)
		{
			paused = !paused;
			if (paused)
			{
				Pause();
			}
			else
			{
				Unpause();
			}
		}
		//if (Input.GetKeyDown(KeyCode.Return))
		//{
		//	EventBus.Publish(EventBus.EventType.LevelComplete);
		//}
	}

	public GameObject GetPlayer()
	{
		return player;
	}

	public void PlayerDeath()
	{
		sriramDead = true;
		squirrelManager.DestroySquirrels();
		player.GetComponent<SriramMovement>().speed = 0f;
	}

	public void EndLevel()
	{
		sriramDead = true;
		squirrelManager.DestroySquirrels();
		player.GetComponent<SriramMovement>().speed = 0f;
		if (currentLevel == levelInfo.Length - 1)
		{
			canvasManager.GameEndFade();
		}
	}

	public void NextLevel()
	{
		currentLevel++;
		SetupLevel();
	}

	public void Pause()
	{
		squirrelManager.FreezeSquirrels();
		player.GetComponent<SriramMovement>().speed = 0f;
		soundManager.paused = true;
		canvasManager.Pause();
	}

	public void Unpause()
	{
		squirrelManager.UnfreezeSquirrels();
		player.GetComponent<SriramMovement>().speed = 4.5f;
		soundManager.paused = false;
		canvasManager.Unpause();
	}

	public void MainMenu()
	{
		Destroy(gameObject);
		SceneManager.LoadScene("Main Menu");
	}
}
