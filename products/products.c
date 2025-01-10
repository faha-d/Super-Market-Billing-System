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
    if(cartCount >= MAX_PRODUCTS) {
        printf("\nCart is full! Cannot add more products.\n");
        return;
    }

    Product product;
    printf("\nLet's add some products to your cart! \n");
    printf("\nEnter product name: ");
    scanf("%s", product.name);
    printf("Enter quantity: ");
    scanf("%d", &product.quantity);
    printf("Enter price per unit: ");
    scanf("%f", &product.price);

    cart[cartCount++] = product;
    printf("\nProduct '%s' added to your cart successfully!\n", product.name);
}

void displayProducts() {
    if(cartCount == 0) {
        printf("\nYour cart is empty. Please add some products first. \n");
        return;
    }

    printf("\nProducts in your cart:\n");
    printf("-------------------------------------------------\n");
    printf("| %-20s | %-10s | %-10s |\n", "Name", "Quantity", "Price");
    printf("-------------------------------------------------\n");

    for(int i = 0; i < cartCount; i++) {
        printf("| %-20s | %-10d | %-10.2f |\n", cart[i].name, cart[i].quantity, cart[i].price);
    }
    printf("-------------------------------------------------\n");
}