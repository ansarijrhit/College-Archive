using System.Collections;
using System.Collections.Generic;
using UnityEditor.U2D;
using UnityEngine;

public class BadgerMovement : MonoBehaviour
{

	public float speed = 4.5f;

	private Rigidbody2D bean;

	private CircleCollider2D circle;

	// Start is called before the first frame update
	void Start()
	{
		bean = GetComponent<Rigidbody2D>();
		circle = GetComponent<CircleCollider2D>();
	}

	// Update is called once per frame
	void Update()
	{
		Vector2 movement = new Vector2(Input.GetAxis("Horizontal") * speed, Input.GetAxis("Vertical") * speed);
		bean.velocity = movement;
	}

	public void IncreaseSpeed()
	{
		speed *= 1.10f;
	}

	public void DecreaseSpeed()
	{
		CabbageManager cm = FindObjectOfType<CabbageManager>();
		speed /= cm.GetCabbageCount() - cm.GetCabbagesRemaining();
	}
}
