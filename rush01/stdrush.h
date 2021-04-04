/* utils  */
int     *format_args(char *input_args);
void    swap(int *a, int *b);
void    find_dir_index(int i, int *directionptr, int *indexptr);

/* boards */
int     **make_2d_array(int x, int y);

/* lines */
int     amount_boxes_seen(int *lineptr);
void    reverse_line(int *lineptr);
void    write_to_lineptr(int *lineptr, int input);
int     *line_on_board(int **boardptr, int direction, int index);
void    write_on_board(int **boardptr, int *lineptr, int direction, int index);

/* print */
void    print_int(int num);
void    print_line(char *str);
void    lg(char *str, int is_debug);
void    print_board(int **boardptr);

/* compare */
void compare_write_ALL(int **boardptr, int *inputListptr);