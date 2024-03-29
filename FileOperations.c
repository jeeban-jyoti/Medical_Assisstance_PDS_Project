#include "hospital_data_fetcher.c"

int appendToFile(const char *text) {
    FILE *file;

    // Open the file in append mode
    file = fopen("search_list.txt", "a");

    if (file == NULL) {
        printf("File could not be opened.");
        return -1;
    }

    // Append the text to the file
    fprintf(file, "%s\n", text);

    // Close the file
    fclose(file);

    return 0;
}

int readFromFile() {
    FILE *file;
    char line[1000]; // Assuming maximum line length is 1000 characters
    int lineNumber = 1;

    // Open the file in read mode
    file = fopen("search_list.txt", "r");

    if (file == NULL) {
        printf("File could not be opened.");
        return -1;
    }

    // Read line by line and print line number before each line
    while (fgets(line, sizeof(line), file)) {
        printf("%d. %s", lineNumber, line);
        lineNumber++;
    }

    // Close the file
    fclose(file);

    return lineNumber;
}

void readSpecificLineFromFile(int LINE_NUMBER) {
    FILE *file, *fp;
    char line[1000]; // Assuming maximum line length is 1000 characters
    char output[100];
    char lonlat[2][20];
    int lineNumber = 1;

    // Open the file in read mode
    file = fopen("search_list.txt", "r");

    if (file == NULL) {
        printf("File could not be opened.");
        return;
    }

    // Read line by line and print line number before each line
    while (fgets(line, sizeof(line), file)) {
        if(lineNumber == LINE_NUMBER){
            printf("%d. %s", lineNumber, line);
            break;
        }
        lineNumber++;
    }

    // Close the file
    fclose(file);

    // Construct the command to execute the Python script with the input argument
    printf("\n\n\n%s\n\n\n", line);
    char command[200];
    sprintf(command, "python location_finder.py \"%s\"", line);

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
}