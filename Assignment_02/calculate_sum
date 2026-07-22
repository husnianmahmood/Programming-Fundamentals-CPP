#include <iostream>
#include <iomanip>
using namespace std;

double calculateSum(int arr[], int size) {
    double sum = 0;
    for (int i = 0; i < size; i++) {
        sum += arr[i];
    }
    return sum;
}

int main() {
    int n;
    cin >> n;
    int arr[100];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    cout << fixed << setprecision(2);
    cout << "Sum = " << calculateSum(arr, n) << endl;
    return 0;
}
