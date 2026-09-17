#include <stdio.h>
#include <string.h>

int main(void){
    float num_of_hours = 0.0;
    char vehicle_type[6];
    float car_rate_per_hour = 25.00; 
    float bus_rate_per_hour = 50.00; 
    float truck_rate_per_hour = 75.00;
    float total_fee = 0.0;

    printf("Please enter your vehicle you brought (car, bus, truck): ");
    if (scanf("%5s", vehicle_type) != 1) {
        fprintf(stderr, "Failed to read vehicle type\n");
        return 1;
    }

    printf("How many hours did you park your vehicle?: ");
    if (scanf("%f", &num_of_hours) != 1) {
        fprintf(stderr, "Failed to read number of hours\n");
        return 1;
    }

    if (strcmp(vehicle_type, "car") == 0) {
        total_fee = car_rate_per_hour * num_of_hours;
        printf("Your total parking fees for your car is: %.2f\n", total_fee);
    } else if (strcmp(vehicle_type, "bus") == 0) {
        total_fee = bus_rate_per_hour * num_of_hours;
        printf("Your total parking fees for your bus is: %.2f\n", total_fee);
    } else if (strcmp(vehicle_type, "truck") == 0) {
        total_fee = truck_rate_per_hour * num_of_hours;
        printf("Your total parking fees for your truck is: %.2f\n", total_fee);
    } else {
        printf("Unknown vehicle type: %s\n", vehicle_type);
    }

    return 0;
}