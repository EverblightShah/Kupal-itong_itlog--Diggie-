#include <stdio.h>

int main(){
    
    char classID;    
    
    printf("Class ID: ");
    scanf("%c", &classID);
    
    if(classID == 'B' || classID == 'b'){
        printf("\nClass Type is Battleship");
    }
    else if(classID == 'C' || classID == 'c'){
        printf("\nClass Type is Cruiser");
    }
    else if(classID == 'D' || classID == 'd'){
        printf("\nClass Type is Destroyer");
    }
    else if(classID == 'F' || classID == 'f'){
        printf("\nClass Type is Trigate");
    }
    else{
        printf("\nNot a War Ship");
    }
    
    return 0;
}