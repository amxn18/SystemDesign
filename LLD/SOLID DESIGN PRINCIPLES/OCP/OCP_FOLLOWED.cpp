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

class InvoiceSaver {
    private:
    ShoppingCart* cart;  // Reference to ShoppingCart
    public:
    virtual void save(ShoppingCart* cart) = 0; // Pure virtual function for saving invoice
};
class InvoiceSaverSQL : public InvoiceSaver {
    public:
    void save(ShoppingCart* cart) override {
        cout << "Invoice saved to SQL database." << endl;
    }
};
class InvoiceSaverNoSQL : public InvoiceSaver {
    public:
    void save(ShoppingCart* cart) override {
        cout << "Invoice saved to NoSQL database." << endl;
    }
};
class InvoiceSaverXML : public InvoiceSaver {
    public:
    void save(ShoppingCart* cart) override {
        cout << "Invoice saved to XML file." << endl;
    }
};

int main() {
    ShoppingCart cart;
    cart.addProduct(Product("Laptop", 1000.0));
    cart.addProduct(Product("Mouse", 50.0));

    ShopingCartPrinter printer(cart);
    printer.printInvoice();

    InvoiceSaver* sqlSaver = new InvoiceSaverSQL();
    sqlSaver->save(&cart);

    InvoiceSaver* noSqlSaver = new InvoiceSaverNoSQL();
    noSqlSaver->save(&cart);

    InvoiceSaver* xmlSaver = new InvoiceSaverXML();
    xmlSaver->save(&cart);

    delete sqlSaver;
    delete noSqlSaver;
    delete xmlSaver;

    return 0;
}