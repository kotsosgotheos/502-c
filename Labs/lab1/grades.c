#include <stdio.h>

void input(char *prompt, float *var) {
    printf("%s", prompt);
    scanf("%g", var);
}

int main(void) {
    float ANUM; /* arithmos apousiwn */
    float A; /* apousies */
    float PR1, PR2; /* vathmos 1, 2 */
    float TE; /* telikh esketash */
    float BE; /* vathmos ergasthriou */
    float GR; /* telokos vathmos */

    input("Αριθμός απουσιών: ", &ANUM);
    input("Βαθμοί στην πρόοδο 1: ", &PR1);
    input("Βαθμός στην πρόοδο 2: ", &PR2);
    input("Βαθμός στην τελική εξέταση: ", &TE);

    if(ANUM == 0) A = 10;
    else if(ANUM < 2) A = 5;
    else A = 0;

    BE = A * 0.2 + PR1 * 0.4 + PR2 * 0.4;

    if(BE < 4.5)
        printf("Αποτυχία στα εργαστήρια.");
    else if(TE < 4.5)
        printf("Αποτυχία στην τελική εξέταση.");
    else {
        GR = BE * 0.5 + TE * 0.5;
        printf("Επιτυχία στο MYY502 με βαθμο: %g\n", GR);
    }

    return 0;
}
