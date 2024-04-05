#include "FileOperations.c"

void callSearch(){
    // Find the current address
    char output[100];
    char input[100];
    char lonlat[2][20];
    FILE *fp;

    // Prompt the user to enter a string
    fgets(input, sizeof(input), stdin);
    printf("Enter the name of the place: ");
    fgets(input, sizeof(input), stdin);

    // Remove newline character from the input
    input[strcspn(input, "\n")] = '\0';
    appendToFile(input);

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

        for(int i = 0; i < strlen(output) && i < 19;i++){
            if(output[i] == '\0' || output[i] == '\n'){
                continue;
            }
            lonlat[c][i] = output[i];
        }
        c++;
    }

    // Close the pipe
    pclose(fp);
    printf("%s\n", lonlat[0]);
    printf("%s\n", lonlat[1]);

    // Find nearest hospitals
    find_nearest_hospitals(lonlat[0],lonlat[1]);
}

void callHistory(){
    while(1){
        int lines = readFromFile(), opt;
        printf("0. Exit\n\n\n");

        printf("Enter the number for which you want to search the hospitals data again, or enter 0 to exit: ");
        scanf("%d", &opt);

        if(opt < 0 || opt > lines){
            printf("enter any valid input.\n");
            continue;
        }
        if(opt == 0){
            break;
        }

        readSpecificLineFromFile(opt);
        printf("\n\n");
    }
}

int main(){
    printf("\n************************************************PDS PROJECT**********************************************");
    printf("\n********************************************MEDICAL ASSISTANCE*******************************************\n");
    printf("\n  Welcome to our Medical Assistance Project mainly for students and even for many other citizens who\nare new to any area or dont know about the local hospitals and need contacts \n                           and addresses urgently at the time of any emergency");
    printf("\n\n**************************************************MADE BY************************************************\n");
    printf("\n                                        JEEBAN JYOTI PATRA(23CS01026)                                    ");
    printf("\n                                           SHATADEEP DE(23CE01052)                                       ");
    printf("\n                                           ADITYAA SAHA(23CS01002)                                       ");
    printf("\n                                          NILABJA MANDAL(23MM02008)                                      ");
    printf("\n\n*********************************************************************************************************\n");

    int choice;
    int i = 1;
    while (i != 0){
        printf("\n Choices:");
        printf("\n 1 for Search for Hospitals\n 2 for Your recent Searches\n 0 for Exit\n Enter your choice:");
        scanf("%d", &choice);

        switch (choice){
            case 0:
                printf("\n Exit\n");
                i = 0;
                break;
            case 1:
                callSearch();
                break;
            case 2:
                callHistory();
                break;
            default:
                printf("\n Wrong Entry. Enter you choice again");
        }
    }
    return 0;
}
