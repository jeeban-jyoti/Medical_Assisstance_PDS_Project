#include <stdio.h>
#include "hospital_data_fetcher.c"

void callSearch(){
    // Find the current address
    char output[100];
    char input[100];
    char lonlat[2][20];
    FILE *fp;

    // Prompt the user to enter a string
    fgets(input, sizeof(input), stdin);
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
}

int main(){
    printf("\n************************************************PDS PROJECT**********************************************");
    printf("\n********************************************MEDICAL ASSISTANCE*******************************************");
    printf("\n  Welcome to our Medical Assistance Project mainly for students and even for many other citizens who\nare new to any area or dont know about the local medical shops, doctors and hospitals and need contacts \n                           and addresses urgently at the time of any emergency");
    printf("\n\n**************************************************MADE BY************************************************");
    printf("\n                                        JEEBAN JYOTI PATRA(23CS01026)                                    ");
    printf("\n                                           SHATADEEP DE(23CE01052)                                       ");
    printf("\n                                           ADITYAA SAHA(23CS01002)                                       ");
    printf("\n                                          NILABJA MONDAL(23MM02008)                                      ");
    int choice;
    int i = 1;
    while (i != 0)
    {
        printf("\n Choices:");
        printf("\n 1 for Search for Doctors, Medical shops and Hospitals\n 2 for Your recent Searches\n 3 for Exit\n Enter your choice:");
        scanf("%d", &choice);
        switch (choice){
        case 1:
            callSearch();
            break;
        case 2:
            printf("\n Your Search History is Here-->");
            break;
        case 3:
            printf("\nExit\n");
            i = 0;
            break;
        default:
            printf("\n Wrong Entry. Enter you choice again");
        }
    }
    return 0;
}