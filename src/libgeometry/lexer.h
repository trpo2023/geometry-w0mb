#pragma once

#include <stdio.h>

#define BLUE "\e[1;34m"
#define CLOSE "\e[0m"


enum ERROR {
    ERROR_NAME,
    ERROR_BRACKET,
    ERROR_NUMBER,
    ERROR_UNEXPECT_TOKEN,
    ERROR_EXPECT_COMMA,
};

void show_error(int ERROR, int num, char* ch);
void to_lower(char* str, int num);
void is_end_empty(char* arr, int* num);