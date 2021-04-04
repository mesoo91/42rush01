#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "stdrush.h"

int is_answer_full(int **boardptr)
{
    int x;
    int y;
    
    x = 0;
    y = 0;
    
    while(y < 4)
    {
        while(x < 4)
        {
            if (boardptr[x][y] = 0)
            {
                return 0;
            }
            x++;
        }
        y++;
    }
    return 1;
}

void write_to_board_num(int **boardptr, int i, int num_to_write)
{
    int direction;
    int index;
    int *lineptr = malloc(4 * sizeof(int));
    //printf("num_to_write is %d\n",num_to_write);
    write_to_lineptr(lineptr, num_to_write);
    find_dir_index(i, &direction, &index);
    write_on_board(boardptr, lineptr, direction, index);
}

int     **make_2d_array(int x, int y)
{
    int i;
    int x_count;
    int y_count;
    int **dlistptr;
    
    i = 0;
    dlistptr = malloc(x * sizeof(int *));
    while(i < y)
    {
        dlistptr[i] = malloc(y * sizeof(int));
        i++;
    }
    
    y_count = 0;
    while (y_count < y){
        x_count = 0;
        while(x_count < x)
        {
            dlistptr[x_count][y_count] = 0;
            x_count++;
        }
        y_count++;
    }
    return dlistptr;
}