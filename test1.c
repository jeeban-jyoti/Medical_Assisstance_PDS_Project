#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h> // for sending HTTP requests

// Callback function to handle response data
size_t write_callback(char *ptr, size_t size, size_t nmemb, char *data) {
    strcat(data, ptr);
    return size * nmemb;
}

// Function to find the latitude and longitude of a place using OpenStreetMap Nominatim API
void find_location(const char *place_name) {
    
}

int main() {
    const char *place_name = "dukura,odisha"; // Example place name
    find_location(place_name);
    return 0;
}
