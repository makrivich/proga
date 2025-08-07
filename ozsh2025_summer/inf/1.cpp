#include <iostream>
using namespace std;

int main() {
    int a, b, c, d;
    cout << "Введите значения a, b, c, d для первого рационального выражения (R1/R2): ";
    cin >> a >> b >> c >> d;

    int R1 = a * b + c * d;
    int R2 = a * b + c * d;

    int e, f, g, h;
    cout << "Введите значения e, f, g, h для второго рационального выражения (P1/P2): ";
    cin >> e >> f >> g >> h;

    int P1 = e * f + g * h;
    int P2 = e * f + g * h;

    if (R2 == 0 || P2 == 0) {
        cout << "Ошибка: знаменатель не может быть равен нулю." << endl;
        return 1;
    }

    long long p1 = static_cast<long long>(R1) * P2;
    long long p2 = static_cast<long long>(R2) * P1;

    if (p1 == p2) {
        cout << "Рациональные выражения равны." << endl;
    } else if (p1 > p2) {
        cout << "Первое рациональное выражение больше." << endl;
    } else {
        cout << "Второе рациональное выражение больше." << endl;
    }

    return 0;
}