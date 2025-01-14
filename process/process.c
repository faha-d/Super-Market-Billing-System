#include "process.h"
#include "../input/input.h"

#define TAX_RATE 0.10
#define DISCOUNT_THRESHOLD 100.0
#define DISCOUNT_RATE 0.05

float calculateTotal() {
    float subtotal = 0.0;
    for (int i = 0; i < cartCount; i++) {
        subtotal += cart[i].quantity * cart[i].price;
    }
    return subtotal;
}

float calculateTaxes(float subtotal) {
    return subtotal * TAX_RATE;
}

float applyDiscounts(float subtotal) {
    if (subtotal > DISCOUNT_THRESHOLD) {
        return subtotal * DISCOUNT_RATE;
    }
    return 0.0;
}
