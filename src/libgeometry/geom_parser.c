#include <libgeometry/geom_parser.h>
#include <libgeometry/lexer.h>

#include <ctype.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

double coordinat_x(char* arr, int* num)
{
    char exp[20];
    int i = 0;

    while (!isdigit(arr[*num]) && arr[*num] != '-') {
        if (arr[*num] == '(' || arr[*num] == ' ') {
            *num += 1;
        } else {
            if (arr[*num] == ')') {
                show_error(ERROR_BRACKET, *num, &arr[*num]);
                exit(EXIT_FAILURE);
            } else {
                show_error(ERROR_NUMBER, *num, NULL);
                exit(EXIT_FAILURE);
            }
        }
    }

    while (isdigit(arr[*num]) || arr[*num] == '-' || arr[*num] == '.') {
        exp[i] = arr[*num];
        i++;
        *num += 1;
    }
    if (arr[*num] != ' ') {
        show_error(ERROR_UNEXPECT_TOKEN, *num, NULL);
        exit(EXIT_FAILURE);
    }
    char* trash;
    return strtod(exp, &trash);
}

double coordinat_y(char* arr, int* num)
{
    char exp[20];
    int i = 0;

    while (!isdigit(arr[*num]) && arr[*num] != '-') {
        if (arr[*num] == ' ') {
            *num += 1;
        } else {
            show_error(ERROR_NUMBER, *num, NULL);
            exit(EXIT_FAILURE);
        }
    }

    while (isdigit(arr[*num]) || arr[*num] == '-' || arr[*num] == '.') {
        exp[i] = arr[*num];
        i++;
        *num += 1;
    }

    while (arr[*num] != ',') {
        if (arr[*num] == ' ') {
            *num += 1;
        } else {
            show_error(ERROR_EXPECT_COMMA, *num, NULL);
            exit(EXIT_FAILURE);
        }
    }
    char* trash;
    return strtod(exp, &trash);
}

double radius_search(char* arr, int* num)
{
    char exp[20];
    int i = 0;

    while (!isdigit(arr[*num])) {
        if (arr[*num] == ' ' || arr[*num] == ',') {
            *num += 1;
        } else {
            show_error(ERROR_NUMBER, *num, NULL);
            exit(EXIT_FAILURE);
        }
    }

    while (isdigit(arr[*num]) || arr[*num] == '.') {
        exp[i] = arr[*num];
        i++;
        *num += 1;
    }

    while (arr[*num] != ')') {
        if (arr[*num] == ' ') {
            *num += 1;
        } else {
            if (arr[*num] == '(') {
                show_error(ERROR_BRACKET, *num, &arr[*num]);
                exit(EXIT_FAILURE);
            } else {
                show_error(ERROR_UNEXPECT_TOKEN, *num, NULL);
                exit(EXIT_FAILURE);
            }
        }
    }
    char* trash;
    return strtod(exp, &trash);
}
