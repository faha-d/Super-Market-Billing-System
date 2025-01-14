#include <stdio.h>
#include "output.h"
#include "../process/process.h"
#include "../input/input.h"

void displayCart() {
    if (cartCount == 0) {
        printf("\nYour cart is empty. Please add some products first.\n");
        return;
    }

    printf("\nProducts in your cart:\n");
    printf("--------------------------------------------------\n");
    printf("| %-20s | %-10s | %-10s |\n", "Name", "Quantity", "Price");
    printf("--------------------------------------------------\n");
    for (int i = 0; i < cartCount; i++) {
        printf("| %-20s | %-10d | %-10.2f |\n", cart[i].name, cart[i].quantity, cart[i].price);
    }
    printf("--------------------------------------------------\n");
}

void generateBill() {
    if (cartCount == 0) {
        printf("\nYour cart is empty. Add products before checking out.\n");
        return;
    }

    float subtotal = calculateTotal();
    float taxes = calculateTaxes(subtotal);
    float discount = applyDiscounts(subtotal);
    float total = subtotal + taxes - discount;

    printf("\n=== Final Bill ===\n");
    printf("Customer Name: %s\n", currentCustomer.name);
    printf("Phone Number: %s\n", currentCustomer.phone);
    displayCart();
    printf("\nSubtotal: %.2f\n", subtotal);
    printf("Taxes (10%%): %.2f\n", taxes);
    printf("Discount: %.2f\n", discount);
    printf("Total Amount: %.2f\n", total);

    saveBillToFile(subtotal, taxes, discount, total);
}

void saveBillToFile(float subtotal, float taxes, float discount, float total) {
    FILE *file = fopen("data/bills.txt", "a");
    if (!file) {
        printf("\nERROR: Could not save the bill to file.\n");
        return;
    }

    fprintf(file, "\n=== Final Bill ===\n");
    fprintf(file, "Customer Name: %s\n", currentCustomer.name);
    fprintf(file, "Phone Number: %s\n", currentCustomer.phone);
    fprintf(file, "--------------------------------------------------\n");
    fprintf(file, "| %-20s | %-10s | %-10s |\n", "Name", "Quantity", "Price");
    fprintf(file, "--------------------------------------------------\n");
    for (int i = 0; i < cartCount; i++) {
        fprintf(file, "| %-20s | %-10d | %-10.2f |\n", cart[i].name, cart[i].quantity, cart[i].price);
    }
    fprintf(file, "--------------------------------------------------\n");
    fprintf(file, "Subtotal: %.2f\n", subtotal);
    fprintf(file, "Taxes (10%%): %.2f\n", taxes);
    fprintf(file, "Discount: %.2f\n", discount);
    fprintf(file, "Total Amount: %.2f\n", total);
    fprintf(file, "\n=================================\n");
    fclose(file);

    printf("\nBill saved to 'data/bills.txt'.\n");
}
