using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class SquirrelEatPlayer : MonoBehaviour
{
	private void OnCollisionEnter2D(Collision2D collision)
	{
		if (collision.gameObject.name.Contains("Sriram"))
		{
			EventBus.Publish(EventBus.EventType.PlayerEaten);
		}
	}
}
