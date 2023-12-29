using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.SceneManagement;

public class GameManager : Singleton<GameManager>
{
	[SerializeField] GameObject playerPrefab;
	GameObject player;
	[SerializeField] GameObject bombPrefab;
	[SerializeField] GameObject spawner;
	GameObject mazeSpawner;
	[SerializeField] UnityEngine.UI.Image timerFill;

	private int duration = 60, remainingDuration;

	public int bricksDestroyed;

	public float playerSpeed = 1.5f;
	public float bombRadius = 0.3f;

	public int GetTotalBricks()
	{
		if (mazeSpawner == null)
		{
			return 0;
		}
		return mazeSpawner.GetComponent<MazeSpawner>().totalBricks;
	}

	// Start is called before the first frame update
	void Start()
    {
		EventBus.Subscribe(EventBus.EventType.BombPlaced, placeBomb);
		EventBus.Subscribe(EventBus.EventType.PlayerKilled, endLoop);
		newLoop();
    }

	private void placeBomb()
	{
		Vector2 spawnPos = player.transform.position;
		Instantiate(bombPrefab, spawnPos, Quaternion.identity);
	}

	private void newLoop()
	{
		remainingDuration = duration;
		StartCoroutine(countdown());
		mazeSpawner = Instantiate(spawner);
		mazeSpawner.GetComponent<MazeSpawner>().createMaze();
		player = Instantiate(playerPrefab);
	}

	IEnumerator countdown()
	{
		while (remainingDuration > 0)
		{
			timerFill.fillAmount = Mathf.InverseLerp(0, duration, remainingDuration);
			remainingDuration--;
			yield return new WaitForSeconds(1f);
		}
		endLoop();
	}

	private void endLoop()
	{
		if (bricksDestroyed == GetTotalBricks())
		{
			SceneManager.LoadScene("Main Menu");
			print("You won!");
			return;
		}
		else if (bricksDestroyed >= GetTotalBricks() / 4)
		{
			playerSpeed *= 1.50f;
			if (bricksDestroyed >= GetTotalBricks() / 2)
			{
				bombRadius *= 1.50f;
			}
		}
		bricksDestroyed = 0;
		Destroy(player);
		Destroy(mazeSpawner);
		StopCoroutine(countdown());
		newLoop();
	}
}
