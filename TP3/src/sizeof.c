#include <stdio.h>

int main()
{
    printf("int : %zu\n", sizeof(int));
    printf("int* : %zu\n", sizeof(int *));
    printf("int** : %zu\n", sizeof(int **));
    printf("char* : %zu\n", sizeof(char *));
    printf("char** : %zu\n", sizeof(char **));
    printf("char*** : %zu\n", sizeof(char ***));
    printf("float* : %zu\n", sizeof(float *));
    printf("float** : %zu\n", sizeof(float **));
    printf("float*** : %zu\n", sizeof(float ***));

    return 0;
}