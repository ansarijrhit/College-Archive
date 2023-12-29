using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class CameraClamp : MonoBehaviour
{
	// Update is called once per frame
	[SerializeField] Transform target;
	private Vector2 maxPosition;
	private Vector2 minPosition;

	public void SetBounds(float minX, float minY, float maxX, float maxY)
	{
		maxPosition = new Vector2(maxX, maxY);
		minPosition = new Vector2(minX, minY);
	}

	// LateUpdate is called after all other updates
	void LateUpdate()
	{
		if (transform.position != target.position)
		{
			Vector3 targetPosition = new Vector3(target.position.x, target.position.y, transform.position.z);
			targetPosition.x = Mathf.Clamp(targetPosition.x, minPosition.x, maxPosition.x);
			targetPosition.y = Mathf.Clamp(targetPosition.y, minPosition.y, maxPosition.y);
			transform.position = Vector3.Lerp(transform.position, targetPosition, 1);
		}
	}
}
