#include <iostream>
#include <string>
using namespace std;

const int ROWS = 12;
const int COLS = 7;

string passengerNames[ROWS][COLS];
string bookingIDs[ROWS][COLS];
int bookingCounter = 1000;

// Flight info struct
struct Flight {
    string departure;
    string destination;
    string time;
};

// Predefined flights
Flight flights[6] = {
    {"Karachi", "Islamabad", "08:00 AM"},
    {"Lahore", "Dubai", "09:30 AM"},
    {"Islamabad", "Karachi", "02:00 PM"},
    {"Karachi", "Lahore", "06:00 AM"},
    {"Islamabad", "Dubai", "01:00 PM"},
    {"Lahore", "Karachi", "05:00 PM"}
};

// Count available seats in a range of rows
int countSeats(int Seats[][COLS], int startRow, int endRow) {
    int available = 0;
    for (int i = startRow; i < endRow; i++)
        for (int j = 0; j < COLS; j++)
            if (Seats[i][j] == 0)
                available++;
    return available;
}

// Generate Booking ID manually
string generateBookingID() {
    bookingCounter++;
    int temp = bookingCounter;
    string numStr = "";
    while(temp > 0) {
        char digit = (temp % 10) + '0';
        numStr = digit + numStr;
        temp = temp / 10;
    }
    return "BK" + numStr;
}

// Booking function
bool bookSeats(int Seats[][COLS], int startRow, int endRow, int noOfSeats, string passenger, int farePerSeat, int flightChoice, string className) {

    if(noOfSeats <= 0) {
        cout << "Invalid number of seats.\n";
        return false;
    }

    if(countSeats(Seats, startRow, endRow) < noOfSeats) {
        cout << "Not enough seats available.\n";
        return false;
    }

    string bookingID = generateBookingID();
    int totalFare = farePerSeat * noOfSeats;

    // Reserve seats
    for(int i = startRow; i < endRow; i++) {
        for(int j = 0; j < COLS && noOfSeats > 0; j++) {
            if(Seats[i][j] == 0) {
                Seats[i][j] = 1;
                passengerNames[i][j] = passenger;
                bookingIDs[i][j] = bookingID;
                noOfSeats--;
            }
        }
    }

    // Print ticket receipt
    cout << "\n-----------------------------\n";
    cout << "       TICKET RECEIPT\n";
    cout << "Passenger: " << passenger << endl;
    cout << "Booking ID: " << bookingID << endl;
    cout << "Class: " << className << endl;
    cout << "Fare per seat: " << farePerSeat << " PKR" << endl;
    cout << "Total Fare: " << totalFare << " PKR" << endl;
    cout << "Departure: " << flights[flightChoice].departure << endl;
    cout << "Destination: " << flights[flightChoice].destination << endl;
    cout << "Time: " << flights[flightChoice].time << endl;
    cout << "-----------------------------\n";

    return true;
}

// Cancel booking by ID
void cancelBooking(int Seats[][COLS], string id) {
    bool found = false;
    for(int i = 0; i < ROWS; i++)
        for(int j = 0; j < COLS; j++)
            if(bookingIDs[i][j] == id) {
                Seats[i][j] = 0;
                passengerNames[i][j] = "";
                bookingIDs[i][j] = "";
                found = true;
            }
    if(found)
        cout << "Booking cancelled.\n";
    else
        cout << "Booking ID not found.\n";
}

// View remaining seats per class
void viewRemainingSeats(int Seats[][COLS]) {
    cout << "\nRemaining Seats:\n";
    cout << "First Class: " << countSeats(Seats, 0, 2) << endl;
    cout << "Business Class: " << countSeats(Seats, 2, 4) << endl;
    cout << "Economy Class: " << countSeats(Seats, 4, ROWS) << endl;
}

// View seating plan
void viewSeatingPlan(int Seats[][COLS]) {
    cout << "\nSeating Plan (0=Available, 1=Booked)\n";
    for(int i = 0; i < ROWS; i++) {
        cout << "Row " << i+1 << ": ";
        for(int j = 0; j < COLS; j++)
            cout << Seats[i][j] << " ";
        cout << endl;
    }
}

// Display fare per class
void getFare() {
    cout << "\nFares:\n";
    cout << "First Class: Rs. 18000\n";
    cout << "Business Class: Rs. 14000\n";
    cout << "Economy Class: Rs. 10000\n";
}

// Display available flights
void displayFlights() {
    cout << "\nAvailable Flights:\n";
    for(int i = 0; i < 6; i++) {
        cout << i+1 << ". " << flights[i].departure 
             << " -> " << flights[i].destination 
             << " | Time: " << flights[i].time << endl;
    }
}

// Main program
int main() {
    int Seats[ROWS][COLS] = {0};
    int choice, noOfSeats, flightChoice;
    string passenger, cancelID;

    do {
        cout << "\n------------------------------\n";
        cout << "Airplane Reservation System\n";
        cout << "------------------------------\n";
        cout << "1. Book First Class\n";
        cout << "2. Book Business Class\n";
        cout << "3. Book Economy Class\n";
        cout << "4. View Seating Plan\n";
        cout << "5. View Fares\n";
        cout << "6. View Remaining Seats\n";
        cout << "7. Cancel Booking\n";
        cout << "8. View Available Flights\n";
        cout << "9. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch(choice) {
            case 1:
            case 2:
            case 3:
                displayFlights();
                cout << "Select Flight (1-6): ";
                cin >> flightChoice;
                flightChoice--; // adjust index

                cout << "Enter passenger name (no spaces): ";
                cin >> passenger;
                cout << "Enter number of seats: ";
                cin >> noOfSeats;

                if(choice == 1)
                    bookSeats(Seats, 0, 2, noOfSeats, passenger, 18000, flightChoice, "First Class");
                else if(choice == 2)
                    bookSeats(Seats, 2, 4, noOfSeats, passenger, 14000, flightChoice, "Business Class");
                else
                    bookSeats(Seats, 4, ROWS, noOfSeats, passenger, 10000, flightChoice, "Economy Class");
                break;

            case 4:
                viewSeatingPlan(Seats);
                break;

            case 5:
                getFare();
                break;

            case 6:
                viewRemainingSeats(Seats);
                break;

            case 7:
                cout << "Enter Booking ID to cancel: ";
                cin >> cancelID;
                cancelBooking(Seats, cancelID);
                break;

            case 8:
                displayFlights();
                break;

            case 9:
                cout << "Thank You for using Our Airplane Reservation System...\n";
                break;

            default:
                cout << "Invalid choice.\n";
        }

    } while(choice != 9);

    return 0;
}

