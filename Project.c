#include<stdio.h>

int main()
{
    char name[50];
    int num_rooms, room_type, num_days;
    float cost, discount = 0;
    
    printf("Welcome to Dennis Hotel. \n");
    
    
    printf("Enter your name: ");
    scanf("%s", name);
    
    printf("Enter the number of rooms you wish to book: ");
    scanf("%d", &num_rooms);
    
    printf("Enter the room type you wish to book:\n1. VIP room (Sh.1500/day)\n2. Business class room (Sh.1000/day)\n3. Ordinary room (Sh.500/day)\n4. Special room(Includes people with disability) (Sh.350/day)\n");
    scanf("%d", &room_type);
    
    printf("Enter the number of days you wish to stay: ");
    scanf("%d", &num_days);
    
    
    switch(room_type)
    {
        case 1:
            cost = 1500 * num_days * num_rooms;
            break;
        case 2:
            cost = 1000 * num_days * num_rooms;
            break;
        case 3:
            cost = 500 * num_days * num_rooms;
            break;
        case 4:
            cost = 350 * num_days * num_rooms;
            break;
        default:
            printf("Invalid room type!\n");
            return 0;
    }
    
    
    if(num_days > 4)
    {
        discount = cost * 0.05;
        cost -= discount;
    }
    
    
    printf("\n\nThank you for choosing Dennis Hotel.\n Reservation Summary:\n");
    printf("Name: %s\n", name);
    printf("Number of rooms booked: %d\n", num_rooms);
    printf("Room type: ");
    switch(room_type)
    {
        case 1:
            printf("VIP room\n");
            break;
        case 2:
            printf("Business class room\n");
            break;
        case 3:
            printf("Ordinary room\n");
            break;
        case 4:
            printf("Special room\n");
            break;
    }
    printf("Number of days booked: %d\n", num_days);
    printf("Cost: Sh.%.2f\n", cost);
    if(discount > 0)
        printf("Congratulations! You qualify for a discount of Sh.%.2f\n", discount);
    else
        printf("Sorry, you do not qualify for a discount.\n");
    
    return 0;
}





