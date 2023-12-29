using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class DwarfMovement : MonoBehaviour
{
	public float speed = 2.5f;

	private Rigidbody2D body;
	private BoxCollider2D square;

	private GameManager gm;

	private bool napping;
	private bool runningAway = false;
	private Vector3 randomRunAway;

	// Start is called before the first frame update
	void Start()
	{
		body = GetComponent<Rigidbody2D>();
		square = GetComponent<BoxCollider2D>();
		gm = FindObjectOfType<GameManager>();
		randomRunAway = new Vector3(Random.Range(-1f, 1f), Random.Range(-1f, 1f), 0f);
	}

	private float sightDistance = 2f;

    // Update is called once per frame
    void Update()
    {
		if (runningAway)
		{
			body.velocity = randomRunAway * Random.Range(1f, 3f) * speed;
		}
		else if (napping)
		{
			StartCoroutine(Nap());
		}
		else
		{
			// This could all be done in one line, but it's easier to read this way.
			Vector3 currentPos = transform.position;
			Vector3 nearestPos = gm.NearestCabbagePosition(currentPos);
			Vector3 direction = nearestPos - currentPos;


			float playerDistance = Vector3.Distance(transform.position, gm.GetBadger().transform.position);

			if (playerDistance <= sightDistance)
			{
				Vector3 moveAway = transform.position - gm.GetBadger().transform.position;
				body.velocity = (direction.normalized + moveAway.normalized) * speed;
			} else
			{
				body.velocity = direction.normalized * speed;
			}
		}
	}

	public void RunAway()
	{
		runningAway = true;
	}

	public void BeginNap()
	{
		napping = true;
	}

	private IEnumerator Nap()
	{
		float napTimer = 1f;
		body.velocity = new Vector3(0, 0, 0);

		//Debug.Log("Starting wander towards " + direction.ToString());

		while (napTimer > 0)
		{
			napTimer -= Time.deltaTime;
			yield return null; // Go through while loop once, pause, come back next frame when Update is called again
		}
		napping = false;
	}
}
