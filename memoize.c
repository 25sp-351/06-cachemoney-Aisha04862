#include <stdio.h>
#include <string.h>
#include "cache.h"

//number to words
const char *ones[] = {"", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
const char *teens[] = {"ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen",  "sixteen", "seventeen", "eighteen", "nineteen"};
const char *tens[] = {"", "", "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"};
const char *hundred = "hundred";
const char *thousand = "thousand";
const char *million = "million";

void convert_words(int amount, char *result) {
    int dollars = amount / 100;
    int cents = amount % 100;
    char buffer[512] = "";

//millions
    if (dollars >= 1000000) { 
        strcat(buffer, ones[dollars / 1000000]);
        strcat(buffer, " ");
        strcat(buffer, million);
        strcat(buffer, " ");
        dollars %= 1000000;
    }
//thousands
    if (dollars >= 1000) { 
        strcat(buffer, ones[dollars / 1000]);
        strcat(buffer, " thousand ");
        dollars %= 1000;
    }
//hundreds
    if (dollars >= 100) { 
        strcat(buffer, ones[dollars / 100]);
        strcat(buffer, " hundred ");
        dollars %= 100;
    }
//tens and ones
    if (dollars >= 20) { 
        strcat(buffer, tens[dollars / 10]);
        strcat(buffer, " ");
        dollars %= 10;
    } else if (dollars >= 10) { 
        strcat(buffer, teens[dollars - 10]);
        strcat(buffer, " ");
        dollars = 0;
    }
//ones
    if (dollars > 0) { 
        strcat(buffer, ones[dollars]);
        strcat(buffer, " ");
    }

    strcat(buffer, "dollars and ");

    if (cents == 0) {
        strcat(buffer, "zero cents");
    } else {
        if (cents >= 20) {
            strcat(buffer, tens[cents / 10]);
            strcat(buffer, " ");
            cents %= 10;
        } else if (cents >= 10) {
            strcat(buffer, teens[cents - 10]);
            strcat(buffer, " ");
            cents = 0;
        }

        if (cents > 0) {
            strcat(buffer, ones[cents]);
        }
        strcat(buffer, "cents");
    }

    strncpy(result, buffer, 512);
}