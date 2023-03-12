#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    FILE* file1;
    FILE* file;

    file1 = fopen("geometry.txt", "r");

    if (!file1) {
        printf("Error: cannot open file. Check name of file\n");
    }

    int i, ind_open_bracket = 0, ind_close_bracket = 0, ind_last_num_elm = 0, ind_first_num_elm = 0, ind_second_num_elm = 0;
    int length = 0, count = 0, element = 0, error = 0, dotcount1  = 0, minuscount1 =0;

    while (1) {
        element = fgetc(file1);
        if (element == EOF) {
            if (feof(file1) != 0) {
                break;
            }
        }
        count++;
    }
    length = count;
    fclose(file1);

    char a[length], b[6] = "circle";
    file = fopen("geometry.txt", "r");
    while (fgets(a, length + 1, file)) {
        printf("%s", a);

        // check circle
        for (i = 0; i < 7; i++) {
            if (a[i] != b[i] && i < 6) {
                printf("Error : expected 'circle'\n");
                error = 1;
                break;
            }           
            ind_open_bracket = i;
        }
	
        // check (
        if (error == 0) {
            if(a[ind_open_bracket] != '(') {
                error = 1;
                printf("Error: expected '<(>'\n");
            }
        }
        
        // check first number
        if (error == 0) {
            if(a[ind_open_bracket+1] == '-') {
                minuscount1 += 1;
            }
            for (i = ind_open_bracket + 1; a[i] != ' ';i++)
            {
                if (error == 0)
                {
                    if(a[i+1] == '-'){
                        minuscount1 += 1;
                    }
                    if(minuscount1 >= 2){
                        error = 1;
                        printf("Error: expected one minus in first number\n");
                        break;
                    }
                    if(isdigit(a[i]) == 0 && a[i] != '.' && a[ind_open_bracket+1] != '-'){
                        error = 1;
                        printf("Error: expected first number\n");
                        break;
                    }
                    if(a[i]=='.'){
                        dotcount1 += 1;
                    }
                    if(dotcount1 >= 2){
                        error = 1;
                        printf("Error: expected one dot in first number\n");
                        break;
                    }
                }
            }
            dotcount1 = 0;
            minuscount1 = 0;
            ind_first_num_elm = i;
        }
        
        //check first gap
        if(error==0){
            if(a[ind_first_num_elm] !=' '){
	            error = 1;
	            printf("Error: expected ' ' after first number\n");
	        }
	    }
	
        // check second number
        if (error == 0)
        {
            if(a[ind_first_num_elm+ 1] == '-'){
                minuscount1 += 1;
            }
            for (i = ind_first_num_elm + 1; a[i] != ',';i++)
            {
                if (error == 0)
                {
                    if(a[i]==' '){
                        error = 1;
                        printf("Error: expected ',' after second number");
                    }
                    if(a[i+1] == '-'){
                        minuscount1 += 1;
                    }
                    if(minuscount1 >= 2){
                        error = 1;
                        printf("Error: expected one minus in second number\n");
                        break;
                    }  
                    if(isdigit(a[i]) == 0 && a[i] != '.' && a[ind_first_num_elm+ 1] != '-'){
                        error = 1;
                        printf("Error: expected second number\n");
                        break;
                    }
                    if(a[i]=='.'){
                        dotcount1 += 1;
                    }
                    if(dotcount1 >= 2){
                        error = 1;
                        printf("Error: expected one dot in second number\n");
                        break;
                    }
                }
            }
            dotcount1 = 0;
            minuscount1 = 0;
            ind_second_num_elm = i;
        }
        
        
        //check ,
        if(error==0){
            if(a[ind_second_num_elm] !=','){
	            error = 1;
	            printf("Error: expected ','\n");
	        }
	    }
	
        //check second gap
        if(error==0){
            if(a[ind_second_num_elm+1] !=' '){
                error = 1;
                printf("Error: expected ' ' after ','\n");
            }
        }
	
	    // find index of ')' token
        for (i = 0; i < length; i++) 
        {
            if(error == 0)
            {
                if (a[i] == ')') {
                    ind_close_bracket = i;
                } else {
                    ind_close_bracket = length - 1;
                } 
            }
        }
        
        // check last number
        if (error == 0)
        {
            if(a[ind_second_num_elm + 2] == '-'){
               minuscount1 += 1;
            }
            for (i = ind_second_num_elm + 2; i < ind_close_bracket; i++)
            {
                if (error == 0)
                {
                    if(a[i+1] == '-'){
                        minuscount1 += 1;
                    }
                    if(a[i]==')'){
                        break;
                    }
                    if(minuscount1 >= 2){
                        error = 1;
                        printf("Error: expected one minus in third number\n");
                        break;
                    }
                    if(isdigit(a[i]) == 0 && a[i] != '.' && a[ind_second_num_elm + 2] != '-' && a[i] != ')'){
                        error = 1;
                        printf("\nError: expected third number\n");
                        break;
                    }
                    if(a[i]=='.'){
                        dotcount1 += 1;
                    }
                    if(dotcount1 >= 2){
                        error = 1;
                        printf("Error: expected one dot in third number\n");
                        break;
                    }
                }
            }
            dotcount1 = 0;
            minuscount1 = 0;
            ind_last_num_elm = i;
        }
	
        // check unexpected tokens
        for (i = ind_last_num_elm + 1; i < length; i++) {
            if (error == 0) {
                if (a[i] == '\n') {
                    break;
                }

                if (a[i] != ' ') {
                    error = 1;
                    printf("Error: unexpected token\n");
                    break;
                }
            } else {
                break;
            }
        }
        
        

        if (error == 0) {
            printf("No Errors!\n");
        }

        error = 0;
        printf("\n");
    }
    return 0;
}
