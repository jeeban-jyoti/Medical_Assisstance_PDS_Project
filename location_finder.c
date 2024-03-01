#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h> // for sending HTTP requests

// Callback function to handle response data
size_t write_callback(char *ptr, size_t size, size_t nmemb, char *data) {
    strcat(data, ptr);
    return size * nmemb;
}

// Function to find nearest hospitals using OpenStreetMap Overpass API
void find_nearest_hospitals(double latitude, double longitude) {
    CURL *curl;
    CURLcode res;
    char overpass_url[] = "http://overpass-api.de/api/interpreter";
    char overpass_query[1024];
    char response_data[102400] = ""; // Buffer to store response data

    // Initialize libcurl
    curl = curl_easy_init();
    if (curl) {
        // Construct Overpass query to find hospitals within a radius of 5km
        sprintf(overpass_query, "[out:json];node['amenity'='hospital'](around:5000,%f,%f);out;", latitude, longitude);

        // Set the URL
        curl_easy_setopt(curl, CURLOPT_URL, overpass_url);

        // Set the POST data (Overpass query)
        curl_easy_setopt(curl, CURLOPT_POSTFIELDS, overpass_query);

        // Set the write callback function to handle response data
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_callback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, response_data);

        // Perform the request
        res = curl_easy_perform(curl);
        if (res != CURLE_OK) {
            fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res));
        } else {
            printf("Response received:\n%s\n", response_data); // Print the received JSON response
        }

        // Cleanup
        curl_easy_cleanup(curl);
    } else {
        fprintf(stderr, "Failed to initialize libcurl\n");
    }
}

int main() {
    double latitude, longitude;

    // Assuming latitude and longitude are known or obtained from GPS
    latitude = 20.353293;  // Example latitude (New York City)
    longitude = 85.810526;  // Example longitude (New York City)

    // Find nearest hospitals
    find_nearest_hospitals(latitude, longitude);

    return 0;
}
