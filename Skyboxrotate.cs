using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Skyboxrotate : MonoBehaviour
{
    // Start is called before the first frame update
    void Start()
    
        [Range(0.01f, 0.1f)]
    public float rotateSpeed;

    public Material ;

float rotationRepeatValue;

}

// Update is called once per frame
void Update()
    {

        //スカイボックスの回転速度を0.1fに対して1周分を割り出した後に余りを加算し続ける→360f到達後0.1から読み直し
        rotationRepeatValue = Mathf.Repeat(sky.GetFloat("_Rotation") + rotateSpeed, 360f);

        sky.SetFloat("_Rotation", rotationRepeatValue);

    

}
