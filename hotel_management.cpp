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

class Client : public Person {
    int clientId;
public:
    Client(string n, int a, int id) : Person(n, a) {
        clientId = id;
    }
    void showDetails() override {
        cout << "Client ID: " << clientId
             << " | Name: " << name
             << " | Age: " << age << endl;
    }
    int getClientId() {
        return clientId;
    }
};

class Appointment {
    int appointmentId;
    string date;
    Client client;
public:
    Appointment(int id, string d, Client c) : client(c) {
        appointmentId = id;
        date = d;
    }
    void showAppointment() {
        cout << "Appointment ID: " << appointmentId
             << " | Date: " << date
             << " | Client: " << client.getClientId() << endl;
    }
};

class Clinic {
    vector<Appointment> appointments;
public:
    void bookAppointment(Client &c) {
        string date;
        cout << "Enter appointment date (DD/MM/YYYY): ";
        cin >> date;

        int id = appointments.size() + 1;
        appointments.push_back(Appointment(id, date, c));

        cout << "Appointment booked successfully.\n";
    }

    void showAppointments() {
        if (appointments.empty()) {
            cout << "No appointments yet.\n";
            return;
        }
        for (auto &a : appointments)
            a.showAppointment();
    }
};

int main() {
    Clinic clinic;
    Client c1("Tushar", 21, 1);

    int choice;
    do {
        cout << "\n1. Book Appointment\n"
             << "2. Show Appointments\n"
             << "3. Show Client Details\n"
             << "4. Exit\n"
             << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1: clinic.bookAppointment(c1); break;
            case 2: clinic.showAppointments(); break;
            case 3: c1.showDetails(); break;
            case 4: cout << "Exiting...\n"; break;
            default: cout << "Invalid choice!\n";
        }
    } while (choice != 4);

    return 0;
}
