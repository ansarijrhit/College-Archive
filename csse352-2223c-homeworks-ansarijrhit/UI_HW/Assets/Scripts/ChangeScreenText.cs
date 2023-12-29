using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using TMPro;

public class ChangeScreenText : MonoBehaviour
{
    TMP_Text text;
    // Start is called before the first frame update
    void Start()
    {
        text = GetComponent<TMP_Text>();
        text.text = "Value: 0";
    }

    // Update is called once per frame
    void Update()
    {
        
    }

    public void SetValue(TMP_Dropdown change) {

        text.text = "New Value: " + change.value.ToString();
    }
}
