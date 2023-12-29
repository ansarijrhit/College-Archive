using System.Collections;
using System.Collections.Generic;
using TMPro;
using UnityEngine;
using static UnityEditor.FilePathAttribute;

public class DwarfManager : MonoBehaviour
{
	private bool dwarfSpawn = true;
	private bool stopAllSpawn = false;

	[SerializeField] GameObject dwarfPrefab;

    // Start is called before the first frame update
    void Start()
    {
	}

    // Update is called once per frame
    void Update()
    {
		if (dwarfSpawn && !stopAllSpawn)
		{
			StartCoroutine(SpawnCoroutine());
		} else
		{
			StopCoroutine(SpawnCoroutine());
		}
    }

	private IEnumerator SpawnCoroutine()
	{
		float spawnTimer = Random.Range(3f, 5f);
		dwarfSpawn = false;

		int spawnSide = Random.Range(0, 4);
		Vector3 spawnPos = new Vector3();
		switch (spawnSide)
		{
			// Above camera
			case 0:
				spawnPos = new Vector3(Random.Range(-10f, 10f), Random.Range(5.5f, 7f), 0);
				break;
			// Right of camera
			case 1:
				spawnPos = new Vector3(Random.Range(10.5f, 15f), Random.Range(-5f, 5f), 0);
				break;
			// Beneath camera
			case 2:
				spawnPos = new Vector3(Random.Range(-10f, 10f), Random.Range(-5.5f, -7f), 0);
				break;
			// Left of camera
			case 3:
				spawnPos = new Vector3(Random.Range(-10.5f, -15f), Random.Range(-5f, 5f), 0);
				break;
		}
		Instantiate(dwarfPrefab, spawnPos, Quaternion.identity);


		while (spawnTimer > 0)
		{
			spawnTimer -= Time.deltaTime;
			yield return null; // Go through while loop once, pause, come back next frame when Update is called again
		}

		//Debug.Log("Ending wander towards " + direction.ToString());
		dwarfSpawn = true;
	}

	public void DwarvesSuccess()
	{
		stopAllSpawn = true;

		foreach (DwarfMovement dm in FindObjectsOfType<DwarfMovement>())
		{
			dm.RunAway();
		}
	}

	public void PauseMovement()
	{
		stopAllSpawn = true;
		foreach (DwarfMovement dm in FindObjectsOfType<DwarfMovement>())
		{
			dm.speed = 0f;
		}
	}

	public void UnpauseMovement()
	{
		stopAllSpawn = false;
		foreach (DwarfMovement dm in FindObjectsOfType<DwarfMovement>())
		{
			dm.speed = 2.5f;
		}
	}
}
