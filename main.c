#include <stdio.h>
#include "./products/products.h"

void menu() {
    int choice;

    // Greeting User
    printf("\nWelcome to the Super Market Billing System!\n");
    printf("We are here to make your shopping experience smooth and convenient.\n");

    do {
        printf("\n 1. Add Products to Cart\n");
        printf("\n 2. View Your Cart\n");
        printf("\n 3. Proceed to Checkout\n");
        printf("\n 4. Exit\n");
        printf("\n Please select an option: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                addProducts();
                break;
            case 2:
                displayProducts();
                break;
            case 3:
                printf("\n You are now checking out. Please review your bill. \n");
                // checkoutBill();
                break;
            case 4:
                printf("\n Thank you for shopping with us! Have a great day! \n");
                break;
            default: 
                printf("\n Invalid option selected, Please try again. \n");
        }
    }
    while(choice !=4); 
}

int main() {
    menu();
    return 0;
}