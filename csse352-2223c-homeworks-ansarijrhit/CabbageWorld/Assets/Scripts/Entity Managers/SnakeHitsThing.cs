using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class SnakeHitsThing : MonoBehaviour
{
	private void OnCollisionEnter2D(Collision2D collision)
	{
		string collisionName = collision.gameObject.name;
		if (collisionName.Contains("Dwarf"))
		{
			Destroy(collision.gameObject);
		}
		else if (collisionName.Contains("Badger"))
		{
			collision.gameObject.GetComponent<BadgerMovement>().DecreaseSpeed();
		}
	}
}
