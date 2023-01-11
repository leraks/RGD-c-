#include <iostream>
#include <string>
using namespace std;
// Разработка
class Product {
protected:
    string productname;
    int cost;
public:
    Product() { productname = "\t"; cost = 0; }
    void create(const string m, const int n) { productname = n; cost = n; }

    string getTitle() {
        return productname;
    }
    int getCost() {
        return cost;
    }
};
class Productfabrika {
public:
    Product* create(string* ms) {
        Product* res = new Product;
        res->create(ms[0], stoi(ms[1]));
        return res;
    }
};