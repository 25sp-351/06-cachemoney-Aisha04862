#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cache.h"

#define MAX_MEMOIZE_LIMIT 150000  //Max memoize limit $1500
#define MAX_BUFFER_LIMIT 512      

//array to store cached results
static char memo[MAX_MEMOIZE_LIMIT][MAX_BUFFER_LIMIT]; 
static void (*original_converter)(int, char*) = NULL; 

void money_converter(void (*func)(int, char*)) {
    original_converter = func;
}

char* cache_functions(int num) {
    static char result[MAX_BUFFER_LIMIT];

    if (original_converter == NULL) {
        return "Error: Converter function not set";
    }

//check if number within max memoize limit $1500
    if (num < MAX_MEMOIZE_LIMIT && memo[num][0] != '\0') {
        return memo[num];  
    }

    if (original_converter) {
        original_converter(num, result);  

        if (num < MAX_MEMOIZE_LIMIT) {
            strncpy(memo[num], result, MAX_BUFFER_LIMIT);
        }
        return result;
    }

    return "Error: Failure";
}