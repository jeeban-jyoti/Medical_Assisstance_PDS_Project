#include <stdio.h>

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

int readSpecificLineFromFile(int LINE_NUMBER) {
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