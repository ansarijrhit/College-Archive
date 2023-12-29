using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class SriramCollideWithMailbox : MonoBehaviour
{
	private void OnCollisionEnter2D(Collision2D collision)
	{
		if (collision.transform.parent != null && collision.transform.parent.gameObject.name.Contains("Mailbox"))
		{
			collision.gameObject.GetComponent<MailboxData>().PlaceMail();
		}
	}
}
