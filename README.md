✈️ Airplane Reservation System (C++)

A simple and complete Airplane Reservation System built in C++, featuring seat booking, flight selection, fare viewing, booking cancellation, and seating plan display.
This project is ideal for beginners learning arrays, structs, and functions in C++.

📌 Features
✅ Seat Booking by Class

First Class (Rows 1–2)

Business Class (Rows 3–4)

Economy Class (Rows 5–12)

Each booking automatically:

Generates a unique Booking ID (BKxxxx)

Stores passenger name

Calculates total fare

Prints a ticket receipt

✅ Predefined Flights

Includes 6 predefined flights with:

Departure city

Destination city

Departure time

Example routes:

Karachi → Islamabad

Lahore → Dubai

Islamabad → Karachi

Karachi → Lahore

✅ Seating Plan

Displays a 12×7 seat grid:

0 = Available

1 = Booked

✅ Remaining Seats Viewer

Shows available seats by class:

First Class

Business Class

Economy Class

✅ Fare Chart

First Class: 18,000 PKR

Business Class: 14,000 PKR

Economy Class: 10,000 PKR

✅ Booking Cancellation

Cancel any booking by entering the Booking ID.
All seats booked under that ID are released automatically.

✅ Interactive Menu

Menu options include:

Book First Class

Book Business Class

Book Economy Class

View Seating Plan

View Fares

View Remaining Seats

Cancel Booking

View Available Flights

Exit

🧠 Concepts Used
Concept	Description
2D Arrays	For airplane seating layout (12×7)
Structs	For storing flight information
Functions	For booking, cancellation, display, and counting
Loops	Used in menus and seat reservation
Manual ID Generation	Creates unique BKxxxx booking IDs
Strings	To store names and IDs
📁 Project Structure
AirplaneReservation.cpp


Everything is implemented inside one C++ file.

🚀 How to Compile & Run
Compile
g++ AirplaneReservation.cpp -o reservation

Run
./reservation

🧾 Sample Ticket Output
-----------------------------
       TICKET RECEIPT
Passenger: Ali
Booking ID: BK1004
Class: Economy Class
Fare per seat: 10000 PKR
Total Fare: 20000 PKR
Departure: Karachi
Destination: Lahore
Time: 06:00 AM
-----------------------------

🔮 Future Enhancements

Add file storage (save/load bookings)

Admin login system

Modify or rebook seats

Add GUI using Qt or SFML

Add dynamic pricing / seat selection

👩‍💻 Author

Muskaan
Airplane Reservation System — C++ Project
