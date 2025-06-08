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

    // New Methods Added for Different Saving Mechanisms but violates OCP
    // because if we want to add a new saving mechanism, we have to modify this class.
    void savetoSQL() {
        cout<< "Invoice saved to SQL database." << endl;
    }

    void saveToMongoDB() {
        cout<< "Invoice saved to MongoDB database." << endl;
    }

    void saveToFile() {
        cout<< "Invoice saved to file." << endl;
    }
};

int main() {
    ShoppingCart cart;
    cart.addProduct(Product("Laptop", 1000.0));
    cart.addProduct(Product("Mouse", 50.0));

    ShopingCartPrinter printer(cart);
    printer.printInvoice();

    InvoiceSaver saver(cart);
    saver.savetoSQL();
    saver.saveToMongoDB();
    saver.saveToFile();

    return 0;
}