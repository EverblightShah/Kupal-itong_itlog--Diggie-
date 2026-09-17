#include <stdio.h>

int main(){
    
    int hours, parkingcharge;
    char vehicle;
    
    printf("C - Car\nB - Bus\nT - Truck\n\nWhat Type of Vehicle: ");
    scanf("%c", &vehicle);
    
    printf("How Many Hours: ");
    scanf("%d", &hours);
    
    if(vehicle == 'C' || vehicle == 'c'){
        parkingcharge = hours * 25;
        printf("\nParking Charge: %d PHP", parkingcharge);
    }
    else if(vehicle == 'B' || vehicle == 'b'){
        parkingcharge = hours * 50;
        printf("\nParking Charge: %d PHP", parkingcharge);
    }
    else if(vehicle == 'T' || vehicle == 't'){
        parkingcharge = hours * 75;
        printf("\nParking Charge: %d PHP", parkingcharge);
    }
    else{
        printf("\nInvalid Response.");
    }
    
    return 0;
}
