#include <stdio.h>
#include "my_mat.h"
#define SIZE 10

void inputMatrix(int mat[SIZE][SIZE]){
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            printf("Enter value for mat[%d][%d]: ", i, j);
            scanf("%d", &mat[i][j]);
        }
    }
}


int hasPathHelper(int mat[SIZE][SIZE], int first, int last, int beenThere[SIZE]){
    if(first == last){
        return 1;
    }
    
    beenThere[first] = 1;
    for(int i = 1; i<SIZE; i++){
        if(mat[first][i] != 0 && beenThere[i] != 1){
            if(hasPathHelper(mat, i, last, beenThere)){
                return 1;
            }
        }
    }
    return 0;
}


int hasPath(int mat[SIZE][SIZE]){
    int first, last;
    printf("Enter the first node number: ");
    scanf("%d", &first);
    printf("Enter the second node number: ");
    scanf("%d", &last);
    int beenThere[SIZE] = {0};
    int ans = hasPathHelper(mat, first, last, beenThere);
    if(ans == 1){
        printf("True\n");
        return 1;
    }
    if(ans == 0){
        printf("False\n");
        return 0;
    }
    return 1;
}


int shortestPath(int mat[SIZE][SIZE]){
    int D_mat[SIZE][SIZE] = {0};
    for(int i = 0; i < SIZE; i++){
        for(int j = i; j < SIZE; j++){
            D_mat[i][j] = mat[i][j];
        }
    }

    for(int k = 0; k < SIZE; k++){
        for(int i = 0; i < SIZE; i++){
            for(int j = 0; j < SIZE; j++){
                if(D_mat[i][j] == 0 && (i!=j) && D_mat[i][k] != 0 && D_mat[k][j] != 0){
                     D_mat[i][j] = D_mat[i][k]+D_mat[k][j];
                }
                else if(((D_mat[k][j] != 0) && (D_mat[i][k] != 0) && (D_mat[i][j] > D_mat[i][k]+D_mat[k][j]))){
                     D_mat[i][j] = D_mat[i][k]+D_mat[k][j];
                }
            }
        }
    }
    int first, last;
    printf("Enter the first node number: ");
    scanf("%d", &first);
    printf("Enter the second node number: ");
    scanf("%d", &last);
    if(D_mat[first][last] == 0){
        printf("%d", -1);
        return 0;
    }
    else{
        printf("%d", D_mat[first][last]);
        return 1;

    }
}