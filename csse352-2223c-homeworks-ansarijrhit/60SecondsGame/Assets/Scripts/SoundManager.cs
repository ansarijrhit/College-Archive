using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class SoundManager : MonoBehaviour
{

	[SerializeField] AudioClip explosionSound;
	private AudioSource audioSource;

	// Start is called before the first frame update
	void Start()
	{
		audioSource = GetComponent<AudioSource>();
		EventBus.Subscribe(EventBus.EventType.BombExploded, playExplosionSound);
    }

   private void playExplosionSound()
	{
		audioSource.PlayOneShot(explosionSound);
	}
}
