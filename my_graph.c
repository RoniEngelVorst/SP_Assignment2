#include <stdio.h>
#include "my_mat.h"
#define SIZE 10

int main(){
    int mat[SIZE][SIZE] = {0};
    char userInput;
    while (userInput != 'D' && userInput != EOF)
    {
        scanf("%c", &userInput);
        
        if(userInput == 'A'){
            inputMatrix(mat);
        }
        if(userInput == 'B'){
            hasPath(mat);
        }
        if(userInput == 'C'){
            shortestPath(mat);
            printf("\n");
        }

    }
    return 0;
}


