using System;
using System.Collections;
using System.Collections.Generic;
using System.Text;
using UnityEditor;
using UnityEngine;
using UnityEngine.U2D;

public class MazeSpawner : MonoBehaviour
{

	[SerializeField] SpriteAtlas atlas;
	[SerializeField] GameObject mazeBrickPrefab;
	private Sprite[] sprites = new Sprite[16];
	private int[,] maze;
	private int dimension = 20;

	public int totalBricks = 0;
		
	private Stack<Node> stack = new Stack<Node>();
	private System.Random rand = new System.Random();

	// Start is called before the first frame update
	void Start()
    {
		atlas.GetSprites(sprites);

	}

	public void createMaze()
	{
		maze = new int[dimension, dimension];
		generateMaze();
		for (int i = 0; i < dimension; i++)
		{
			for (int j = 0; j < dimension; j++)
			{
				Vector2 spawnPos = new Vector2((float)(i - (dimension / 2)) * 0.7f, (float)(j - (dimension / 2)) * 0.7f);
				GameObject floor = Instantiate(mazeBrickPrefab, spawnPos, Quaternion.identity);
				floor.transform.parent = gameObject.transform;
				floor.GetComponent<SpriteRenderer>().sprite = atlas.GetSprite("Light Wood 1");
				floor.GetComponent<SpriteRenderer>().sortingOrder = -1;
				Destroy(floor.GetComponent<BoxCollider2D>());
				floor.name = "Floor";

				if (maze[i, j] == 1)
				{
					GameObject brick = Instantiate(mazeBrickPrefab, spawnPos, Quaternion.identity);
					brick.transform.parent = gameObject.transform;
					brick.GetComponent<SpriteRenderer>().sprite = atlas.GetSprite("Dark Brick 1");
					totalBricks++;
					brick.name = "Wall";
				}
			}
		}

		// Red border walls
		for (int i = -1; i <= dimension; i++)
		{
			Vector2 spawnPos1 = new Vector2((float)(i - (dimension / 2)) * 0.7f, (float)(-1 - (dimension / 2)) * 0.7f);
			Vector2 spawnPos2 = new Vector2((float)(i - (dimension / 2)) * 0.7f, (float)(dimension - (dimension / 2)) * 0.7f);
			Vector2 spawnPos3 = new Vector2((float)(-1 - (dimension / 2)) * 0.7f, (float)(i - (dimension / 2)) * 0.7f);
			Vector2 spawnPos4 = new Vector2((float)(dimension - (dimension / 2)) * 0.7f, (float)(i - (dimension / 2)) * 0.7f);
			GameObject brick1 = Instantiate(mazeBrickPrefab, spawnPos1, Quaternion.identity);
			GameObject brick2 = Instantiate(mazeBrickPrefab, spawnPos2, Quaternion.identity);
			GameObject brick3 = Instantiate(mazeBrickPrefab, spawnPos3, Quaternion.identity);
			GameObject brick4 = Instantiate(mazeBrickPrefab, spawnPos4, Quaternion.identity);
			brick1.transform.parent = gameObject.transform;
			brick2.transform.parent = gameObject.transform;
			brick3.transform.parent = gameObject.transform;
			brick4.transform.parent = gameObject.transform;
			brick1.GetComponent<SpriteRenderer>().sprite = atlas.GetSprite("Red Brick 1");
			brick2.GetComponent<SpriteRenderer>().sprite = atlas.GetSprite("Red Brick 1");
			brick3.GetComponent<SpriteRenderer>().sprite = atlas.GetSprite("Red Brick 1");
			brick4.GetComponent<SpriteRenderer>().sprite = atlas.GetSprite("Red Brick 1");
		}
	}

	private void generateMaze()
	{
		stack.Push(new Node(0, 0));
		while (stack.Count != 0)
		{
			Node next = stack.Pop();
			if (validNextNode(next))
			{
				maze[next.y,next.x] = 1;
				List<Node> neighbors = findNeighbors(next);
				randomlyAddNodesToStack(neighbors);
			}
		}
		// Clear out the middle
		for (int i = -1; i <= 1; i++)
		{
			for (int j = -1; j <= 1; j++)
			{
				maze[(dimension / 2) + i, (dimension / 2) + j] = 0;
			}
		}
	}

	public String getSymbolicMaze()
	{
		StringBuilder sb = new StringBuilder();
		for (int i = 0; i < dimension; i++)
		{
			for (int j = 0; j < dimension; j++)
			{
				sb.Append(maze[i,j] == 1 ? "*" : " ");
				sb.Append("  ");
			}
			sb.Append("\n");
		}
		return sb.ToString();
	}

	private bool validNextNode(Node node)
	{
		int numNeighboringOnes = 0;
		for (int y = node.y - 1; y < node.y + 2; y++)
		{
			for (int x = node.x - 1; x < node.x + 2; x++)
			{
				if (pointOnGrid(x, y) && pointNotNode(node, x, y) && maze[y,x] == 1)
				{
					numNeighboringOnes++;
				}
			}
		}
		return (numNeighboringOnes < 3) && maze[node.y,node.x] != 1;
	}

	private void randomlyAddNodesToStack(List<Node> nodes)
	{
		int targetIndex;
		while (nodes.Count != 0)
		{
			targetIndex = rand.Next(nodes.Count);
			stack.Push(nodes[targetIndex]);
			nodes.RemoveAt(targetIndex);
		}
	}

	private List<Node> findNeighbors(Node node)
	{
		List<Node> neighbors = new List<Node>();
		for (int y = node.y - 1; y < node.y + 2; y++)
		{
			for (int x = node.x - 1; x < node.x + 2; x++)
			{
				if (pointOnGrid(x, y) && pointNotCorner(node, x, y)
					&& pointNotNode(node, x, y))
				{
					neighbors.Add(new Node(x, y));
				}
			}
		}
		return neighbors;
	}

	private Boolean pointOnGrid(int x, int y)
	{
		return x >= 0 && y >= 0 && x < dimension && y < dimension;
	}

	private Boolean pointNotCorner(Node node, int x, int y)
	{
		return (x == node.x || y == node.y);
	}

	private Boolean pointNotNode(Node node, int x, int y)
	{
		return !(x == node.x && y == node.y);
	}

}

public class Node
{
	public int x;
	public int y;

	public Node(int x, int y)
	{
		this.x = x;
		this.y = y;
	}
}