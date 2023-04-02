#include <stdio.h>
#include <string.h>

#define MAX_CUSTOMERS 5

struct Reservation {
    char name[50];
    int num_customers;
    int num_days;
    int room_type;  // 1 = VIP, 2 = Business Class, 3 = Ordinary
    double room_rate;
    double total_cost;
};

void print_menu();
int get_integer_input();
double get_double_input();
void make_reservation(struct Reservation *res);

int main() {
    printf("Hello, welcome to Liebig Hotel!\n");
    
    struct Reservation res;
    make_reservation(&res);
    
    printf("Thank you for choosing Liebig Hotel!\n");
    printf("Your total cost for %d days in a %d-person %s room is $%.2f.\n",
           res.num_days, res.num_customers, 
           (res.room_type == 1) ? "VIP" : (res.room_type == 2) ? "Business Class" : "Ordinary",
           res.total_cost);
           
    return 0;
}

void print_menu() {
    printf("Please select a room type:\n");
    printf("1. VIP (max. 5 people per room) - $500/day\n");
    printf("2. Business Class (max. 5 people per room) - $100/day\n");
    printf("3. Ordinary (max. 5 people per room) - $50/day\n");
}

int get_integer_input() {
    int input;
    scanf("%d", &input);
    return input;
}

double get_double_input() {
    double input;
    scanf("%lf", &input);
    return input;
}

void make_reservation(struct Reservation *res) {
    printf("Please enter your name: ");
    scanf("%s", res->name);
    
    printf("Please enter the number of customers (max. 5): ");
    res->num_customers = get_integer_input();
    while (res->num_customers < 1 || res->num_customers > MAX_CUSTOMERS) {
        printf("Invalid input. Please enter a number between 1 and %d: ", MAX_CUSTOMERS);
        res->num_customers = get_integer_input();
    }
    
    print_menu();
    printf("Please enter the room type: ");
    res->room_type = get_integer_input();
    while (res->room_type < 1 || res->room_type > 3) {
        printf("Invalid input. Please enter 1, 2, or 3: ");
        res->room_type = get_integer_input();
    }
    switch (res->room_type) {
        case 1:
            res->room_rate = 500.0;
            break;
        case 2:
            res->room_rate = 100.0;
            break;
        case 3:
            res->room_rate = 50.0;
            break;
    }
    
    printf("Please enter the number of days: ");
    res->num_days = get_integer_input();
    while (res->num_days < 1) {
        printf("Invalid input. Please enter a positive number: ");
        res->num_days = get_integer_input();
    }
    
    res->total_cost = res->num_customers * res->room_rate * res->num_days;
}