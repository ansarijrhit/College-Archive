using System.Collections;
using System.Linq;
using System.Collections.Generic;
using UnityEngine;

public class SquirrelManager : Singleton<SquirrelManager>
{
	[SerializeField] GameObject squirrelPrefab;

	List<GameObject> squirrels = new List<GameObject>();

	public void InstantiateSquirrels(MultiDimensionalInt[] squirrelPositions)
	{
		for (int i = 0; i < squirrelPositions.Length; i++)
		{
			GameObject squirrel = Instantiate(squirrelPrefab);
			squirrel.transform.position = new Vector2(squirrelPositions[i].intArray[0], squirrelPositions[i].intArray[1]);
			squirrels.Add(squirrel);
		}
	}

	public void FreezeSquirrels()
	{
		for (int i = 0; i < squirrels.Count; i++)
		{
			squirrels[i].GetComponent<SquirrelMovement>().speed = 0f;
		}
	}

	public void UnfreezeSquirrels()
	{
		for (int i = 0; i < squirrels.Count; i++)
		{
			squirrels[i].GetComponent<SquirrelMovement>().speed = 2.5f;
		}
	}

	public void DestroySquirrels()
	{
		for (int i = 0; i < squirrels.Count; i++)
		{
			Destroy(squirrels[i]);
		}
		squirrels.Clear();
	}
}
