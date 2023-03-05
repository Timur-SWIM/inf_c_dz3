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
}

void arr_sort(int size, char array[]){
    for (int i = 0; i < size - 1 - i; ++i)
        for (int j = 0; j < (size - 1); ++j)
            if (array[j] > array[j + 1]) {
                swap(char, array[j], array[j + 1])
            }
}

void print(int size, char string[]){
    char curent_char = string[0];
    int counter = 1;
    for (int i = 1; i < size; ++i){
        if (string[i] != curent_char){
            printf("%c -> %d times\n", curent_char, counter);
            curent_char = string[i];
            counter = 0;
        }
        ++counter;
    }
    printf("%c -> %d times\n", curent_char, counter);
}
int main(int argc, char *argv[]) {
    int i, j, counter = 1;

    if (ERROR == chek(argc, argv)){
        printf("Error input\n");
        return -1;
    }
    arr_sort(atoi(argv[1]), argv[2]);
    print(atoi(argv[1]), argv[2]);

    return 0;
}


