using System.Collections;
using System.Collections.Generic;
using UnityEngine;

[CreateAssetMenu(fileName = "level", menuName = "Level")]
public class LevelInfo : ScriptableObject
{
	public int playerX, playerY;
	public float maxCameraX, maxCameraY, minCameraX, minCameraY;
	public MultiDimensionalInt[] squirrelSpawns;
	public GameObject tilemap;
	public string MailLocations;
}
