#include <stdlib.h>
#include "stdrush.h"

void    swap(int *a, int *b)
{
    int temp;
    
    temp = *a;
    *a = *b;
    *b = temp;
}

int     check_input(int *inputListptr)
{
    int i;
    int test;
    
    i = 0;
    while(i < 8)
    {
        test = inputListptr[i] + inputListptr[i + 4];
        if(test < 3 && test > 5)
        {
            print_line("error: invalid input\n");
            return 1;
        }
        i++;
    }
    return 0;
}

void    find_dir_index(int i, int *directionptr, int *indexptr)
{
    if ( i < 4 && i >= 0 )
    {
        *directionptr = 0;
    }
    if ( i < 8 && i >= 4 )
    {
        *directionptr = 1;
    }
    if ( i < 12 && i >= 8 )
    {
        *directionptr = 2;
    }
    if ( i < 16 && i >= 12 )
    {
        *directionptr = 3;
    }
    *indexptr = i % 4;
}


int    *format_args(char *input_args)
{
    int count;
    int *inputListptr;
    
    inputListptr = malloc(16 * sizeof(int));
    count = 0;
    while(*input_args)
    {
        if(*input_args <= 52 && *input_args >= 49){
            /* ASCII로 49는 1, 52는 4, 1~4에, 48 = 0 */
            inputListptr[count] = *input_args - 48;
            count++;
        }
        else if (!(*input_args == 32 || *input_args == 0)){
            print_line("\nerror invalid char");
        }
        input_args++;
    }
    if ( count != 16)
    {
        print_line("\nerror number not 16\n");
    }
    check_input(inputListptr);
    return inputListptr;
}