#include <stdio.h>      

int main(){
    char moskov[5][13];
    for(int row = 0; row < 5; row++){
        for(int col = 1; col <= 5 - 1 * row + 1; col++){
            moskov[row][col] = ' ';
            int mid = col / 2;
            if(col >= (mid - 1 * 3 / 2) && col <= (mid + 1 * 3 / 2)){
                moskov[row][col] = '*';
            }
        }
    }
    for (int row = 0; row < 5; row++){
        for(int col = 0; col < 13; col++){
            printf("%c", moskov[row][col]);
        }
        printf("\n");
    }
    return 0;

}