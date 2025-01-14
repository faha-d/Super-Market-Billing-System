#include <stdio.h>
#include "./input/input.h"
#include "./process/process.h"
#include "./output/output.h"

void menu() {
    int choice;

    printf("\nWelcome to the Super Market Billing System!\n");

    do {
        printf("\n=== Super Market Billing System ===\n");
        printf("1. Enter Customer Details\n");
        printf("2. Add Products to Cart\n");
        printf("3. View Your Cart\n");
        printf("4. Proceed to Checkout\n");
        printf("5. Exit\n");
        printf("Please select an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                inputCustomerDetails();
                break;
            case 2:
                inputItems();
                break;
            case 3:
                displayCart();
                break;
            case 4:
                generateBill();
                break;
            case 5:
                printf("\nThank you for shopping with us! Goodbye.\n");
                break;
            default:
                printf("\nInvalid choice. Please try again.\n");
        }
    } while (choice != 5);
}

int main() {
    menu();
    return 0;
}
