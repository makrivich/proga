#include <iostream>
#include <cmath>
#include <iomanip>
#include <algorithm>
using namespace std;

int main() {
    double x1, y1, x2, y2, x3, y3, e;
    cout << "Введите координаты вершин треугольника (x1 y1 x2 y2 x3 y3): ";
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
    cout << "Введите погрешность e: ";
    cin >> e;
    double minArea = 1e18;
    double maxArea = 0.0;

    for (int mask = 0; mask < 64; ++mask) {
        double nx1 = x1 + ((mask & 1) ? e : -e);
        double ny1 = y1 + ((mask & 2) ? e : -e);
        double nx2 = x2 + ((mask & 4) ? e : -e);
        double ny2 = y2 + ((mask & 8) ? e : -e);
        double nx3 = x3 + ((mask & 16) ? e : -e);
        double ny3 = y3 + ((mask & 32) ? e : -e);
        double det = nx1 * (ny2 - ny3) + nx2 * (ny3 - ny1) + nx3 * (ny1 - ny2);
        double area = 0.5 * fabs(det);

        if (area < minArea) minArea = area;
        if (area > maxArea) maxArea = area;
    }

    cout << fixed << setprecision(6);
    cout << "Минимальная возможная площадь: " << minArea << endl;
    cout << "Максимальная возможная площадь: " << maxArea << endl;

    return 0;
}