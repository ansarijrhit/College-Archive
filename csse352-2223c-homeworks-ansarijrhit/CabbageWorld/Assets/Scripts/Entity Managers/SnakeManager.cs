using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class SnakeManager : MonoBehaviour
{

	[SerializeField] GameObject snakePrefab;

	public void DwarvesSuccess()
	{
		foreach (SnakeMovement sm in FindObjectsOfType<SnakeMovement>())
		{
			sm.RunAway();
		}
	}

	public void SpawnSnake()
	{
		int spawnSide = Random.Range(0, 4);
		Vector3 spawnPos = new Vector3();
		switch (spawnSide)
		{
			// Above camera
			case 0:
				spawnPos = new Vector3(Random.Range(-10f, 10f), Random.Range(5f, 7f), 0);
				break;
			// Right of camera
			case 1:
				spawnPos = new Vector3(Random.Range(10f, 15f), Random.Range(-5f, 5f), 0);
				break;
			// Beneath camera
			case 2:
				spawnPos = new Vector3(Random.Range(-10f, 10f), Random.Range(-5f, -7f), 0);
				break;
			// Left of camera
			case 3:
				spawnPos = new Vector3(Random.Range(-10f, -15f), Random.Range(-5f, 5f), 0);
				break;
		}
		Instantiate(snakePrefab, spawnPos, Quaternion.identity);
	}
}