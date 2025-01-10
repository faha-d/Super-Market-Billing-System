#include <stdio.h>
#include "products.h"

typedef struct
{
    char name[50];
    int quantity;
    float price;
} Product;

#define MAX_PRODUCTS 100
Product cart[MAX_PRODUCTS];

int cartCount = 0;

void addProducts() {
    char choice;

    do {
        if(cartCount >= MAX_PRODUCTS) {
        printf("\nCart is full! Cannot add more products.\n");
        return;
    }

    Product product; // variable to hold values.
    printf("\n Enter product name: ");
    scanf("%s", product.name);
    printf("\n Enter quantity: ");
    scanf("%d", &product.quantity);
    printf("\n Enter price per unit: ");
    scanf("%f", &product.price);

    cart[cartCount++] = product;
    printf("\n '%s' added to your cart successfully!\n", product.name);

    printf("\n Do you want to add another product? (y/n): ");
    scanf(" %c", &choice);
    } while(choice == 'y' || choice == 'Y');
}

void displayProducts() {
    if(cartCount == 0) {
        printf("\n Your cart is empty. Please add some products first. \n");
        return;
    }

    printf("\n Products in your cart:\n");
    printf("-------------------------------------------------\n");
    printf("| %-20s | %-10s | %-10s |\n", "Name", "Quantity", "Price");
    printf("-------------------------------------------------\n");

    for(int i = 0; i < cartCount; i++) {
        printf("| %-20s | %-10d | %-10.2f |\n", cart[i].name, cart[i].quantity, cart[i].price);
    }
    printf("-------------------------------------------------\n");
}