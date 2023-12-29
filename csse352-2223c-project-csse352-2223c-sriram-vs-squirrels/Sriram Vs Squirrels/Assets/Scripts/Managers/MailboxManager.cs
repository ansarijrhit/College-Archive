using SuperTiled2Unity;
using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class MailboxManager : MonoBehaviour
{
	SuperObject[] mailboxes;

	private int filledMailboxes = 0;

	public int InstantiateMailboxes()
	{
		EventBus.Subscribe(EventBus.EventType.PlayerEaten, resetFilled);
		EventBus.Subscribe(EventBus.EventType.LevelComplete, resetFilled);
		EventBus.Subscribe(EventBus.EventType.MailPlaced, incrementFilled);
		mailboxes = FindObjectOfType<Grid>().transform.Find("Mailboxes/").gameObject.GetComponentsInChildren<SuperObject>();
		for (int i = 0; i < mailboxes.Length; i++)
		{
			mailboxes[i].gameObject.AddComponent<MailboxData>();
		}
		return mailboxes.Length;
	}

	private void resetFilled()
	{
		filledMailboxes = 0;
	}

	private void incrementFilled()
	{
		filledMailboxes++;
		if (filledMailboxes == mailboxes.Length) 
		{
			print("All filled");
			filledMailboxes = 0;
			EventBus.Publish(EventBus.EventType.LevelComplete);
			EventBus.Unsubscribe(EventBus.EventType.MailPlaced, incrementFilled);
		}
	}
}
