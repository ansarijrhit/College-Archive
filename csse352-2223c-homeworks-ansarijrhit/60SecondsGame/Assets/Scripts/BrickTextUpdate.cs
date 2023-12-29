using System.Collections;
using System.Collections.Generic;
using TMPro;
using UnityEngine;

public class BrickTextUpdate : MonoBehaviour
{
	TMP_Text text;
	// Start is called before the first frame update
	void Start()
	{
		text = GetComponent<TMP_Text>();
	}

	// Update is called once per frame
	void Update()
	{
		text.text = GameManager.Instance.bricksDestroyed + "/" + GameManager.Instance.GetTotalBricks() + " Bricks Destroyed\nSpeed: " + 
			GameManager.Instance.playerSpeed + "\nBomb Radius: " + GameManager.Instance.bombRadius;
	}
}
