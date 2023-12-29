using System;
using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class MailboxData : MonoBehaviour
{
	private bool mailPlaced = false;

	public void PlaceMail()
	{
		if (!mailPlaced)
		{
			mailPlaced = true;
			EventBus.Publish(EventBus.EventType.MailPlaced);
		}
	}
}
