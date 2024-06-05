#include <iostream> 
#include <locale> 
#include <climits> 
#include <cmath>

using namespace std;

// це функція для введ і вивед масиву 
void InputAndOutputArray(int sizeMax, double A[]) {
    int size;
    // запит на введення розміру
    do {
        cout << "Введіть розмір масиву (0 < розмір < " << sizeMax << "): ";
        cin >> size;
    } while (size <= 0 || size >= sizeMax);

    // введення значень 
    cout << "Введіть елементи масиву:\n";
    for (int i = 0; i < size; i++) {
        cout << "A[" << i << "]: ";
        cin >> A[i];
    }

    // виведення масиву
    cout << "Масив A:\n";
    for (int i = 0; i < size; i++) {
        cout << A[i] << " ";
    }
    cout << endl;
}

// підрахунок кількості 0 елементів
int CountZeroElements(int size, double A[]) {
    int count = 0;
    for (int i = 0; i < size; i++) {
        if (A[i] == 0) {
            count++;
        }
    }
    return count;
}

// функція для знаходження макс від'єм елем після знач Т

int LastMaxNegativeIndex(int size, double A[], double T) {
    int lastMaxNegativeIndex = -1;
    double maxNegative = INT_MIN; // макс від'ємне значення
    bool foundT = false;

    // скан масиву від кінця до початку
    for (int i = size - 1; i >= 0; i--) {
        if (A[i] == T) {
            foundT = true;
            break; // зупиняє пошук коли знайдено Т елемент
        }
        // пошук максимального від'ємного елемента
        if (A[i] < 0 && A[i] > maxNegative) {
            maxNegative = A[i];
            lastMaxNegativeIndex = i;
        }
    }

    if (!foundT) {
        cout << "Елемент, що дорівнює T, не знайдено." << endl;
        return -1;
    }

    if (lastMaxNegativeIndex == -1) {
        cout << "В масиві немає від'ємних елементів." << endl;
    }

    return lastMaxNegativeIndex;
}

// головна функція
int main() {
    setlocale(LC_CTYPE, "Ukr");
    const int MAX_SIZE = 100;
    double A[MAX_SIZE];
    double T;
    int choice;
    int lastIndex; // змінна для збереження індексу останнього максимального від'ємного елемента

    do {
        cout << "Меню:\n";
        cout << "1. Ввести масив та вивести його\n";
        cout << "2. Порахувати кількість нульових елементів в масиві\n";
        cout << "3. Знайти останній максимальний від'ємний елемент\n";
        cout << "4. Вийти з програми\n";
        cout << "Виберіть опцію: ";
        cin >> choice;


        switch (choice) {
        case 1:
            InputAndOutputArray(MAX_SIZE, A);
            break;
        case 2:
            cout << "Кількість нульових елементів в масиві: " << CountZeroElements(MAX_SIZE, A) << endl;
            break;
        case 3:
            cout << "Введіть значення T: ";
            cin >> T;
            lastIndex = LastMaxNegativeIndex(MAX_SIZE, A, T);
            if (lastIndex != -1) {
                cout << "Номер останнього максимального від'ємного елемента: " << lastIndex << endl;
            }
            break;
        case 4:
            // вихід
            break;
        default:
            cout << "Некоректний вибір. Спробуйте ще раз.\n";
            break;
        }
    } while (choice != 4);

    return 0;
}
