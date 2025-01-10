#include <stdio.h>

void addProducts() {
    printf("Adding......");
}

void displayProducts() {
    printf("Displaying....");
}

void checkoutBill() {
    printf("Checkout...");
}

void menu() {
    int choice;

    // Greeting User
    printf("\nWelcome to the Super Market Billing System!\n");
    printf("We are here to make your shopping experience smooth and convenient.\n");

    do {
        printf("1. Add Products to Cart\n");
        printf("2. View Your Cart\n");
        printf("3. Proceed to Checkout\n");
        printf("4. Exit\n");
        printf("Please select an option: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("\nLet's add some products to your cart! \n");
                addProducts();
                break;
            case 2:
                printf("\nHere are the products in your cart: \n");
                displayProducts();
                break;
            case 3:
                printf("\nYou are now checking out. Please review your bill. \n");
                checkoutBill();
                break;
            case 4:
                printf("\nThank you for shopping with us! Have a great day! \n");
                break;
        }
    }
    while(choice !=4); 
}

int main() {
    menu();
    return 0;
}