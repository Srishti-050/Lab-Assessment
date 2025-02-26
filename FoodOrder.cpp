#include <iostream>
using namespace std;

class FoodOrder {
private:
    string dishName;
    int quantity;
    double pricePerUnit;
    double totalPrice;

public:
    // Constructor
    FoodOrder(string dish, int qty, double price) 
        : dishName(dish), quantity(qty), pricePerUnit(price) {
        totalPrice = quantity * pricePerUnit;
    }

    // Overloading the + operator to merge two food orders
    FoodOrder operator+(const FoodOrder& other) {
        if (dishName == other.dishName) { 
            return FoodOrder(dishName, quantity + other.quantity, pricePerUnit);
        } else { 
            cout << "Error: Cannot merge different dishes!\n";
            return *this;
        }
    }

    // Display order details
    void displayOrder() {
        cout << "Dish: " << dishName << "\nQuantity: " << quantity 
             << "\nPrice per Unit: $" << pricePerUnit 
             << "\nTotal Price: $" << totalPrice << "\n\n";
    }
};

int main() {
    // Creating two food orders for the same dish
    FoodOrder order1("Burger", 2, 5.99);
    FoodOrder order2("Burger", 3, 5.99);
    FoodOrder order3("Pizza", 1, 8.99);

    cout << "Initial Orders:\n";
    order1.displayOrder();
    order2.displayOrder();

    // Merging orders
    FoodOrder mergedOrder = order1 + order2;
    cout << "Merged Order:\n";
    mergedOrder.displayOrder();

    // Attempt to merge different dishes
    FoodOrder invalidMerge = order1 + order3;

    return 0;
}
