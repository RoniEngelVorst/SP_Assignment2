#include <stdio.h>
#define SIZE2 5
#define LIMIT 20



int knapSack (int weights[], int values[] , int selected_bool[]){
    int mat[SIZE2 + 1][LIMIT + 1] = {0};
    for(int i = 1; i < SIZE2 + 1; i++){
        int wt = weights[i-1];
        int val = values[i-1];
        for(int j = 1; j <LIMIT + 1; j++){
            if(wt > j){
                mat[i][j] = mat[i-1][j];
            }
            else{
                if(mat[i-1][j] > mat[i-1][j-wt]+val){
                    mat[i][j] = mat[i-1][j];
                }
                else{
                    mat[i][j] = mat[i-1][j-wt]+val;
                }
            }
        }
    }

    int w = LIMIT;
    for(int i = SIZE2; i > 0; i--){
        int was_added = mat[i][w] != mat[i-1][w];
        if(was_added){
            int wt = weights[i-1];
            selected_bool[i-1] = 1;
            w = w-wt;
        }
    }

    return mat[SIZE2][LIMIT];

}


int main(){
    char items[SIZE2];
    int values[SIZE2];
    int weights[SIZE2];
    //getting the input from the user
    for(int i = 0; i < SIZE2; i++){
        scanf(" %c", &items[i]);
        scanf("%d", &values[i]);
        scanf("%d", &weights[i]);
    }
    int result[SIZE2] = {0};
    printf("calculating");
    int ans = knapSack(weights, values, result);
    printf("Maximum profit: %d\n", ans);
    printf("Selected items: ");
    for(int i = 0; i < SIZE2; i++){
        if(result[i] == 1){
            printf("%c ", items[i]);
        }
    }
    printf("\n");


    return 0;
}


