#include<bits/stdc++.h>
using namespace std;

class Product {
public:
    string name;
    double price;

    Product(string name, double price) {
        this->name = name;
        this->price = price;
    }
};

// Only Handles Product Details Present in Shopping Cart
class ShoppingCart {
private:
    vector<Product> products;
public:
    void addProduct(Product product) {
        products.push_back(product);
    }

    const vector<Product>& getProducts() const {
        return products;
    }
    double calculateTotal() const {
        double total = 0.0;
        for (const auto& product : products) {
            total += product.price;
        }
        return total;
    }
};

// Responsible for Printing Invoice
class ShopingCartPrinter {
    private:
    const ShoppingCart& cart;
    public:
    ShopingCartPrinter(const ShoppingCart& cart) : cart(cart) {}
    void printInvoice() const {
        for (const auto& product : cart.getProducts()) {
            cout << "Product Name: " << product.name << ", Price: " << product.price << endl;
            cout<< "Total Price: " << cart.calculateTotal() << endl;
        }
    }
};

// Responsible for Saving Invoice to Database
class InvoiceSaver {
private:
    const ShoppingCart& cart;
public:
    InvoiceSaver(const ShoppingCart& cart) : cart(cart) {}

    void saveToDB() const {
        // Simulate saving to database
        cout << "Invoice saved to database." << endl;
    }
};

int main() {
    ShoppingCart cart;
    cart.addProduct(Product("Laptop", 1000.0));
    cart.addProduct(Product("Mouse", 50.0));

    // Print products
    ShopingCartPrinter printer(cart);
    printer.printInvoice();

    // Save invoice to database
    InvoiceSaver saver(cart);
    saver.saveToDB();

    return 0;
}