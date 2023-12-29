using System;
using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class SriramMovement : MonoBehaviour
{
	public float speed = 4.5f;

	private Rigidbody2D bean;

	private CapsuleCollider2D capsule;

	Animator anim;

	// Start is called before the first frame update
	void Start()
	{
		bean = GetComponent<Rigidbody2D>();
		capsule = GetComponent<CapsuleCollider2D>();
		anim = GetComponent<Animator>();
	}

	// Update is called once per frame
	void Update()
	{
		float dX = Input.GetAxis("Horizontal") * speed;
		float dY = Input.GetAxis("Vertical") * speed;
		Vector2 movement = new Vector2(dX, dY);
		bean.velocity = movement;


		anim.SetFloat("Horizontal", movement.x);
		anim.SetFloat("Vertical", movement.y);


		if (speed > 0 && (Math.Abs(Input.GetAxisRaw("Horizontal")) == 1 || Math.Abs(Input.GetAxisRaw("Vertical")) == 1))
		{
			anim.SetFloat("Last Horizontal", Input.GetAxisRaw("Horizontal"));
			anim.SetFloat("Last Vertical", Input.GetAxisRaw("Vertical"));
		}
	}
}
