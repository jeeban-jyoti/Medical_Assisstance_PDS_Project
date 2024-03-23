#include<stdio.h>
int main()
{
    printf("\n************************************************PDS PROJECT**********************************************");
    printf("\n********************************************MEDICAL ASSISTANCE*******************************************");
    printf("\n  Welcome to our Medical Assistance Project mainly for students and even for many other citizens who\nare new to any area or dont know about the local medical shops, doctors and hospitals and need contacts \n                           and addresses urgently at the time of any emergency");
    printf("\n\n**************************************************MADE BY************************************************");
    printf("\n                                        JEEBAN JYOTI PATRA(23CS01026)                                    ");
    printf("\n                                           SHATADEEP DE(23CE01052)                                       ");
    printf("\n                                           ADITYAA SAHA(23CS01002)                                       ");
    printf("\n                                          NILABJA MONDAL(23MM02008)                                      ");
    int choice;
    int i=1;
    while(i!=0)
    {
        printf("\n Choices:");
        printf("\n 1 for Search for Doctors, Medical shops and Hospitals\n 2 for Your recent Searches\n 3 for Exit\n Enter your choice:");
        scanf("%d",&choice);
        switch(choice){
            case 1:
            printf("\n You are redirected to search page-->");
            break;
            case 2:
            printf("\n Your Search History is Here-->");
            break;
            case 3:
            printf("\n Exit");
            i=0;
            break;
            default:
            printf("\n Wrong Entry. Enter you choice again");
        }

    }
    return 0;

}