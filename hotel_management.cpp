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
        cout << "Customer ID: " << customerId
             << " | Name: " << name
             << " | Age: " << age << endl;
    }
    int getId() {
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
        cout << "Staff: " << name 
             << " | Age: " << age 
             << " | Position: " << position << endl;
    }
};

class Room {
    int roomNumber;
    bool booked;
public:
    Room(int num) {
        roomNumber = num;
        booked = false;
    }
    int getNumber() {
        return roomNumber;
    }
    bool isBooked() {
        return booked;
    }
    void book() {
        booked = true;
    }
    void showRoom() {
        cout << "Room " << roomNumber 
             << " | " << (booked ? "Booked" : "Available") << endl;
    }
};

class Hotel {
    vector<Room> rooms;
public:
    Hotel() {
        rooms.push_back(Room(101));
        rooms.push_back(Room(102));
        rooms.push_back(Room(201));
    }

    void showRooms() {
        for (auto &r : rooms)
            r.showRoom();
    }

    void bookRoom(Customer &c) {
        int num;
        cout << "Enter room number to book: ";
        cin >> num;

        for (auto &r : rooms) {
            if (r.getNumber() == num) {
                if (r.isBooked()) {
                    cout << "Room already booked.\n";
                    return;
                }
                r.book();
                cout << "Room booked successfully by Customer ID: "
                     << c.getId() << endl;
                return;
            }
        }
        cout << "Invalid room number.\n";
    }
};

int main() {
    Hotel h;
    Customer c1("Tushar", 21, 1);
    Staff s1("Ravi", 30, "Manager");

    int choice;
    do {
        cout << "\n1. Show Rooms\n"
             << "2. Book Room\n"
             << "3. Show Customer Details\n"
             << "4. Show Staff Details\n"
             << "5. Exit\n"
             << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1: h.showRooms(); break;
            case 2: h.bookRoom(c1); break;
            case 3: c1.showDetails(); break;
            case 4: s1.showDetails(); break;
            case 5: cout << "Exiting...\n"; break;
            default: cout << "Invalid choice!\n";
        }

    } while (choice != 5);

    return 0;
}
