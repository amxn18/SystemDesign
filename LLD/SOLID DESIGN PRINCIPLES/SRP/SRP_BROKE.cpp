// Single Responsibility Principle (SRP) states that a class should have only one reason to change, meaning it should only have one job or responsibility.
// This principle helps in maintaining a clean and understandable codebase, making it easier to manage and extend.

#include<bits/stdc++.h>
using namespace std;

class Product{
    public:
    string name;
    double price;
    Product(string name, double price) {
        this->name = name;
        this->price = price;
    }
};

// Violation of SRP: This class handles both product details and printing functionality.
class ShopingCart {
    private:
    vector<Product> products;
    
    public:
    void addProduct(Product product) {
        products.push_back(product);
    }

    // 1) This method violates SRP as it handles printing logic.
    const vector<Product>& getProducts() const {
        return products;
    }

    void printProducts() const {
        for (const auto& product : products) {
            cout << "Product Name: " << product.name << ", Price: " << product.price << endl;
        }
    }

    // 2) This method violates SRP as it handles calculating total price.
    double calculateTotal() const {
        double total = 0.0;
        for (const auto& product : products) {
            total += product.price;
        }
        return total;
    }

    // 3) This method violates SRP as it Print Invoice.
    void invoicePrinter() const {
        cout << "Invoice:" << endl;
        printProducts();
        cout << "Total Price: " << calculateTotal() << endl;
    }
    // 4) This method violates SRP as it handles saving invoice to database.
    void saveToDB() const {
        // Simulate saving to database
        cout << "Invoice saved to database." << endl;
    }
};

int main() {
    ShopingCart cart;
    cart.addProduct(Product("Laptop", 1000.0));
    cart.addProduct(Product("Mouse", 50.0));
    
    // Print products
    cart.printProducts();
    
    // Calculate total price
    cout << "Total Price: " << cart.calculateTotal() << endl;
    
    // Print invoice
    cart.invoicePrinter();
    
    // Save invoice to database
    cart.saveToDB();
    
    return 0;
}