#include <iostream>
#include <cmath>

#define PI 3.14159265

using namespace std;

int main() {
    double x1, x2, x3, y1, y2, y3, epsilon = 0.0000001;
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;

    double v1x = x2 - x1, v1y = y2 - y1;
    double v2x = x3 - x2, v2y = y3 - y2;
    double v3x = x1 - x3, v3y = y1 - y3;

    double v1cos = (-1.0) * (v1x * v2x + v1y * v2y) / (sqrt((v1x * v1x) + (v1y * v1y)) * sqrt((v2x * v2x) + (v2y * v2y)));
    double v2cos = (-1.0) * (v2x * v3x + v2y * v3y) / (sqrt((v2x * v2x) + (v2y * v2y)) * sqrt((v3x * v3x) + (v3y * v3y)));
    double v3cos = (-1.0) * (v3x * v1x + v3y * v1y) / (sqrt((v3x * v3x) + (v3y * v3y)) * sqrt((v1x * v1x) + (v1y * v1y)));

    if (abs(v1cos - 1) < epsilon | abs(v2cos - 1) < epsilon | abs(v3cos - 1) < epsilon) {
        cout << "degenerate";
        return 0;
    }
    else if (v1cos == 0 | v2cos == 0 | v3cos == 0) {
        cout << "right";
        return 0;
    }
    else if (v1cos < 0 | v2cos < 0 | v3cos < 0) {
        cout << "obtuse";
        return 0;
    }
    else if (v1cos > 0 | v2cos > 0 | v3cos > 0) {
        cout << "acute";
        return 0;
    } 
    else cout << "degenerate";
 
    return 0;
}