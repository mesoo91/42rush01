#include <unistd.h>

void    print_line(char *str)
{
    while(*str)
    {
        write(1, str,1);
        str++;
    }
}

void    print_int(int num)
{
    int chr;
    
    if (num == -1){
        chr = '\n';
    } else if ( num == -2) {
        chr = ' ';
    } else if ( num <= 4 && num >= 0 ){
        chr = '0' + num;
    } else {
        print_line("error in print_int:you put forbidden number");
    }
    write(1, &chr, 1);
}

void    lg(char *str, int is_debug)
{
    if (is_debug)
    {
        print_line(str);
    }
}

void    print_board(int **boardptr)
{
    int x;
    int y;
    
    y = 0;
    while (y < 4){
        x = 0;
        while(x < 4)
        {
            print_int(boardptr[x][y]);
            if (x != 3)
            {
                print_int(-2);
            }
            x++;
        }
        print_int(-1);
        y++;
    }
}