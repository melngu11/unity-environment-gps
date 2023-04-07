using System.Collections;
using System.Collections.Generic;
using UnityEngine;


public class MoveCube : MonoBehaviour
{
    // The speed at which the cube moves
    public float moveSpeed = 5f;

    void Update()
    {
        // Get the user's input
        float horizontal = Input.GetAxis("Horizontal");
        float vertical = Input.GetAxis("Vertical");

        // Calculate the movement direction
        Vector3 movement = new Vector3(horizontal, 0f, vertical).normalized;

        // Move the cube based on the movement direction and speed
        transform.position += movement * moveSpeed * Time.deltaTime;

        if (Input.GetKey(KeyCode.Space))
        {
            transform.Translate(Vector3.up * moveSpeed * Time.deltaTime);
        }
        else if (Input.GetKey(KeyCode.LeftControl) || Input.GetKey(KeyCode.RightControl))
        {
            transform.Translate(Vector3.down * moveSpeed * Time.deltaTime);
        }
    }
}

