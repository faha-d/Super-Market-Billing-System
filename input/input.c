#include <stdio.h>
#include "../utils/utils.h"
#include "input.h"

Product cart[MAX_PRODUCTS];
int cartCount = 0;
Customer currentCustomer;

// Collect customer details
void inputCustomerDetails() {
    printf("\nEnter customer name (letters and spaces only): ");
    scanf(" %[^\n]%*c", currentCustomer.name);
    while (!isValidName(currentCustomer.name)) {
        printf("\nERROR: Invalid name format!\n");
        printf("Names can only contain letters and spaces.\n");
        printf("Please enter the customer name again: ");
        scanf(" %[^\n]%*c", currentCustomer.name);
    }

    printf("Enter customer phone number (10 digits only): ");
    scanf("%s", currentCustomer.phone);
    while (!isValidPhone(currentCustomer.phone)) {
        printf("\nERROR: Invalid phone number!\n");
        printf("Phone numbers must be exactly 10 digits and numeric.\n");
        printf("Please enter the phone number again: ");
        scanf("%s", currentCustomer.phone);
    }

    printf("\nCustomer details saved successfully!\n");
}

// Collect product details
void inputItems() {
    char choice = 'y';
    while (choice == 'y' || choice == 'Y') {
        if (cartCount >= MAX_PRODUCTS) {
            printf("\nERROR: Cart is full! Cannot add more products.\n");
            return;
        }

        Product p;
        printf("\nEnter product name (letters and spaces only): ");
        scanf(" %[^\n]%*c", p.name);
        while (!isValidName(p.name)) {
            printf("\nERROR: Invalid product name!\n");
            printf("Product names can only contain letters and spaces.\n");
            printf("Please enter the product name again: ");
            scanf(" %[^\n]%*c", p.name);
        }

        printf("Enter quantity (positive integer only): ");
        scanf("%d", &p.quantity);
        while (p.quantity <= 0) {
            printf("\nERROR: Invalid quantity!\n");
            printf("Quantity must be a positive whole number.\n");
            printf("Please enter the quantity again: ");
            scanf("%d", &p.quantity);
        }

        printf("Enter price per unit (positive number only): ");
        scanf("%f", &p.price);
        while (p.price <= 0) {
            printf("\nERROR: Invalid price!\n");
            printf("Price per unit must be a positive number.\n");
            printf("Please enter the price per unit again: ");
            scanf("%f", &p.price);
        }

        cart[cartCount++] = p;
        printf("\nProduct '%s' added to your cart successfully!\n", p.name);

        printf("\nDo you want to add another product? (y/n): ");
        scanf(" %c", &choice);
    }
}
