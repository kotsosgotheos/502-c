#include <stdio.h>
#include <stdlib.h>

/** @param bool -> A 'big' enough size to hold both 1 and 0 **/
typedef unsigned char bool;
#define true 1
#define false 0

int sudoku[9][9] = {
    {5,3,4,6,7,8,9,1,2},
    {6,7,2,1,9,5,3,4,8},
    {1,9,8,3,4,2,5,6,7},
    {8,5,9,7,6,1,4,2,3},
    {4,2,6,8,5,3,7,9,1},
    {7,1,3,9,2,4,8,5,6},
    {9,6,1,5,3,7,2,8,4},
    {2,8,7,4,1,9,6,3,5},
    {3,4,5,2,8,6,1,7,9}
};

int sudoku2[9][9] = {
    {5,8,1,4,2,7,6,9,3},
    {3,7,4,5,9,6,8,1,2},
    {9,6,2,1,3,8,4,7,5},
    {6,2,9,3,8,5,7,4,1},
    {1,5,7,9,6,4,3,2,8},
    {8,4,3,2,7,1,5,6,9},
    {4,1,8,7,5,2,9,3,6},
    {2,9,5,6,4,3,1,8,7},
    {7,3,6,8,1,9,2,5,4}
};

bool check_solution(int s[9][9]) {
    int i;
    int j;
    int sum = 0;
    for(i = 0; i < 9; i++) {
        for(j = 0; j < 9; j++)
            sum += s[i][j];
        if(sum != 45) return false;
        sum = 0;
    }
    
    return true;
}

bool check_diagonal_solution(int s[9][9]) {
    int i;
    int j;
    int sum = 0;
    int diagonal_sum = 0;
    for(i = 0; i < 9; i++) {
        for(j = 0; j < 9; j++) {
            sum += s[i][j];

            if(i == j) diagonal_sum += s[i][j];
        }
        if(sum != 45) return false;
        if(diagonal_sum != 45) return false;
        sum = 0;
    }

    return true;
}

int main(void) {
    if(check_solution(sudoku))
        printf("Solution is correct\n");
    else
        printf("Solution is wrong\n");

    if(check_diagonal_solution(sudoku2))
        printf("Solution 2 is correct\n");
    else
        printf("Solution 2 is wrong\n");

    return 0;
}
