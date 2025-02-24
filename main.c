#include <stdio.h>
#include <stdlib.h>
#include "cache.h"

extern void convert_words(int, char*);


int main() {
    // Set the function pointer
    money_converter(convert_words);  

    char buffer[512];
    while (fgets(buffer, sizeof(buffer), stdin)) {
        int amount = atoi(buffer);
        printf("%d = %s\n", amount, cache_functions(amount));
    }

    return 0;
}