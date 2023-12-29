using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class DwarfHitsThing : MonoBehaviour
{
	private void OnCollisionEnter2D(Collision2D collision)
	{
		GameManager gm = FindObjectOfType<GameManager>();
		string collisionName = collision.gameObject.name;
		if (collisionName.Contains("Cabbage"))
		{
			gm.DwarfEatsCabbage(gameObject, collision.gameObject);
		} else if (collisionName.Contains("Badger"))
		{
			gm.BadgerEatsDwarf(gameObject);
		}
	}
}
