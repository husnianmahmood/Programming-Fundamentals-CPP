#include <iostream>
using namespace std;

double calculatePower(double base, double exponent) {
    double ans = 1.0;
    for (int i = 0; i < exponent; i++) {
        ans *= base;
    }
    return ans;
}

int main() {
    double base, exponent;
    cout << "Enter Base: ";
    cin >> base;
    cout << "Enter Power: ";
    cin >> exponent;

    cout << base << " raised to the power of " << exponent << " is: " 
         << calculatePower(base, exponent) << endl;

    return 0;
}
