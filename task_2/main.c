#include <stdio.h>
#include <stdlib.h>
#define ERROR (-1)
#define swap(t,x,y) t temp = x; x = y; y = temp;

int chek(int argc, char *argv[]){
    if (argc != 3){
        return ERROR;
    }
    if (atoi(argv[1]) < 1){
        return ERROR;
    }
    for (int i = 0; i < atoi(argv[1]); ++i){
        if (argv[2][i] == '\0'){
            return ERROR;
        }
    }
    return 0;
}

void arr_sort(int size, char array[]){
    int counter = 0;
    for (int i = 0; i < size; ++i)
        for (int j = 0; j < (size - 1 - i); ++j)
            if (array[j] > array[j + 1]) {
                swap(char, array[j], array[j + 1]);
                ++counter;}
    printf(" Number of inversions -> %d\n", counter);
    printf("Array -> %s", array);
}

int main(int argc, char *argv[]){
    if (ERROR == chek(argc, argv)){
        printf("Error input\n");
        return -1;}
    arr_sort(atoi(argv[1]), argv[2]);

    return 0;
}
