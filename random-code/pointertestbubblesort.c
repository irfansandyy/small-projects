#include <stdio.h>
#define MAX_SIZE 8

void bubblesort(int *array) {
    int arrlen = sizeof(array);
    for(int pass = 0; pass < arrlen - 1; pass++) {
        for(int *arptr = array; arptr < (array + (arrlen - 1)); arptr++) {
            if(*arptr > *(arptr+1)) {
                int hold = *(arptr+1);
                *(arptr+1) = *arptr;
                *arptr = hold;
            }
        }
    }
}

int main() {
    int n[MAX_SIZE] = {6, 2, 8, 0, 3, 5, 4, 7};
    int arrlen = (int) sizeof(n)/sizeof(int);

    for(int *arrptr = n; arrptr < n + arrlen; arrptr++) {
        printf("%d", *arrptr);
    }
    bubblesort(n);
    printf("\n");
    for(int *arrptr = n; arrptr < n + arrlen; arrptr++) {
        printf("%d", *arrptr);
    }
}