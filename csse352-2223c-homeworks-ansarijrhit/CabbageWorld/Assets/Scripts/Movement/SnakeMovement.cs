using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using static UnityEditor.FilePathAttribute;

public class SnakeMovement : MonoBehaviour
{
	private Rigidbody2D body;
	private CapsuleCollider2D capsule;

	private bool seesBadger = false;
	private bool runningAway = false;
	private int rotationDirection = 1;
	// Start is called before the first frame update
	void Start()
    {
		body = GetComponent<Rigidbody2D>();
		capsule = GetComponent<CapsuleCollider2D>();
	}

    // Update is called once per frame
    void Update()
    {
		if (runningAway)
		{
			body.velocity = Quaternion.AngleAxis(transform.eulerAngles.z + 90, Vector3.forward) * new Vector3(13f, 0, 0);
			body.angularVelocity = 0;
		}
		else
		{
			RaycastHit2D[] hits = new RaycastHit2D[10];
			// Look in front of the snake
			int rayHits = capsule.Raycast(Quaternion.AngleAxis(transform.eulerAngles.z + 90, Vector3.forward) * new Vector3(100f, 0, 0), hits);
			Debug.DrawRay(transform.position, Quaternion.AngleAxis(transform.eulerAngles.z + 90, Vector3.forward) * new Vector3(100f, 0, 0));
			if (rayHits > 0)
			{
				for (int i = 0; i < hits.Length; i++)
				{
					if (hits[i].collider != null && hits[i].collider.gameObject.name.Contains("Badger"))
					{
						seesBadger = true;
					}
				}
			}


			if (seesBadger)
			{
				body.drag = 10f;
				body.angularVelocity = 0;
				body.velocity = Quaternion.AngleAxis(transform.eulerAngles.z + 90, Vector3.forward) * new Vector3(13f, 0, 0);
				StartCoroutine(ShootForward());
			}
			else
			{
				body.velocity = new Vector3(0f, 0f, 0f);
				body.drag = 0;
				body.angularVelocity = rotationDirection * 70f;
			}
		}
	}
	private IEnumerator ShootForward()
	{
		rotationDirection = (Random.Range(0, 2) * 2 - 1);
		float moveTimer = 0.5f;

		//Debug.Log("Starting wander towards " + direction.ToString());

		while (moveTimer > 0)
		{
			moveTimer -= Time.deltaTime;
			yield return null; // Go through while loop once, pause, come back next frame when Update is called again
		}
		seesBadger = false;
	}

	public void RunAway()
	{
		runningAway = true;
	}
}
