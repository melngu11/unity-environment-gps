using System.Collections;
using System.Collections.Generic;
using UnityEngine;


public class FollowTarget : MonoBehaviour
{
    // The target object to follow
    public Transform target;

    // The distance to follow the target from
    public float distance = 3f;

    // The height to follow the target from
    public float height = 5f;

    void LateUpdate()
    {
        // Calculate the camera's position based on the target object's position
        Vector3 targetPosition = target.position + Vector3.up * height - target.forward * distance;

        // Set the camera's position and look at the target object
        transform.position = targetPosition;
        transform.LookAt(target.position);
    }
}

