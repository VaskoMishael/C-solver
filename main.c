#include <stdio.h>
#include "string.h"
#include <stdlib.h>

void makeArrays(int **arr, char input[], int length) {
    int decreasingLength = strlen(input);
    (*arr) = (int *) malloc(sizeof(int) * length);
    for (int i = length - 1; i >= 0; i--) {
        (*arr)[i] = (int) malloc(sizeof(int));
        (*arr)[i] = atoi(&input[decreasingLength - 4]);

        //        printf("%d\n", atoi(&input[decreasingLength - 4]));
        input[decreasingLength - 4] = '\0';

        if (decreasingLength - 4 >= 4) {
            decreasingLength -= 4;
        } else decreasingLength = 4;
    }
}

int main() {
    char input[1000];
    int true = 1, threePlusOne = 0, twoKei = 0, maximumMember = 0, sum = 0;
    while (true) {
        printf("Enter digit:\n");
        scanf("%s", input);
        if (strcmp(input, "x") == 0) {          //stop the program, if input is 'x'
            break;
        }
        int length = strlen(input) / 4 + 1;   //quantity of 4-digit numbers
        int *arr, addDecimals = 0;
        makeArrays(&arr, input, length);    //divide into array

        if (arr[length - 1] % 2 == 0) {
            for (int i = length - 1; i > 0; i--) {
                twoKei += 1;
            }
        } else {
            threePlusOne += 1;
            for (int i = length - 1; i >= 0; i--) {
                arr[i] = arr[i] * 3 + addDecimals;
                if (i == length - 1) {
                    arr[i] += 1;
                }
                if (arr[i] / 10000 > 0) {
                    addDecimals = arr[i] / 10000;
                    arr[i] = arr[i] % 10000;
                } else addDecimals = 0;
            }
        }
        for (int j = 0; j < length; j++) {      //print digit
            if (arr[j] == 0) {
                printf("0000");
            } else if (arr[j] / 10 == 0) {
                printf("%000d", arr[j]);
            } else if (arr[j] / 100 == 0) {
                printf("00%d", arr[j]);
            } else if (arr[j] / 1000 == 0) {
                printf("0%d", arr[j]);
            } else printf("%d", arr[j]);
        }
        printf("\n%d\n", addDecimals);

        for (int l = 0; l < length; ++l) {          //sum of all digits
            sum+=arr[l];
        }
        if (sum == 1) {                             //if its equals 1, therefore,1 is the only number in digit
            printf("Number of 3k+1 operations: %d\nNumber of 2k operations: %d\nMaximum member: %d\n", threePlusOne,
                   twoKei, maximumMember);
        }
    }
    return 0;
}
