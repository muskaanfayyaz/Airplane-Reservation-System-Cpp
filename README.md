# Airplane Reservation System

A simple C++ console application for managing airplane seat reservations. This project provides a basic but functional command-line interface for booking and managing airline seats for a single aircraft.

## Features

*   **Book Seats:** Reserve seats in First, Business, and Economy classes for different flights.
*   **Cancel Bookings:** Cancel an existing reservation using a unique booking ID.
*   **View Seating Plan:** Display the current seating arrangement, showing which seats are available (`0`) and which are booked (`1`).
*   **View Fares:** Check the ticket prices for First, Business, and Economy classes.
*   **View Remaining Seats:** See the number of available seats in each class.
*   **View Available Flights:** List all available flights with their departure, destination, and time.

## Project Structure

```
.
├── airplane reservation system.cpp
├── airplane reservation system.exe
└── README.md
```

*   `airplane reservation system.cpp`: The main C++ source code file containing all the logic for the reservation system.
*   `airplane reservation system.exe`: The compiled executable file (on Windows).
*   `README.md`: This file.

## Code Details

### Data Structures

*   **`Seats[ROWS][COLS]`**: A 2D integer array representing the seating plan of the aircraft. A value of `0` means the seat is available, and `1` means it is booked.
*   **`passengerNames[ROWS][COLS]`**: A 2D string array to store the name of the passenger for each booked seat.
*   **`bookingIDs[ROWS][COLS]`**: A 2D string array to store the unique booking ID associated with each reserved seat.
*   **`Flight` struct**: A structure to hold flight information, including `departure`, `destination`, and `time`.
*   **`flights[]` array**: An array of `Flight` structs, pre-populated with a list of available flights.

### Key Functions

*   `main()`: The main entry point of the program. It contains the main menu loop and handles user input.
*   `bookSeats()`: Manages the seat booking process. It checks for seat availability, calculates the fare, reserves the seats, and prints a ticket receipt.
*   `cancelBooking()`: Cancels a reservation by searching for the provided booking ID and resetting the seat status.
*   `viewSeatingPlan()`: Renders the current layout of the aircraft seats, showing available and booked spots.
*   `countSeats()`: A utility function that returns the number of available seats within a specified range of rows.
*   `generateBookingID()`: Creates a unique booking ID for each new reservation.

## How to Compile and Run

To use this program, you need a C++ compiler (like G++).

1.  **Compile the code:**
    Open your terminal or command prompt and run the following command:
    ```bash
    g++ "airplane reservation system.cpp" -o "airplane reservation system.exe"
    ```

2.  **Run the executable:**
    Execute the compiled program:
    ```bash
    ./"airplane reservation system.exe"
    ```

## Example Usage

Once the program is running, you will be presented with the main menu.

### Booking a Ticket

1.  Select option `1`, `2`, or `3` to book a seat in First, Business, or Economy class.
2.  The system will display a list of available flights.
3.  Choose a flight by entering its number (e.g., `1`).
4.  Enter your name (e.g., `john`).
5.  Enter the number of seats you want to book (e.g., `2`).
6.  If seats are available, a ticket receipt will be printed to the console:

```
-----------------------------
       TICKET RECEIPT
Passenger: john
Booking ID: BK1001
Class: First Class
Fare per seat: 18000 PKR
Total Fare: 36000 PKR
Departure: Karachi
Destination: Islamabad
Time: 08:00 AM
-----------------------------
```

### Canceling a Booking

1.  Select option `7` from the main menu.
2.  Enter the `Booking ID` from your receipt (e.g., `BK1001`).
3.  The system will confirm the cancellation.

## Contributing

Contributions are welcome! If you have suggestions for improvements or find any bugs, please feel free to open an issue or submit a pull request.

1.  Fork the repository.
2.  Create a new branch (`git checkout -b feature/YourFeature`).
3.  Commit your changes (`git commit -m 'Add some feature'`).
4LAG.  Push to the branch (`git push origin feature/YourFeature`).
5.  Open a Pull Request.

## License

This project is licensed under the MIT License. See the [LICENSE](LICENSE) file for details (if applicable).
