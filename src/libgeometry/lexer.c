#include <libgeometry/geom_parser.h>
#include <libgeometry/lexer.h>

#include <ctype.h>
#include <stdlib.h>



void show_error(int ERROR, int num, char* ch)
{
    for (int i = 0; i < num; i++) {
        putchar(' ');
    }
    printf("^\n");

    switch (ERROR) {
    case ERROR_NAME:
        printf("Error at column %d: expected %s'circle'%s\n", num, BLUE, CLOSE);
        break;
    case ERROR_BRACKET:
        if (*ch == ')') {
            printf("Error at column %d: expected %s'('%s\n", num, BLUE, CLOSE);
            break;
        } else {
            printf("Error at column %d: expected %s')'%s\n", num, BLUE, CLOSE);
            break;
        }
    case ERROR_NUMBER:
        printf("Error at column %d: expected %s'<double>'%s\n",
               num,
               BLUE,
               CLOSE);
        break;
    case ERROR_UNEXPECT_TOKEN:
        printf("Error at column %d: unexpected token\n", num);
        break;
    case ERROR_EXPECT_COMMA:
        printf("Error at column %d: expected %s','%s\n", num, BLUE, CLOSE);
        break;
    }
}

void to_lower(char* str, int num)
{
    for (int i = 0; i < num; i++) {
        str[i] = tolower(str[i]);
    }
}



void is_end_empty(char* arr, int* num)
{
    *num += 1;
    while (arr[*num] != '\n' && arr[*num] != EOF) {
        if (arr[*num] == ' ') {
            *num += 1;
        } else {
            show_error(ERROR_UNEXPECT_TOKEN, *num, NULL);
            exit(EXIT_FAILURE);
        }
    }
}