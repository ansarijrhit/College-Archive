using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class SoundManager : MonoBehaviour
{
	[SerializeField] AudioClip spottedSound;
	[SerializeField] AudioClip eatenSound;
	private AudioSource audioSource;

	// Start is called before the first frame update
	void Start()
	{
		audioSource = GetComponent<AudioSource>();
		EventBus.Subscribe(EventBus.EventType.PlayerSpotted, playSpottedSound);
		EventBus.Subscribe(EventBus.EventType.PlayerEaten, playEatenSound);
	}

	public void StartMusic()
	{
		audioSource.Play();
	}

	public bool paused = false;
	private bool playingSpotted = false;

	private void playSpottedSound()
	{
		if (!playingSpotted && !paused)
		{
			audioSource.PlayOneShot(spottedSound);
			playingSpotted = true;
			StartCoroutine(spottedDelayCoroutine());
		}
	}

	private IEnumerator spottedDelayCoroutine()
	{
		yield return new WaitForSeconds(7.5f);
		playingSpotted = false;
	}

	private void playEatenSound()
	{
		audioSource.Stop();
		audioSource.PlayOneShot(eatenSound);
	}
}
