#include <stdlib.h>
#include "stdrush.h"

void compare_14(int **boardptr, int i, int left, int right)
{
    int direction;
    int index;
    //printf("left %d right %d\n", left, right);
    
    find_dir_index(i, &direction, &index);
    if (left == 1 && right == 4)
    {
        write_to_board_num(boardptr, i, 4321);
    }
    if (left == 4 && right == 1)
    {
        write_to_board_num(boardptr, i, 1234);
    }
}

void compare_12(int **boardptr, int i, int left, int right)
{
    int direction;
    int index;
    
    find_dir_index(i, &direction, &index);
    if (left == 1 && right == 2)
    {
        write_to_board_num(boardptr, i, 4003);
    }
    if (left == 2 && right == 1)
    {
        write_to_board_num(boardptr, i, 3004);
    }
}

void compare_12(int **boardptr, int i, int left, int right)
{
    int direction;
    int index;
    
    find_dir_index(i, &direction, &index);
    if (left == 1 && right == 2)
    {
        write_to_board_num(boardptr, i, 4003);
    }
    if (left == 2 && right == 1)
    {
        write_to_board_num(boardptr, i, 3004);
    }
}


void compare_MULT(int **boardptr, int i, int left, int right)
{
    compare_14(boardptr, i, left, right);
    compare_12(boardptr, i, left, right);
}

void compare_write_ALL(int **boardptr, int *inputListptr)
{
    int i;
    int finish;
    int left;
    int right;
    
    //while(finish)
    //{
        i = 0;
        while(i < 4)
        {
            left = inputListptr[i];
            right = inputListptr[i + 4];
            compare_MULT(boardptr, i, left, right);
            i++;
        }
        i= 8;
        while(i < 12)
        {
            left = inputListptr[i];
            right = inputListptr[i + 4];
            compare_MULT(boardptr, i, left, right);
            i++;
        }
        print_board(boardptr);
        finish = is_answer_full(boardptr);
    //}
}