#include <stdio.h>
#include "string.h"
#include <stdlib.h>

void makeArrays(int **arr, char input[], int length) {
    int decreasingLength = strlen(input);
    (*arr) = (int *) malloc(sizeof(int) * length);
    for (int i = length - 1; i >= 0; i--) {
        (*arr)[i] = (int) malloc(sizeof(int));

//        printf("%d\n", atoi(&input[decreasingLength - 4]));
        (*arr)[i] = atoi(&input[decreasingLength - 4]);
        input[decreasingLength - 4] = '\0';

        if (decreasingLength - 4 >= 4) {
            decreasingLength -= 4;
        } else decreasingLength = 4;
    }
}

int main() {
    char input[1000];
    int true = 1, threePlusOne = 0, twoKei = 0, maximumMember = 0;
    while (true) {
        printf("Enter digit:\n");
        scanf("%s", input);
        if (strcmp(input, "x") == 0) {          //stop the program, if input is 'x'
            break;
        }
        int length = strlen(input) / 4 + 1;   //quantity of 4-digit numbers
        int *arr;
        makeArrays(&arr, input, length);    //divide into array

        for (int j = 0; j < length; j++) {      //print digit
            printf("%d", arr[j]);
        }
        if (arr[length - 1] % 2 == 0) {
            for (int i = length - 1; i > 0; i--) {

            }
        } else {
            for (int i = length - 1; i > 0; i--) {
                arr[i] = arr[i] * 3 + 1;
            }
        }

        if (arr[0] == 1) {
            printf("Number of 3k+1 operations: %d\nNumber of 2k operations: %d\nMaximum member: %d\n", threePlusOne,
                   twoKei, maximumMember);
        }
    }
    return 0;
}
