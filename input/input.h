#ifndef INPUT_H
#define INPUT_H

#define MAX_PRODUCTS 100

typedef struct {
    char name[50];
    char phone[15];
} Customer;

typedef struct {
    char name[50];
    int quantity;
    float price;
} Product;

extern Product cart[MAX_PRODUCTS]; // Cart array
extern int cartCount;              // Number of products in the cart
extern Customer currentCustomer;   // Current customer's details

void inputCustomerDetails();       // Collects customer details
void inputItems();                 // Collects product details

#endif
