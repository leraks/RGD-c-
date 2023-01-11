#include <iostream>
#include <fstream>
#include <string>
#include "Product.h"
#include "OrderProgramm.h"
#include "Manipulator.h"
using namespace std;
// Тема 5. Заказы фирмы разработки ПО

/* Задание: cоздать программу по управлению объектами данных по указанной теме с  использованием ООП и реализовывать изученные паттерны.
Необходимо создать минимум 3 объекта сущности разных видов и указать взаимодействие между объектами.
Реализовать интерфейсы ввода, вывода и редактитрования сущностей. Реализовать ручной ввод сущностей, загрузку из файла и сохранения в файл, удаление выбранных сущностей.
Данные между запусками программы хранить в структурированном текстовом файле. */

// Консольное меню
class Menu {
private:
    int choice1 = 0;
    int exit = 0;
    Manipulator* manipulator = new Manipulator;


    void navigationMenu(void) {
        system("cls");
        cout << "Меню навигации\n";
        cout << "~~~~~~~~~~~~~~~~~~~~~~\n\n";

        cout << "1 - Заказы\n";
        cout << "2 - Новая разработка\n";
        cout << "3 - Удалить из списка\n";
        cout << "4 - Сохранить данных\n";
        cout << "5 - Загружка данных из файла\n";
        cout << "0 - Выйти\n\n";

        cout << "~~~~~~~~~~~~~~~~~~~~~~\n\n";
        cout << "Выбор ";
        cin >> choice1;
    }

    // Вывод всех разработок в консоль
    void print() {
        system("cls");
        manipulator->printOrders();
        cout << "Введите 0 для продолжения:";
        cin >> exit;
    }

    // Создание нового заказа
    void newOrderMenu(void) {
        string n, name, deadlines;
        string ms[100][2];
        system("cls");
        cout << "Имя клиента - ";
        getline(cin >> ws, name);
        cout << "Предполагаемые сроки выполнения работы - ";
        getline(cin >> ws, deadlines);


        cout << "Вид проекта - ";
        getline(cin >> ws, ms[0][0]);
        cout << "Цена - ";
        getline(cin >> ws, ms[0][1]);

        manipulator->newOrder(name, deadlines, stoi("1"), ms);

        cout << "Выполнено\n";
        cout << "Введите 0 для продолжения: ";
        cin >> exit;
    }

    // Удаление заказа
    void removeOrderMenu(void) {
        string n;
        system("cls");
        cout << "Меню удаления заказа\n\n";
        cout << "0 - Назад\n";
        manipulator->printOrders();
        cout << "Пожалуйста, выберете заказ: ";
        getline(cin >> ws, n);
        manipulator->delOrder(stoi(n) - 1);
        system("cls");
        cout << "Выполнено успешно" << endl;
        cout << "Введите 0 для продолжения";
        cin >> exit;
    }

    // Сохранение данных в файл "orders.txt"
    void saveToFile() {
        ofstream fout;
        string path = "orders.txt";
        fout.open(path);
        if (!fout.is_open()) {
            cout << "Ошибка открытия файла" << endl;
        }
        else {
            OrderProgramm** ord = manipulator->getOrders();
            fout << manipulator->getCount() << '\n'; // количество клиентов
            for (int i = 0; i < manipulator->getCount(); i++) {
                fout << ord[i]->getName() << '\n'; // имя клиента
                fout << ord[i]->getTime() << '\n'; // номер клиента
                fout << ord[i]->getCount() << '\n'; // количество разработок
                Product** prod = ord[i]->getItems();
                for (int j = 0; j < ord[i]->getCount(); j++) {
                    fout << prod[j]->getTitle() << endl; // описание разработки
                    fout << prod[j]->getCost() << endl; // стоимость разработки
                }
            }
            system("cls");
            cout << "Выполнено успешно" << endl;
            cout << "Введите 0 для продолжения";
            cin >> exit;
        }
        fout.close();
    }

    // Импорт из файла "orders.txt"
    void takeFromFile() {
        ifstream fin;
        string str, nm, tm, cnt, path = "orders.txt";
        string ms[100][2];
        fin.open(path);
        if (!fin.is_open()) {
            cout << "Ошибка открытия файла" << endl;
        }
        else {
            getline(fin, str, '\n');
            int ordersCount = stoi(str);
            for (int i = 0; i < ordersCount; i++) {
                getline(fin, nm, '\n');
                getline(fin, tm, '\n');
                getline(fin, cnt, '\n');
                int itemsCount = stoi(cnt);
                for (int j = 0; j < itemsCount; j++) {
                    getline(fin, ms[j][0], '\n');
                    getline(fin, ms[j][1], '\n');
                }
                manipulator->newOrder(nm, tm, stoi(cnt), ms);
            }
            system("cls");
            cout << "Complete!" << endl;
            cout << "Enter 0 to continue:";
            cin >> exit;
        }
        fin.close();
    }

public:
    void menu() {
        do {
            navigationMenu();
            switch (choice1) {
            case 1:
                print();
                break;
            case 2:
                newOrderMenu();
                break;
            case 3:
                removeOrderMenu();
                break;
            case 4:
                saveToFile();
                break;
            case 5:
                takeFromFile();
                break;
            case 0:
                break;
            }
        } while (choice1 != 0);
    }
};

int main()
{
    setlocale(LC_ALL, "Ru");
    Menu app;
    app.menu();

    return 0;
}