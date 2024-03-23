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
void find_nearest_hospitals(char * latitude, char * longitude) {
    CURL *curl;
    CURLcode res;
    char overpass_url[] = "http://overpass-api.de/api/interpreter";
    char overpass_query[1024];
    char response_data[102400] = ""; // Buffer to store response data

    int radius;
    printf("enter radius: ");
    scanf("%d", &radius);

    // Initialize libcurl
    curl = curl_easy_init();
    if (curl) {
        // Construct Overpass query to find hospitals within a radius of 5km
        sprintf(overpass_query, "[out:json];node['amenity'='hospital'](around:%d,%s,%s);out;",radius, latitude, longitude);

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

    // Find the current address
    FILE *fp;
    char output[100];
    char input[100];
    char lonlat[2][20];

    // Prompt the user to enter a string
    printf("Enter a string: ");
    fgets(input, sizeof(input), stdin);

    // Remove newline character from the input
    input[strcspn(input, "\n")] = '\0';

    // Construct the command to execute the Python script with the input argument
    char command[200];
    sprintf(command, "python location_finder.py \"%s\"", input);

    // Open a pipe to execute the command and read its output
    fp = popen(command, "r");
    if (fp == NULL) {
        fprintf(stderr, "Failed to open pipe.\n");
    }

    // Read the output of the Python script
    int c = 0;
    while (fgets(output, sizeof(output), fp) != NULL) {
        printf("%s", output);

        for(int i = 0; i < strlen(output) && i < 19;i++){
            lonlat[c][i] = output[i];
        }

        lonlat[c][19] = '\0';
        c++;
    }

    // Close the pipe
    pclose(fp);

    // Find nearest hospitals
    find_nearest_hospitals(lonlat[0],lonlat[1]);

    return 0;
}