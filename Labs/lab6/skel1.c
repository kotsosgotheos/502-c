#include <stdio.h> /* printf */
#include <stdlib.h> /* malloc */
#include <string.h> /* strcat */

#define STUDENT_NUM 15

struct student {
    char *onoma;
    int am;
    float vathmos;
};

struct student **create_struct_table(char **onoma, int *am, float *vathmos) {
    size_t i;
    struct student *st;
    struct student **sarr = (struct student**)malloc(sizeof(struct student*) * STUDENT_NUM);

    for(i = 0; i < STUDENT_NUM; i++) {
        st = (struct student*)malloc(sizeof(struct student));

        st->onoma = onoma[i];
        st->am = am[i];
        st->vathmos = vathmos[i];

        sarr[i] = st;
    }

    return sarr;
}

void show_struct_table(struct student **sarr) {
    size_t i;
    for(i = 0; i < STUDENT_NUM; i++) {
        printf("\tOnoma: %s\n", sarr[i]->onoma);
        printf("\tAM: %d\n", sarr[i]->am);
        printf("\tVathmos: %g\n", sarr[i]->vathmos);
        printf("---\n");
    }
}

float compute_average_grade(struct student **sarr) {
    size_t i;
    float avg = 0;

    for(i = 0; i < STUDENT_NUM; i++)
        avg += sarr[i]->vathmos;

    return avg / STUDENT_NUM;
}

void print_failed_names(struct student **sarr) {
    size_t i;
    for(i = 0; i < STUDENT_NUM; i++)
        if(sarr[i]->vathmos < 10)
            printf("Failed: %s\n", sarr[i]->onoma);
}

void change_failed_names(struct student **sarr) {
    size_t i;
    char buf[64];

    for(i = 0; i < STUDENT_NUM; i++)
        if(sarr[i]->vathmos < 10) {
            /* TODO unsafe */
            strcpy(buf, sarr[i]->onoma);
            strcat(buf, " (failed)");
            sarr[i]->onoma = buf;
        }
}

int main(void) {
	char *onoma[] = {
		"Georgios Georgiou", "Vasilios Vasiliou", "Ioanna Ioannidou", 
		"Nikos Nikolaou", "Kiriakos Kiriakidis", "Kwstas Kwstantinidis", 
		"Spyros Spyropoulos", "Dimitris Dimitropoulos", "Dimitra Dimitriadi", 
		"Areti Aretidou", "Ilias Iliopoulos", "Kwstas Kwstoglou",
		"Aimilia Aimilianou", "Xristina Xristopoulou", "Theodoros Theodorou"
	};
    
	int am[] = {
		120, 122, 142, 130, 156, 132, 145, 133, 131, 140, 141, 150, 155, 134, 146
	};

	float vathmos[] = {
		12, 8.5, 15.5, 20, 7.5, 1, 19.5, 12, 17, 17.5, 15.5, 18, 19, 18, 19
	};

    struct student **sarr = create_struct_table(onoma, am, vathmos);

    show_struct_table(sarr);

    printf("Average grade: %g\n", compute_average_grade(sarr));

    print_failed_names(sarr);
    change_failed_names(sarr);

    show_struct_table(sarr);

	return 0;
}
