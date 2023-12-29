using System.Collections;
using System.Collections.Generic;
//using System.Numerics;
using UnityEngine;

public class CabbageManager : MonoBehaviour
{

	public int cabbageCount = 6;
	private int cabbagesRemaining;

	private GameObject[] cabbages;

	[SerializeField] GameObject cabbagePrefab;

    // Start is called before the first frame update
    void Start()
    {
		cabbagesRemaining = cabbageCount;
		cabbages = new GameObject[cabbageCount];
		for (int i = 0; i < cabbages.Length; i++)
		{
			// Determine the angle by which the spawning should increment
			float angle = 360f / cabbages.Length;
			// First the location is just straight right between 1 and 4 units
			Vector3 location = new Vector3(Random.Range(1f,4f), 0, 0);
			// Rotate it around the Z axis by a random amount (but close to the angle)
			location = Quaternion.AngleAxis(Random.Range(angle-10, angle+10) * i, Vector3.forward) * location;
			// Modify the x distance
			location = new Vector3(Random.Range(0.7f, 3f) * location.x, location.y, 0);
			cabbages[i] = Instantiate(cabbagePrefab, location, Quaternion.identity);
		}
    }

    // Update is called once per frame
    void Update()
    {
        
    }

	public void ConsumeCabbage(GameObject cabbage)
	{
		Destroy(cabbage);
		cabbagesRemaining--;
	}

	public Vector3 NearestCabbagePosition(Vector3 to)
	{
		Vector3 nearest = new Vector3(float.MaxValue, float.MaxValue, 0);
		for (int i = 0; i < cabbages.Length; i++)
		{
			if (cabbages[i] != null && Vector3.Distance(nearest, to) > Vector3.Distance(cabbages[i].transform.position, to))
			{
				nearest = cabbages[i].transform.position;
			}
		}
		return nearest;
	}

	public int GetCabbageCount()
	{
		return cabbageCount;
	}

	public int GetCabbagesRemaining()
	{
		return cabbagesRemaining;
	}
}
