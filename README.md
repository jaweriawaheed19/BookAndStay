# 🏨 Book and Stay
*Hotel Management System (C++)*

Managing hotel operations manually can be time-consuming, error-prone, and inefficient. That’s where a **Hotel Management System** steps in. This project, **Book and Stay**, is designed to streamline essential hotel tasks such as room booking, check-in/check-out, food orders, billing, and customer record management — all in a simple console interface.

This system is implemented using **C++** and showcases a practical application of all **four pillars of Object-Oriented Programming (OOP)**

## Functionalities

- 🛏️ **Room Booking**
  - Book single or double rooms
  - Auto-discount for 2+ room bookings
  - Prevent booking if room is already reserved

- ✅ **Check-In / Check-Out**
  - Assign room to a customer
  - Auto-calculate days of stay
  - Generate total bill on check-out (room + food + taxes)

- 🍽️ **Food Ordering**
  - View menu
  - Order multiple food items
  - Add food cost to the room bill

- 🧾 **Billing**
  - Combine room and food charges
  - Display customer bill on demand
  - Apply taxes and discounts

- ❌ **Booking & Order Cancellation**
  - Cancel room bookings (with cancellation fee)
  - Cancel food orders before bill is generated

- 🧍 **Customer Record Management**
  - View all customer details
  - Search bookings by room number or name

## 🧠 OOP Concepts Used

| OOP Concept     | Implementation Example |
|----------------|------------------------|
| **Encapsulation** | Data hidden in `Room`, `Food`, and `Customer` classes |
| **Abstraction**   | Main logic in `HotelManagementSystem` class |
| **Inheritance**   | `Customer` inherits from base class `Person` |
| **Polymorphism**  | `showDetails()` method overridden in child classes |

## 🛠️ Technologies

- **Language:** C++  
- **Libraries:** `iostream`, `iomanip`, `string`, `ctime`

## Learning Outcomes

- Understand how to apply all four pillars of OOP in a real-world application
- Learn to design modular C++ classes with proper abstraction and encapsulation
- Practice class inheritance and polymorphism to simplify code reuse and extension
- Build a console-based UI and use menus for interaction
- Strengthen logic-building and problem-solving skills using C++

## Author

*Jaweria Waheed*

- Student – BS Computer Science, Bahria University  
- [LinkedIn Profile](https://www.linkedin.com/in/jaweriasatti)  
- [Email](mailto:jaweriasatti19@gmail.com)

##  License

This project is released under the MIT License.
