#include <stdio.h>
#include <stdlib.h>
#include "stdrush.h"

void    reverse_line(int *lineptr)
{
    swap(&lineptr[0], &lineptr[3]);
    swap(&lineptr[1], &lineptr[2]);
}

int     amount_boxes_seen(int *lineptr)
{
    int i;
    int prevmax;
    int seen;
    
    i = 0;
    seen = 0;
    prevmax = 0;
    while (i < 4)
    {
        if(lineptr[i] > prevmax)
        {
            prevmax = lineptr[i];
            seen++;
        }
        i++;
    }
    
    return seen ;
}

void write_to_lineptr(int *lineptr, int input)
{
    int i;
    while (i < 4)
    {
        lineptr[i] = input % 10;
        input /= 10;
        i++;
    }
}

void write_on_board(int **boardptr, int *lineptr, int direction, int index)
{
    int counter;
    
    counter = 0;
    if(direction==0 || direction==1){
        while(counter < 4){
            if (boardptr[counter][index] == 0)
            {
                boardptr[counter][index] = lineptr[counter];
            }
            counter++;
        }
    }
    else if(direction == 2 || direction == 3){
        while(counter < 4){
            if (boardptr[index][counter] == 0)
            {
                boardptr[index][counter] = lineptr[counter]; 
            }
            counter++;
        }
    }
    // else{
    //     print_line("error: direction for fetch_line wrong");
    // }
    // if(direction==1||direction==3){
    //     print_line("error: reverse writing not supported");
    // }
}

int *line_on_board(int **boardptr, int direction, int index)
{
    /* 
    return address to 4-item array
    direction is 0:col_up 1:col_down 2:row_left 3:row_right 
    index is 0: first 1: second 2: third 3:fourth
    */
    int counter;
    
    counter = 0;
    int *lineptr;
    lineptr = malloc(4 * sizeof(int));
    if(direction==0 || direction==1){
        while(counter < 4){
            lineptr[counter] = boardptr[counter][index]; 
            // y, x로 접근, 세로
            counter ++;
        }
    }
    else if(direction == 2 || direction == 3){
        while(counter < 4){
            lineptr[counter] = boardptr[index][counter];
            // y, x로 접근, 가로
            counter ++;
        }
    }
    else{
        print_line("error: direction for fetch_line wrong");
    }
    if(direction==1||direction==3){
        reverse_line(lineptr);
    }
    return lineptr;
}