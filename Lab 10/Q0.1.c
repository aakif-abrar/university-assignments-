// Write a program that uses structures to manage flight information, including flight number, departure city, destination city, date, and available seats. Create functionalities to book a seat and display flight details.
#include <stdio.h>
#include <string.h>
typedef struct {
    int flightNumber;
    char departureCity[30], destinationCity[30], date[15];
    int availableSeats;
} Flight;
void displayFlightDetails(Flight flight) {
    printf("Flight %d: %s to %s on %s, Seats Available: %d\n", flight.flightNumber, flight.departureCity, flight.destinationCity, flight.date, flight.availableSeats);
}
void bookSeat(Flight *flight) {
    if (flight->availableSeats > 0) {
        flight->availableSeats--;
        printf("Seat booked successfully! Remaining seats: %d\n", flight->availableSeats);
    } else {
        printf("No seats available!\n");
    }
}
int main() {
    Flight flight = {101, "New York", "Los Angeles", "2024-12-01", 5};
    displayFlightDetails(flight);
    bookSeat(&flight);
    displayFlightDetails(flight);
    return 0;
}
