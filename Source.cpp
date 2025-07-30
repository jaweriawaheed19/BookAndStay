#include <iostream>
#include <string>
#include <iomanip>
#include <ctime>
using namespace std;

const int MAX_ROOMS = 10;
const int MAX_CUSTOMERS = 10;
const int MAX_FOOD_ITEMS = 10;

// Abstract Class for Polymorphism
class Person {
public:
	virtual void showDetails() = 0;
};

// Room Class (Encapsulation)
class Room {
private:
	int roomNumber;
	string roomType;
	double roomPrice;
	bool isOccupied;

public:
	Room() : roomNumber(0), roomType(""), roomPrice(0.0), isOccupied(false) {}

	void setRoom(int number, string type, double price) {
		roomNumber = number;
		roomType = type;
		roomPrice = price;
	}

	void occupy() { isOccupied = true; }
	void vacate() { isOccupied = false; }

	bool getOccupied() const { return isOccupied; }
	int getRoomNumber() const { return roomNumber; }
	string getRoomType() const { return roomType; }
	double getRoomPrice() const { return roomPrice; }
};

// Food Class (Encapsulation)
class Food {
private:
	string foodName;
	double price;

public:
	Food() : foodName(""), price(0.0) {}

	void setFood(string name, double p) {
		foodName = name;
		price = p;
	}

	string getName() const { return foodName; }
	double getPrice() const { return price; }
};

// Customer Class (Inheritance + Polymorphism)
class Customer : public Person {
private:
	string name;
	int roomNumbers[MAX_ROOMS];
	int roomCount;
	double totalBill;
	bool hasFoodOrdered[MAX_FOOD_ITEMS];
	time_t bookingTime;
	bool isCheckedIn;

public:
	Customer() {
		name = "";
		roomCount = 0;
		totalBill = 0.0;
		isCheckedIn = false;
		for (int i = 0; i < MAX_FOOD_ITEMS; ++i)
			hasFoodOrdered[i] = false;
	}

	void setName(const string& n) { name = n; }
	string getName() const { return name; }

	void setRoom(int index, int roomNumber) {
		roomNumbers[index] = roomNumber;
	}

	int getRoom(int index) const {
		return roomNumbers[index];
	}

	void setRoomCount(int count) { roomCount = count; }
	int getRoomCount() const { return roomCount; }

	void setTotalBill(double bill) { totalBill = bill; }
	void addToBill(double amount) { totalBill += amount; }
	double getTotalBill() const { return totalBill; }

	void setCheckedIn(bool status) { isCheckedIn = status; }
	bool getCheckedIn() const { return isCheckedIn; }

	void setBookingTime(time_t t) { bookingTime = t; }
	time_t getBookingTime() const { return bookingTime; }

	void orderFood(int index) { hasFoodOrdered[index] = true; }
	void cancelFood(int index) { hasFoodOrdered[index] = false; }
	bool hasOrdered(int index) const { return hasFoodOrdered[index]; }

	void showDetails() override {
		cout << "\nCustomer Name: " << name << "\n";
		cout << "Room Count: " << roomCount << "\n";
		cout << "Rooms Booked: ";
		for (int i = 0; i < roomCount; ++i)
			cout << roomNumbers[i] << " ";
		cout << "\nTotal Bill: $" << totalBill << "\n";
		cout << "Status: " << (isCheckedIn ? "Checked-In" : "Not Checked-In") << "\n";
	}
};

// Hotel Management System Class (Abstraction + Logic)
class HotelManagementSystem {
private:
	Room rooms[MAX_ROOMS];
	Customer customers[MAX_CUSTOMERS];
	Food foodItems[MAX_FOOD_ITEMS];

public:
	HotelManagementSystem() {
		initializeRooms();
		initializeFoodItems();
	}

	void run();

private:
	void initializeRooms();
	void initializeFoodItems();
	void displayMenu();
	void displayRooms();
	void displayFoodMenu();
	void bookRoom();
	void checkIn();
	void checkOut();
	void viewBill();
	void addFoodItem();
	void orderFood();
	void cancelRoomBooking();
	void cancelFoodOrder();
	void viewCustomerDetails();
	double calculateCancellationFee(time_t);
	int findCustomerIndex(const string&);
};

void HotelManagementSystem::initializeRooms() {
	for (int i = 0; i < MAX_ROOMS; i++) {
		rooms[i].setRoom(i + 1, (i % 2 == 0 ? "Single" : "Double"), (i % 2 == 0 ? 2500 : 4000));
	}
}

