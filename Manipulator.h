class Manipulator {
private:
    Orderfabrika store;
    OrderProgramm* orders[100] = {};
    int countOrders = 0;

public:
    int getCount() { return countOrders; }
    OrderProgramm** getOrders() { return orders; }

    void printOrders() {
        for (int i = 0; i < countOrders; i++) {
            cout << '[' << i + 1 << "] ";
            orders[i]->printOrder();
        }
    }
    void newOrder(const string m, const string tm, const int count, string(*ms)[2], const int id = 0) {
        orders[countOrders] = store.create(m, tm, count, ms, id);
        countOrders++;
    }
    void delOrder(const int ind) {
        if ((ind >= 0) && (ind < countOrders)) {
            for (int i = ind; i < countOrders - 1; i++) { orders[i] = orders[i + 1]; }
            countOrders--;
        }
    }
};