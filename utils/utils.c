#include "utils.h"

int isAlphabet(char c) {
    return (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z');
}

int isValidName(const char *name) {
    int i = 0;
    while (name[i] != '\0') {
        if (!isAlphabet(name[i]) && name[i] != ' ') {
            return 0;
        }
        i++;
    }
    return i > 0;
}

int isValidPhone(const char *phone) {
    int i = 0;
    while (phone[i] != '\0') {
        if (phone[i] < '0' || phone[i] > '9') {
            return 0;
        }
        i++;
    }
    return i == 10;
}
