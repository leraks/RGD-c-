#include <iostream>
#include <string>
using namespace std;
class OrderProgramm {
protected:
    Productfabrika store;
    int countItems = 0;
    Product* items[100] = { 0 };
    string Clientname, Timework;

public:

    int getCount() {
        return countItems;
    }
    Product** getItems() {
        return items;
    }
    string getName() {
        return Clientname;
    }
    string getTime() {
        return Timework;
    }

    void order_create(const string m, const string tm, const int count, string(*ms)[2], const int id_in) {
        Clientname = m;
        Timework = tm;
        for (int i = 0; i < count; i++) {
            items[i] = store.create(ms[i]);
            countItems++;
        }
    }
    void printOrder() {
        cout << "\t" << "Name: " << Clientname << endl;
        cout << "\t" << "Deadlines: " << Timework << endl;
        for (int i = 0; i < countItems; i++) {
            cout << "\t" << "Title: " << items[i]->getTitle() << endl
                << "\t" << "Cost: " << items[i]->getCost() << endl;
        }
    }
};
class Orderfabrika {
public:
    OrderProgramm* create(const string m, const string tm, const int count, string(*ms)[2], const int id) {
        OrderProgramm* res = new OrderProgramm;
        res->order_create(m, tm, count, ms, id);
        return res;
    }
};