using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class BEANMove : MonoBehaviour
{
	public float speed = 4.5f;

	public float jumpForce = 8f;

	private Rigidbody2D bean;

	private CapsuleCollider2D capsule;

	Animator anim;

	// Start is called before the first frame update
	void Start()
	{
		speed = GameManager.Instance.playerSpeed;
		bean = GetComponent<Rigidbody2D>();
		capsule = GetComponent<CapsuleCollider2D>();
		anim = GetComponent<Animator>();
	}

	// Update is called once per frame
	void Update()
	{
		if (Input.GetKeyDown(KeyCode.Space))
		{
			EventBus.Publish(EventBus.EventType.BombPlaced);
		}

		float dX = Input.GetAxis("Horizontal") * speed;
		float dY = Input.GetAxis("Vertical") * speed;
		Vector2 movement = new Vector2(dX, dY);
		bean.velocity = movement;

		anim.SetFloat("horizontal", movement.x);
		anim.SetFloat("vertical", movement.y);
		anim.SetFloat("speed", movement.sqrMagnitude);
	}

	public void Death()
	{
		speed = 0;
		jumpForce = 0;
		anim.SetBool("PlayerDead", true);
		StartCoroutine(DeathTimer());
	}

	IEnumerator DeathTimer()
	{
		AnimatorStateInfo info = anim.GetCurrentAnimatorStateInfo(0);

		gameObject.layer = LayerMask.NameToLayer("Enemies");

		while (!info.IsName("rogue_death"))
		{
			Debug.Log("Animation not in death state yet...");
			yield return new WaitForEndOfFrame();
			info = anim.GetCurrentAnimatorStateInfo(0);
		}

		while (info.normalizedTime < 1)
		{
			yield return new WaitForEndOfFrame();
			info = anim.GetCurrentAnimatorStateInfo(0);
		}
	}
}
