#include <stdio.h>
#include <stdlib.h>

typedef u_int8_t byte;

void getArrElemVals(int **arrPtr, int len);
void allocateArray_int(int **arrPtr, byte arrLen);
void swap_int(int *a, int *b);
void selectionSort(int **arrPtr, byte arrLen);
void printArrElems(int *arr, byte arrLen);

/*/ The Main Program /*/
int main() {

    // Variables
    auto int *arr;
    auto byte arrLen;

    // Get Array with It's Length
    printf( "Please enter a length for array: " );
    scanf("%i", &arrLen);

    // Exit If The Length is Greater than 255
    if(arrLen > 255) exit(0);

    // Allocated Array and Point to It
    allocateArray_int(&arr, arrLen);

    // Get Value of Elements from User
    getArrElemVals(&arr, arrLen);

    // Sort The Array Using Selection Sort Algorithm
    selectionSort(&arr, arrLen);

    // Print Array Elements
    printArrElems(arr, arrLen);

    free(arr);
    return 0;
}

/*/ Get Value of Array Elements from User Input /*/
void getArrElemVals(int **arrPtr, int len){

    for( register byte i = 0; i < len; i++ ){

        printf("Value of Index %i: ", i);
        scanf( "%i", (*arrPtr + i) );

    }

}

/*/ Point to Allocated Array /*/
void allocateArray_int(int **arrPtr, byte arrLen){

    *arrPtr = calloc( (size_t) arrLen, sizeof(int) );

    if (*arrPtr == NULL) {
        printf("\nArray Allocation FAILED !!!\n");
        exit(0);
    }

}

/*/ Swap Values /*/
void swap_int(int *a, int *b){

    auto int tmp = *a;
    *a = *b;
    *b = tmp;

}

/*/ Sort Array Using Selection Sort Algorithm /*///e.g. {12, 6, 9, 11, 7, 10, 2, 5, 3, 1, 4, 8}
void selectionSort(int **arrPtr, byte arrLen){


    for (register byte i = arrLen - 1; i > 0; i--) {

        // Store The Max Value of This Gauging
        int thisMaxValue = 0;
        register byte thisMaxValueIndex = 0;

        for (register byte j = 0; j < i + 1; j++) {

            if ( *(*arrPtr + j) > thisMaxValue ) {

                thisMaxValue = *(*arrPtr + j);
                thisMaxValueIndex = j;

            }

        }

        swap_int(*arrPtr + thisMaxValueIndex, *arrPtr + i);

    }

}

/*/ Show Array Elements /*/
void printArrElems(int *arr, byte arrLen){

    for (register byte i = 0; i < arrLen; i++)
        printf("%i, ", *(arr + i));

    printf("\b\b\n");

}