void HotelManagementSystem::initializeFoodItems() {
	string names[MAX_FOOD_ITEMS] = {
		"MacnCheese", "Lobster", "Tiramisu", "Beef Steak", "Churro",
		"Pizza Bread", "Prawns", "Chowmein", "", ""
	};
	double prices[MAX_FOOD_ITEMS] = {
		12.99, 19.99, 22.99, 25.99, 15.99,
		13.49, 10.99, 10.49, 0.0, 0.0
	};
	for (int i = 0; i < MAX_FOOD_ITEMS; i++)
		foodItems[i].setFood(names[i], prices[i]);
}

void HotelManagementSystem::displayMenu() {
	cout << "\n==== Book And Stay ====\n";
	cout << "1.  Display Rooms\n";
	cout << "2.  Book Room\n";
	cout << "3.  Check-In\n";
	cout << "4.  Check-Out\n";
	cout << "5.  View Bill\n";
	cout << "6.  Add Food Item\n";
	cout << "7.  Order Food\n";
	cout << "8.  Display Food Menu\n";
	cout << "9.  Cancel Room Booking\n";
	cout << "10. Cancel Food Order\n";
	cout << "11. View Customer Details\n";
	cout << "12. Exit\n";
}

int HotelManagementSystem::findCustomerIndex(const string& name) {
	for (int i = 0; i < MAX_CUSTOMERS; i++)
		if (customers[i].getName() == name)
			return i;
	return -1;
}

void HotelManagementSystem::displayRooms() {
	cout << "\nAvailable Rooms:\n";
	cout << "-------------------------------------------------" << endl;
	cout << "|Rooms\t\t|Type\t\t|Price\t\t|" << endl;
	cout << "-------------------------------------------------" << endl;
	for (int i = 0; i < MAX_ROOMS; i++)
		if (!rooms[i].getOccupied())
			cout << "|Room " << rooms[i].getRoomNumber() << " \t|" << rooms[i].getRoomType() << "\t\t|$" << rooms[i].getRoomPrice() << " \t\t|\n";
	cout << "-------------------------------------------------" << endl;

}

void HotelManagementSystem::displayFoodMenu() {
	cout << "\nFood Menu:\n";
	cout << "---------------------------------" << endl;
	cout << "|No.\t|Item\t\t|Price\t|" << endl;
	cout << "---------------------------------" << endl;

	for (int i = 0; i < MAX_FOOD_ITEMS; i++)
		if (!foodItems[i].getName().empty())
			cout << "|" << i + 1 << ". \t|" << foodItems[i].getName() << " \t| $" << foodItems[i].getPrice() << "|\n";
	cout << "---------------------------------" << endl;

}

void HotelManagementSystem::bookRoom() {
	int count;
	cout << "Enter number of rooms to book: ";
	cin >> count;

	if (count < 1 || count > MAX_ROOMS) {
		cout << "Invalid count.\n";
		return;
	}

	string name;
	cout << "Enter your name: ";
	cin.ignore();
	getline(cin, name);

	int custIndex = -1;
	for (int i = 0; i < MAX_CUSTOMERS; i++) {
		if (customers[i].getName().empty()) {
			custIndex = i;
			break;
		}
	}

	if (custIndex == -1) {
		cout << "Customer list full.\n";
		return;
	}

	customers[custIndex].setName(name);
	customers[custIndex].setRoomCount(count);
	double bill = 0.0;

	for (int j = 0; j < count; j++) {
		int r;
		cout << "Enter room number " << j + 1 << ": ";
		cin >> r;
		if (r < 1 || r > MAX_ROOMS || rooms[r - 1].getOccupied()) {
			cout << "Invalid or occupied room.\n";
			return;
		}
		rooms[r - 1].occupy();
		customers[custIndex].setRoom(j, r);
		bill += rooms[r - 1].getRoomPrice();
	}

	if (count > 2) bill *= 0.8;
	customers[custIndex].setTotalBill(bill);
	customers[custIndex].setBookingTime(time(0));
	cout << "Room(s) booked. \nTotal: $" << bill << "\n";
}

void HotelManagementSystem::checkIn() {
	string name;
	cout << "Enter your name: ";
	cin.ignore();
	getline(cin, name);
	int i = findCustomerIndex(name);
	if (i == -1) { cout << "Not found.\n"; return; }
	if (customers[i].getCheckedIn()) cout << "Already checked-in.\n";
	else { customers[i].setCheckedIn(true); cout << "Checked-in.\n"; }
}

void HotelManagementSystem::checkOut() {
	string name;
	cout << "Enter your name: ";
	cin.ignore();
	getline(cin, name);
	int i = findCustomerIndex(name);
	if (i == -1 || !customers[i].getCheckedIn()) { cout << "Invalid.\n"; return; }

	for (int j = 0; j < customers[i].getRoomCount(); j++)
		rooms[customers[i].getRoom(j) - 1].vacate();

	cout << "Checked out. \nTotal Bill: $" << customers[i].getTotalBill() << "\n";
	customers[i].setCheckedIn(false);
}

