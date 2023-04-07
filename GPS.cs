using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public class GPS : MonoBehaviour
{
    // Public variable to reference the Text UI element for displaying coordinates
    public Text coordinatesText;

    // Base origin coordinates
    public float baseLatitude;
    public float baseLongitude;
    //public float baseAltitude;
    public const float R = 6371000f;

    // Update is called once per frame
    void Update()
    {
        // Get the XYZ position of the game object
        Vector3 position = transform.position;

        // Convert the XYZ position to GPS coordinates based on the base origin
       // float lat = Mathf.Asin(position.z/R);
       // float lon = Mathf.Atan2(position.y, position.x);
        
        
       float x = (position.x - baseLongitude) * Mathf.Cos((baseLatitude + position.y)/2);
       float y = (position.y - baseLatitude);
        float d = Mathf.Sqrt(x*x + y*y) * R;
        

        

        // Format the Unity coordinates as a string
        string unityCoordinatesString = string.Format("Unity Coordinates\nX: {0}\nY: {1}\nZ: {2}", position.x, position.y, position.z);

        // Format the GPS coordinates as a string
        string gpsCoordinatesString = string.Format("GPS Coordinates\nLatitude: {0}\nLongitude: {1}\nD: {2}", y, x, d);

        // Combine the Unity and GPS coordinates strings
        string coordinatesString = unityCoordinatesString + "\n\n" + gpsCoordinatesString;

        // Update the Text UI element with the combined coordinates string
        coordinatesText.text = coordinatesString;
    }
}
