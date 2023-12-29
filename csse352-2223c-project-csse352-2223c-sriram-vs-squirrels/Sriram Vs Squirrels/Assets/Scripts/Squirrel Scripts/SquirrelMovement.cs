using System.Collections;
using System.Collections.Generic;
using System.Text.RegularExpressions;
using UnityEngine;

public class SquirrelMovement : MonoBehaviour
{

	enum MoveType { Left, Right, Up, Down, Idle }
	[SerializeField] private MoveType currentMoveType;


	public float speed = 2.5f;

	private Rigidbody2D body;
	private BoxCollider2D box;

	private bool finishedWander = true;

	private float lastHorizontal = 0f;
	private float lastVertical = 0f;
	Vector3 facing = Vector3.down;

	//EnemySoundManager soundManager;

	Animator anim;

	// Start is called before the first frame update
	void Start()
	{
		body = GetComponent<Rigidbody2D>();
		box = GetComponent<BoxCollider2D>();
		anim = GetComponent<Animator>();
	}

	// Update is called once per frame
	void Update()
	{
		Seek();
	}

	MoveType WanderDirection(MoveType direction)
	{
		float horizontal = 0f;
		float vertical = 0f;
		MoveType oppositeDirection = MoveType.Idle;
		switch (direction)
		{
			case MoveType.Up:
				facing = Vector3.up;
				oppositeDirection = MoveType.Down;
				vertical = 1f;
				break;
			case MoveType.Down:
				facing = Vector3.down;
				oppositeDirection = MoveType.Up;
				vertical = -1f;
				break;
			case MoveType.Left:
				facing = Vector3.left;
				oppositeDirection = MoveType.Right;
				horizontal = -1f;
				break;
			case MoveType.Right:
				facing = Vector3.right;
				oppositeDirection = MoveType.Left;
				horizontal = 1f;
				break;
			case MoveType.Idle:
				break;
		}

		RaycastHit2D[] hits = new RaycastHit2D[1];

		int rayHits = box.Raycast(facing, hits, facing.magnitude);
		Debug.DrawRay(transform.position, facing, Color.white);
		if (rayHits == 1)
		{
			horizontal *= -1f;
			vertical *= -1f;
			direction = oppositeDirection;
			facing *= -1f;
		}

		Vector2 movement = new Vector2(speed * horizontal, speed * vertical);
		body.velocity = movement;

		anim.SetFloat("Horizontal", movement.x);
		anim.SetFloat("Vertical", movement.y);
		return direction;
	}

	void WanderRandom()
	{
		if (finishedWander)
		{
			float rand = Random.Range(0f, 1f);
			if (rand < 0.1)
			{
				lastHorizontal = 0f;
				lastVertical = 1f;
				StartCoroutine(WanderCoroutine(MoveType.Up));
			}
			else if (rand < 0.2)
			{
				lastHorizontal = 0f;
				lastVertical = -1f;
				StartCoroutine(WanderCoroutine(MoveType.Down));
			}
			else if (rand < 0.3)
			{
				lastHorizontal = -1f;
				lastVertical = 0f;
				StartCoroutine(WanderCoroutine(MoveType.Left));
			}
			else if (rand < 0.4)
			{
				lastHorizontal = 1f;
				lastVertical = 0f;
				StartCoroutine(WanderCoroutine(MoveType.Right));
			}
			else
			{
				anim.SetFloat("LastHorizontal", lastHorizontal);
				anim.SetFloat("LastVertical", lastVertical);
				// Should be most likely to just idle in place
				StartCoroutine(WanderCoroutine(MoveType.Idle));
			}
		}
	}

	private IEnumerator WanderCoroutine(MoveType direction)
	{
		float wanderTimer = Random.Range(1f, 3f);
		finishedWander = false;

		//Debug.Log("Starting wander towards " + direction.ToString());

		while (wanderTimer > 0)
		{
			direction = WanderDirection(direction);
			wanderTimer -= Time.deltaTime;
			yield return null; // Go through while loop once, pause, come back next frame when Update is called again
		}

		//Debug.Log("Ending wander towards " + direction.ToString());
		finishedWander = true;
	}

	private float visionDistance = 15f;
	private bool lostPlayer = true;

	void Seek()
	{
		Vector3 playerPos = GameManager.Instance.GetPlayer().transform.position;
		float playerDistance = Vector3.Distance(transform.position, playerPos);
		if (playerDistance <= visionDistance)
		{
			Vector3 directionToPlayer = (playerPos - transform.position).normalized;
			float angleToPlayer = Vector3.Angle(facing, directionToPlayer);
			if (Mathf.Abs(angleToPlayer) <= 60 && speed > 0)
			{
				if (lostPlayer)
				{
					EventBus.Publish(EventBus.EventType.PlayerSpotted);
					lostPlayer = false;
				}
				finishedWander = true;
				StopAllCoroutines();
				Vector3 direction = GameManager.Instance.GetPlayer().transform.position - transform.position;
				Vector3 movement = direction.normalized * 6f;
				body.velocity = movement;
				anim.SetFloat("Horizontal", movement.x);
				anim.SetFloat("Vertical", movement.y);
				return;
			}
		}
		WanderRandom();
		lostPlayer = true;
	}
}
