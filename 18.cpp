#include <iostream>
#include <vector>

using namespace std;

int main() {

    setlocale(LC_ALL, "RU");

    // Константа
    const double A = 3.5;

    // Вектор для хранения значений X
    vector<double> x;

    // Заполнение вектора X значениями от 1 до 10 с шагом 1
    for (double i = 1; i <= 10; i++) {
        x.push_back(i);
    }

    // Вектор для хранения значений Y
    vector<double> y;

    // Вычисление значений Y для каждого элемента вектора X
    for (double xi : x) {
        double yi = 0.5 * xi * pow(1 + A * xi, 2);
        y.push_back(yi);
    }

    // Вывод значений X и Y на экран
    cout << "Значения X:" << endl;
    for (double xi : x) {
        cout << xi << " ";
    }
    cout << endl;

    cout << "Значения Y:" << endl;
    for (double yi : y) {
        cout << yi << " ";
    }
    cout << endl;

    return 0;
}