void HotelManagementSystem::viewBill() {
	string name;
	cout << "Enter your name: ";
	cin.ignore();
	getline(cin, name);
	int i = findCustomerIndex(name);
	if (i != -1 && customers[i].getCheckedIn())
		cout << "Bill: $" << customers[i].getTotalBill() << "\n";
	else
		cout << "Not checked-in or invalid.\n";
}

void HotelManagementSystem::addFoodItem() {
	string name;
	double price;
	cout << "Food name: ";
	cin.ignore();
	getline(cin, name);
	cout << "Price: ";
	cin >> price;

	for (int i = 0; i < MAX_FOOD_ITEMS; i++) {
		if (foodItems[i].getName().empty()) {
			foodItems[i].setFood(name, price);
			cout << "New Food Item Added.\n";
			return;
		}
	}
	cout << "Menu full.\n";
}

void HotelManagementSystem::orderFood() {
	string name;
	cout << "Enter your name: ";
	cin.ignore();
	getline(cin, name);
	int i = findCustomerIndex(name);
	if (i == -1) { cout << "Not found.\n"; return; }

	displayFoodMenu();
	char cont;
	do {
		int ch;
		cout << "Enter food number: ";
		cin >> ch;

		if (ch >= 1 && ch <= MAX_FOOD_ITEMS && !foodItems[ch - 1].getName().empty()) {
			if (!customers[i].hasOrdered(ch - 1)) {
				customers[i].orderFood(ch - 1);
				customers[i].addToBill(foodItems[ch - 1].getPrice());
				cout << foodItems[ch - 1].getName() << " ordered.\n";
			}
			else {
				cout << "Already ordered.\n";
			}
		}
		else {
			cout << "Invalid choice.\n";
		}

		cout << "Order more? (y/n): ";
		cin >> cont;
	} while (cont == 'y' || cont == 'Y');
}

void HotelManagementSystem::cancelRoomBooking() {
	string name;
	cout << "Enter your name: ";
	cin.ignore();
	getline(cin, name);
	int i = findCustomerIndex(name);
	if (i == -1 || customers[i].getCheckedIn()) { cout << "Cannot cancel.\n"; return; }

	double percent = calculateCancellationFee(customers[i].getBookingTime());
	double fee = customers[i].getTotalBill() * percent;
	customers[i].addToBill(-fee);


	for (int j = 0; j < customers[i].getRoomCount(); j++)
		rooms[customers[i].getRoom(j) - 1].vacate();

	cout << "Booking canceled. \nCancellation Fee: $" << fee << "\nTotal after fee: $" << customers[i].getTotalBill() << "\n";
}

double HotelManagementSystem::calculateCancellationFee(time_t bookTime) {
	double diff = difftime(time(0), bookTime);
	if (diff < 86400) return 0.20;
	if (diff < 172800) return 0.50;
	return 1.00;
}

void HotelManagementSystem::cancelFoodOrder() {
	string name;
	cout << "Enter your name: ";
	cin.ignore();
	getline(cin, name);
	int i = findCustomerIndex(name);
	if (i == -1 || !customers[i].getCheckedIn()) { cout << "Invalid.\n"; return; }

	int ch;
	cout << "Enter food number to cancel: ";
	cin >> ch;

	if (ch >= 1 && ch <= MAX_FOOD_ITEMS && customers[i].hasOrdered(ch - 1)) {
		customers[i].cancelFood(ch - 1);
		customers[i].addToBill(-foodItems[ch - 1].getPrice());
		cout << foodItems[ch - 1].getName() << " Canceled.\n";
	}
	else {
		cout << "Invalid.\n";
	}
}

void HotelManagementSystem::viewCustomerDetails() {
	string name;
	cout << "Enter your name: ";
	cin.ignore();
	getline(cin, name);
	int i = findCustomerIndex(name);
	if (i != -1) {
		Person* p = &customers[i];
		p->showDetails();
	}
	else {
		cout << "Customer not found.\n";
	}
}

void HotelManagementSystem::run() {
	int choice;
	do {
		displayMenu();
		cout << "Enter choice: ";
		cin >> choice;

		switch (choice) {
		case 1: displayRooms(); break;
		case 2: bookRoom(); break;
		case 3: checkIn(); break;
		case 4: checkOut(); break;
		case 5: viewBill(); break;
		case 6: addFoodItem(); break;
		case 7: orderFood(); break;
		case 8: displayFoodMenu(); break;
		case 9: cancelRoomBooking(); break;
		case 10: cancelFoodOrder(); break;
		case 11: viewCustomerDetails(); break;
		case 12: cout << "Thank you! Have a great day!\n"; break;
		default: cout << "Invalid choice.\n";
		}
	} while (choice != 12);
}

// Main Driver
int main() {
	HotelManagementSystem hotel;
	hotel.run();
	return 0;
}