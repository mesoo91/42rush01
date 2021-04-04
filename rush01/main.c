#include <stdio.h>
#include "stdrush.h"

int main(int argc, int **argv)
{
    int **boardptr;
    int *lineptr;
    int *inputListptr;
    
    if (argc == 2){
        inputListptr = format_args(argv[1]);
    } else {
        print_line("ERROR");
        return 1;
    }
    for (int i = 0; i < 16; i++){
        print_int(inputListptr[i]);
    }
    boardptr = make_2d_array(4, 4);
    lineptr = line_on_board(boardptr, 3, 3); // direction, index
    print_line("\nwriting start\n");
    compare_write_ALL(boardptr, inputListptr);
    // printf("\ncheck, boardptr x3,y2 is %d\n", boardptr[3][2]);
    // printf("so this is how line looks like\n");
    // for(int i = 0; i < 4; i++){
    //     printf("%d ",lineptr[i]);
    // }
    //printf("amount_boxes_seen:%d",amount_boxes_seen(lineptr));
    
    print_line("\n FINAL RESULT \n");
    //print_board(boardptr);
    print_line("\n FINAL RESULT \n");
    return 0;
}