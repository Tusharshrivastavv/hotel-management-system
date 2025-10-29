#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Person {
protected:
    string name;
    int age;
public:
    Person(string n, int a) {
        name = n;
        age = a;
    }
    virtual void showDetails() = 0;
};

class Customer : public Person {
    int customerId;
public:
    Customer(string n, int a, int id) : Person(n, a) {
        customerId = id;
    }
    void showDetails() override {
        cout << "Customer ID: " << customerId << " Name: " << name << " Age: " << age << endl;
    }
    int getCustomerId() {
        return customerId;
    }
};

class Staff : public Person {
    string position;
public:
    Staff(string n, int a, string p) : Person(n, a) {
        position = p;
    }
    void showDetails() override {
        cout << "Staff: " << name << " Age: " << age << " Position: " << position << endl;
    }
};

class Room {
    int roomNumber;
    string roomType;
    bool isBooked;
public:
    Room(int num, string type) {
        roomNumber = num;
        roomType = type;
        isBooked = false;
    }
    int getRoomNumber() {
        return roomNumber;
    }
    string getRoomType() {
        return roomType;
    }
    bool getIsBooked() {
        return isBooked;
    }
    void bookRoom() {
        isBooked = true;
    }
    void freeRoom() {
        isBooked = false;
    }
    void showRoom() {
        cout << "Room " << roomNumber << " " << roomType << " " << (isBooked ? "Booked" : "Available") << endl;
    }
};

class Booking {
    int bookingId;
    Customer customer;
    Room* room;
public:
    Booking(int id, Customer c, Room* r) : customer(c) {
        bookingId = id;
        room = r;
    }
    void showBooking() {
        cout << "Booking ID: " << bookingId << " Customer: " << customer.getCustomerId()
             << " Room: " << room->getRoomNumber() << " " << room->getRoomType() << endl;
    }
};

class Hotel {
    vector<Room> rooms;
    vector<Booking> bookings;
public:
    Hotel() {
        rooms.push_back(Room(101, "Single"));
        rooms.push_back(Room(102, "Double"));
        rooms.push_back(Room(201, "Deluxe"));
    }
    void showRooms() {
        for (int i = 0; i < rooms.size(); i++)
            rooms[i].showRoom();
    }
    void bookRoom(Customer &c) {
        int roomNo;
        cout << "Enter room number: ";
        cin >> roomNo;
        for (int i = 0; i < rooms.size(); i++) {
            if (rooms[i].getRoomNumber() == roomNo && !rooms[i].getIsBooked()) {
                rooms[i].bookRoom();
                bookings.push_back(Booking(bookings.size() + 1, c, &rooms[i]));
                cout << "Room booked successfully." << endl;
                return;
            }
        }
        cout << "Room not available." << endl;
    }
    void showBookings() {
        for (int i = 0; i < bookings.size(); i++)
            bookings[i].showBooking();
    }
};

int main() {
    Hotel h;
    Customer c1("Tushar", 21, 1);
    Staff s1("Ravi", 30, "Manager");

    int choice;
    do {
        cout << "\n1. Show Rooms\n2. Book Room\n3. Show Bookings\n4. Show Staff\n5. Exit\nEnter choice: ";
        cin >> choice;
        switch (choice) {
            case 1: h.showRooms(); break;
            case 2: h.bookRoom(c1); break;
            case 3: h.showBookings(); break;
            case 4: s1.showDetails(); break;
            case 5: cout << "Exiting...\n"; break;
            default: cout << "Invalid choice\n";
        }
    } while (choice != 5);

    return 0;
}
