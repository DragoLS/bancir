#include <iostream>
#include <string>
#include <Windows.h>
#pragma execution_character_set("utf-8")

using namespace std;

// Объявление структуры
struct Bank
{
    int accountNumber;
    double balance;
    double interestRate;
    void Info() {
        cout << "Номер счёта: " << accountNumber << endl;
    }
    void Infoi() {

        cout << "Сумма процентов: " << balance * interestRate * 1/12 << endl;
    }
    void Infor() {
        cout << "Баланс данного аккаунта: " << balance << endl;
    }
    void dep(int i) {
        balance = balance + i;
    }
    void inter(int i) {
        interestRate = i;
    }
    // Конструктор для инициализации полей
    Bank(int accountNumber, double balance, double interestRate) {
        this->accountNumber = accountNumber;
        this->balance = balance;
        this->interestRate = interestRate;
    }
};

class BankAccount {
private:
    int count;
    Bank** people; // Массив указателей на Bank

public:
    BankAccount(int size) {
        count = 0;
        people = new Bank * [size];
    }

    void addBank(Bank* p) {
        people[count++] = p;
    }
    void getAccountNumber(int n) {
        people[n]->Info();  
    }
    void getBalance(int n) {
        people[n]->Infor();
    }
    void getInterest(int n) {
        people[n]->Infoi();
    }
    void deposit(int n, int dep) {
        people[n]->dep(dep);
    }
    void withdraw(int n, int dep) {
        dep = dep * -1;
        people[n]->dep(dep);
    }
    void setInterestRate(int n, double dep) {
        people[n]->inter(dep);
    }
    //Деструктор класса BankAccount, освобождающий динамически выделенную память.
    ~BankAccount() {
        for (int i = 0; i < count; i++) {
            cout << "аккаунт под номером: " << people[i]->accountNumber << " удален" << endl;
            delete people[i];
        }
        delete[] people;
    }
};



int main() {
    SetConsoleCP(65001); // устанавливаем кодировку входящего потока данных на UTF-8
    SetConsoleOutputCP(65001); // устанавливаем кодировку исходящего потока данных на UTF-8
    int num_of_people;
    cout << "Введите количество аккаунтов: ";
    cin >> num_of_people;

    //Создание объекта коллекции PersonCollection с указанным количеством мест.

    BankAccount collection(num_of_people);
    
    //Цикл для ввода информации о каждом аккаунте и добавления его в коллекцию.
    for (int i = 0; i < num_of_people; i++) {
        int num;
        double mon;
        cout << "Введите номер аккаунта ";
        try
        {
        cin >> num;
        }
        catch (const exception&)
        {
            cout << "Введите цифрами";
        }
        cout << "Деньги на данном аккаунте";
        try{
        cin >> mon;
        }
        catch (const exception&)
        {
            cout << "Введите цифрами";
        }
        // Создание объекта Bank в динамической памяти и передача указателя на него в метод addBank
        Bank* new_Bank = new Bank(num,mon,0);
        collection.addBank(new_Bank);
    }
    while (true)
    {
        int v = 0;
        cout << "1.Внести средства на счёт";
        cout << "2.Вывести средства с счёта";
        cout << "3.Просмотреть баланс";
        cout << "4.Обновть процентную ставку";
        cout << "5.Получить номер банковского счёта";
        cout << "6.Проценты заработнанные на счёте";
        cout << "7.Трансфер";
        try
        {
             cin >> v;
        }
        catch (const exception&)
        {
            cout << "Введите цифрами";
        }
        if (v == 1) {
            int n;
            int dep;
            cout << "";
            try
            {
                 cin >> n;
            }
            catch (const exception&)
            {
                cout << "Введите цифрами";
            }
            cout << "";
            try
            {
                cin >> dep;
            }
            catch (const exception&)
            {
                cout << "Введите цифрами";
            }
            collection.deposit(n,dep);
        }

        if (v == 2) {
            int n;
            int dep;
            cout << "";
            try
            {
                cin >> n;
            }
            catch (const exception&)
            {
                cout << "Введите цифрами";
            }
            cout << "";
            try
            {
                cin >> dep;
            }
            catch (const exception&)
            {
                cout << "Введите цифрами";
            }
            collection.withdraw(n, dep);
        }

        if (v == 3) {
            int n;
            cout << "Баланс какого аккаунта нужен. Введите число";
            try
            {
                cin >> n;
            }
            catch (const exception&)
            {
                cout << "Введите цифрами";
            }
            collection.getBalance(n);
        }

        if (v == 4) {
            int n;
            double dep;
            cout << "";
            try
            {
                cin >> n;
            }
            catch (const exception&)
            {
                cout << "Введите цифрами";
            }
            cout << "";
            try
            {
                cin >> dep;
            }
            catch (const exception&)
            {
                cout << "Введите цифрами";
            }
            try
            {
            collection.setInterestRate(n, dep);
            }
            catch (const std::exception&)
            {

            }
        }

        if (v == 5) {
            int n;
            cout << "Номер банковского счёта какого аккаунта нужен. Введите число";
            try
            {
            cin >> n;
            }
            catch (const exception&)
            {
                cout << "Введите цифрами";
            }
            collection.getAccountNumber(n);
        }

        if (v == 6) {
            int n;
            cout << "Номер банковского счёта какого аккаунта нужен. Введите число";
            try
            {
                cin >> n;
            }
            catch (const exception&)
            {
                cout << "Введите цифрами";
            }
            collection.getAccountNumber(n);
        }

    }

    return 0;
}