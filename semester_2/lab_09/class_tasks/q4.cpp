#include<iostream>
#include<string>
#include<vector>
using namespace std;

class Flight {
    string flightNumber, departure, arrival;
    int capacity, bookedSeats;

public:
    Flight(string fn, string dep, string arr, int cap)
        : flightNumber(fn), departure(dep), arrival(arr), capacity(cap), bookedSeats(0) {}

    bool bookSeat() {
        if (bookedSeats < capacity) {
            bookedSeats++;
            return true;
        }
        return false;
    }

    bool cancelSeat() {
        if (bookedSeats > 0) {
            bookedSeats--;
            return true;
        }
        return false;
    }

    int getAvailableSeats() const {
        return capacity - bookedSeats;
    }
};

class Passenger {
    string name;
public:
    Passenger(string n) : name(n) {}

    bool requestBooking(Flight& flight) {
        return flight.bookSeat();
    }

    bool cancelBooking(Flight& flight) {
        return flight.cancelSeat();
    }
};

int main() {
    Flight flight("PK101", "Lahore", "Karachi", 2);
    Passenger p1("Ali"), p2("Ahmed");

    p1.requestBooking(flight);
    p2.requestBooking(flight);
    cout << flight.getAvailableSeats() << endl;
}