#include <stdio.h>
#include <string.h>


void savemobileNumber(const char *name, const char *phoneNumber);
void searchmobileNumber(const char *name);

int main() {
    char option;
    char name[50];
    char phoneNumber[12];
    
    while (1) {
        printf("Choose any one  option:\n");
        printf("1. Save you Name plz....\n");
        printf("2. Save you phone number plz....\n");
        printf("3. Search phone number \n");
        printf("4. Search name \n");
        printf("5. Exit\n");
        printf("Option: ");
        scanf(" %c", &option);

        switch (option) {
            case '1':
                printf("Enter name: ");
                scanf(" %[^\n]", name);
                printf("Enter phone number: ");
                scanf(" %[^\n]", phoneNumber);
                savemobileNumber(name, phoneNumber);
                break;
            case '2':
                printf("Enter Phone Number: ");
                scanf(" %[^\n]", phoneNumber);
                printf("Enter Name: ");
                scanf(" %[^\n]", name);
                savemobileNumber(phoneNumber, name);
                break;
            case '3': 
                printf("Enter name to search: ");
                scanf(" %[^\n]", name);
                searchmobileNumber(name);
                break;
            case '4':
                printf("Enter number: ");
                scanf(" %[^\n]", phoneNumber);
                searchmobileNumber(phoneNumber);
                break;
            case '5':
                printf("Exiting program.\n");
                return 0;
            default:
                printf("Invalid option. Try again.\n");
        }
    }
    return 0;
}

    void savemobileNumber(const char *name, const char *phoneNumber) {
    FILE *file = fopen("demo.txt", "a");
    if (file != NULL) {
        fprintf(file, "%s,%s\n", name, phoneNumber);
        fclose(file);
        printf("Phone number saved successfully!\n");
    } else {
        printf("Error opening file.\n");
    }
}

void searchmobileNumber(const char *name) {
    char temp[256];
    FILE *file = fopen("demo.txt", "r");
    if (file != NULL) {
        while (fgets(temp, sizeof(temp), file) != NULL) {
            char savedname[50];
            char savedmobilenumber[20];

            sscanf(temp, "%[^,],%s", savedname, savedmobilenumber);

            if (strcmp(savedname, name) == 0) {
                printf("Phone number for %s: %s\n", name, savedmobilenumber);
                fclose(file);
                return;
            }
        }
        printf("Phone number not found for %s.\n", name);
        fclose(file);
    } else {
        printf("Error opening file.\n");
    }
}












/*
#include<stdio.h>
#include<string.h>
#define MAX_PHONE_LENGTH 20
#define Max_name_LENGTH 50


void savePhoneNumber(char* phoneNumber, char* name);
void searchPhoneNumber(char* phoneNumber);


int main(){

    char phoneNumber[MAX_PHONE_LENGTH];
    char name[Max_name_LENGTH];

    printf("Enter your Name to Save: ");
    scanf("%s", &name);
    printf("Enter your Phone Number to Save: ");
    scanf("%s", &phoneNumber);
    savePhoneNumber(&phoneNumber,&name);
    printf("Successfully! add Your Number\n");
    

  printf("Enter the name you want to search: ");

    scanf("%s %s", name, phoneNumber);
    searchPhoneNumber(&phoneNumber);

    return 0;
}
void savePhoneNumber(char* phoneNumber,char* name) {
    FILE* file = fopen("demo.txt", "a");
    if (file == NULL) {
        printf("Error opening file!\n");
        return;
    }
    fprintf(file, "%s ",name);
    fprintf(file, "%s\n",phoneNumber);
    fclose(file);
}
void searchPhoneNumber(char* phoneNumber) {
    FILE* file = fopen("demo.txt", "r");
    if (file == NULL) {
        printf("Error opening file!\n");
        return;
    }
    char line[MAX_PHONE_LENGTH];
    int found = 0;

    while (fgets(line, sizeof(line), file)) {
        line[strcspn(line, "\n")] = '\0';

        if (strcmp(line, phoneNumber) == 0) {
            printf("Phone number found: %s\n", phoneNumber);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Phone number not found!\n");
    }

    fclose(file);
}


*/

/*
#include<stdio.h>
void main()
{
    struct Serch
    {
        int number;
        char name[50];
    };

    struct Serch s1;

       int number, flag = 0;
       FILE *fp;
       fp = fopen("demo.txt", "rb");

       if(fp == NULL)
       {
           printf("File can not open"); 
       }
           printf("Enter the name if you Search :- ");
           scanf("%d", &number);

           while (fread(&s1, sizeof(s1), 1, fp)>0 && flag == 0)
           {
              if (s1.number == number)
              {
                flag = 1;
                printf("Number is Found \n");
                printf("%d %s", s1.number, s1.name);
              }
            }
           if(flag == 0)
        {
            printf("Not found");
        }
            fclose(fp);
           
}
*/