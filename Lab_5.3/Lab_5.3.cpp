#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

double j (const double x);
int factorial(const int n);


int main() {
    double kp, kk;
    int n;

    cout << "kp = "; cin >> kp;
    cout << "kk = "; cin >> kk;
    cout << "n = "; cin >> n;

    double dk = (kk - kp) / n;
    double k = kp;

    cout << fixed;
    cout << "-----------------------------------------" << endl;
    cout << "|    p    |         z(p)                |" << endl;
    cout << "-----------------------------------------" << endl;

    while (k <= kk) {
        double result = j(1+k+j(k))+(k*k)*(1+pow(k,2));
        cout << "| " << setw(7) << setprecision(2) << k << " | "
            << setw(24) << setprecision(10) << result << "    |" << endl;

        k += dk;
    }

    cout << "-----------------------------------------" << endl;
    system("pause");
    return 0;
}
int factorial(int n) {
    if (n <= 1) {
        return 1;
    }
    else {
        return n * factorial(n - 1);
    }
}
double j(const double x) {
    if (abs(x) >= 1) {
        return (cos(x) + exp(-abs(x))) / (1 + cos(x) * cos(x));
    }
    else {
        double S = 0;
        double term = 1;
        int i = 0;

        do {
            if (i > 0) {
                double R = (pow(x, 2 * i + 1)) / factorial(2 * i + 1);
                term *= R;
            }
            S += term;
            i++;
        } while (i <= 5);

        return S;
    }
}
