#include <stdio.h>
#include "my_mat.h"

void inputMatrix(int mat[10][10]){
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; ++j) {
            printf("Enter value for mat[%d][%d]: ", i, j);
            scanf("%d", &mat[i][j]);
        }
    }
}

int hasPath(int mat[10][10]){
    int first, last;
    printf("Enter the first node number: ");
    scanf("%d", first);
    printf("Enter the second node number: ");
    scanf("%d", last);
    int beenThere[10] = {0};
    return hasPathHelper(mat, first, last, beenThere);
}

int hasPathHelper(int mat[10][10], int first, int last, int beenThere[10]){
    if(first == last){
        return 1;
    }
    
    beenThere[first] = 1;
    for(int i = 1; i<10; i++){
        if(mat[first][i] != 0 && beenThere[i] != 1){
            if(hasPathHelper(mat, i, last, beenThere)){
                return 1;
            }
        }
    }
    return 0;
}

int shortestPath(int mat[10][10]){
    int D_mat[10][10] = {0};
    for(int i = 0; i < 10; i++){
        for(int j = i; j < 10; j++){
            D_mat[i][j] = mat[i][j];
        }
    }

    for(int k = 1; k < 100; k++){
        for(int i = 1; i < 100; i++){
            for(int j = 1; j < 100; j++){
                if(D_mat[i][j] > D_mat[i][k]+D_mat[k][j]){
                    D_mat[i][j] = D_mat[i][k]+D_mat[k][j];
                }
            }
        }
    }
    int first, last;
    printf("Enter the first node number: ");
    scanf("%d", first);
    printf("Enter the second node number: ");
    scanf("%d", last);
    return D_mat[first][last];
}