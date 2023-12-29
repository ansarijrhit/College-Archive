using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.SceneManagement;

public class HomeScreenManager : MonoBehaviour
{

	public static bool tutorial = false;

    // Start is called before the first frame update
    void Start()
    {
        
    }

    // Update is called once per frame
    void Update()
    {
        
    }

	public void LoadFirstLevel()
	{
		SceneManager.LoadScene("Game");
	}

	public void LoadTutorial()
	{
		tutorial = true;
		SceneManager.LoadScene("Game");
	}
}
