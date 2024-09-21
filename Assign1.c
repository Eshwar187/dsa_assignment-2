#include <stdio.h>
// Structure to store Type Details
struct Type
{
    char type_of_friend[20];
    char name_of_comman_friends[20];
    int number_of_places_visited;
};
// Structure to store Friends Details
struct Friends
{
    char name[100];
    char petName[100];
    char phoneNumber[20];
    struct Type t1; // Calling struct Type in struct Friends
};

int main()
{
    int n;
    // Input number of friend to be add
    printf("Enter the number of friends to add : ");
    scanf("%d", &n);

    struct Friends f1[n];

    // User Input Data
    for (int i = 0; i < n; i++)
    {
        printf("Enter Friend Name: ");
        scanf("%s", &f1[i].name);

        printf("Enter Pet Name: ");
        scanf("%s", &f1[i].petName);

        printf("Enter Phone Number: ");
        scanf("%s", &f1[i].phoneNumber);

        printf("Enter Type of friend: ");
        scanf("%s", &f1[i].t1.type_of_friend);

        printf("Enter Name of Common Friends: ");
        scanf("%s", &f1[i].t1.name_of_comman_friends);

        printf("Enter No. of Places Visited Together: ");
        scanf("%d", &f1[i].t1.number_of_places_visited);

        printf("\n");
    }

    // Displaying Data
    printf("\nFriends List:\n");
    printf("S.No.\tName\t\tPet Name\tPhone Number\tType of Friend\tName of common friends\tNo. of places visited together\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d\t%s\t\t%s\t\t%s\t\t%s\t\t%s\t\t\t\t%d\n", i + 1, f1[i].name,
               f1[i].petName, f1[i].phoneNumber, f1[i].t1.type_of_friend, f1[i].t1.name_of_comman_friends,
               f1[i].t1.number_of_places_visited);
    }
    return 0;
}