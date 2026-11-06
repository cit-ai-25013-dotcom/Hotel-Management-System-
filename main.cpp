
#include <iostream>
#include <string>
using namespace std;

class Room {
private:
    int roomNumber;
    string guestName;
    bool booked;

public:
    Room(int number) {
        roomNumber = number;
        guestName = "";
        booked = false;
    }

    void bookRoom() {
        if (booked) {
            cout << "Room is already booked!\n";
        }
        else {
            cout << "Enter Guest Name: ";
            cin.ignore();
            getline(cin, guestName);

            booked = true;
            cout << "Room booked successfully!\n";
        }
    }

    void cancelBooking() {
        if (booked) {
            booked = false;
            guestName = "";
            cout << "Booking cancelled successfully!\n";
        }
        else {
            cout << "Room is not booked!\n";
        }
    }

    void displayRoom() {
        cout << "\nRoom Number: " << roomNumber;
        cout << "\nGuest Name: ";

        if (booked)
            cout << guestName;
        else
            cout << "No Guest";

        cout << "\nStatus: ";

        if (booked)
            cout << "Booked\n";
        else
            cout << "Available\n";
    }

    int getRoomNumber() {
        return roomNumber;
    }
};

int main() {
    Room rooms[5] = {
        Room(101), Room(102), Room(103),
        Room(104), Room(105)
    };

    int choice;
    int number;

    do {
        cout << "\n===== Hotel Management System =====";
        cout << "\n1. Book Room";
        cout << "\n2. Cancel Booking";
        cout << "\n3. Display Rooms";
        cout << "\n4. Search Room";
        cout << "\n5. Exit";
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice) {

        case 1:
        case 2:
        case 4: {
            cout << "Enter Room Number: ";
            cin >> number;

            bool found = false;

            for (int i = 0; i < 5; i++) {
                if (rooms[i].getRoomNumber() == number) {
                    found = true;

                    if (choice == 1)
                        rooms[i].bookRoom();

                    else if (choice == 2)
                        rooms[i].cancelBooking();

                    else
                        rooms[i].displayRoom();

                    break;
                }
            }

            if (!found)
                cout << "Room not found!\n";

            break;
        }

        case 3:
            for (int i = 0; i < 5; i++) {
                rooms[i].displayRoom();
            }
            break;

        case 5:
            cout << "Thank you for using the system!\n";
            break;

        default:
            cout << "Invalid choice!\n";
        }

    } while (choice != 5);

    return 0;
}
