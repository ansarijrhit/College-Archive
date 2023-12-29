using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class BombBehavior : MonoBehaviour
{
	// Start is called before the first frame update
	void Start()
    {
		Destroy(gameObject, this.GetComponent<Animator>().GetCurrentAnimatorStateInfo(0).length);
		EventBus.Subscribe(EventBus.EventType.BombExploded, explode);
    }

	private void explode()
	{
		Collider2D[] hitColliders = Physics2D.OverlapCircleAll(gameObject.transform.position, GameManager.Instance.bombRadius);
		foreach (var hitCollider in hitColliders)
		{
			if (hitCollider.name == "Wall")
			{
				GameManager.Instance.bricksDestroyed++;
				Destroy(hitCollider.gameObject);
			}
		}
	}
}
