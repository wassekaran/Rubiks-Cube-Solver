
#include <stdio.h>
#include <stdlib.h>

#include "cornertable.h"
#include "goal.h"
#include "cube.h"

int generate_tables()
{
    FILE *output;
    unsigned char *cornertable = CORNER_TABLE_NEW;
    corner_generate(cornertable, cube_solved);
    output = fopen("table_corner.rht", "w");
    corner_write(cornertable, output);
    fclose(output);
    return 0;
}

/* Reads in tables and starts the solver */
int solve(char *tosolve)
{
    FILE *input;
    unsigned char *corner_table;
    cube_type tosolve_converted;
    input = fopen("table_corner.rht", "r");
    corner_table = CORNER_TABLE_NEW;
    if (fread(corner_table, 1, 44089920, input) != 44089920)
        exit(1);

    cube_120convert(tosolve, tosolve_converted);
    goal_solve(tosolve_converted, NULL, corner_table); 
    return 1;
}

int main(int argc, char **argv)
{
    solve(argv[1]);
    return 0;
}
