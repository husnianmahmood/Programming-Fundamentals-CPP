#include <iostream>
using namespace std;

int calculate2High(int arr[], int size) {
    int highest = arr[0];
    int secondHighest = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] > highest) {
            secondHighest = highest;
            highest = arr[i];
        } else if (arr[i] > secondHighest && arr[i] != highest) {
            secondHighest = arr[i];
        }
    }
    return secondHighest;
}

int calculate2Low(int arr[], int size) {
    int lowest = arr[0];
    int secondLowest = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] < lowest) {
            secondLowest = lowest;
            lowest = arr[i];
        } else if (arr[i] < secondLowest && arr[i] != lowest) {
            secondLowest = arr[i];
        }
    }
    return secondLowest;
}

int main() {
    int n;
    cin >> n;
    int arr[100];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    cout << "2nd Lowest = " << calculate2Low(arr, n) << endl;
    cout << "2nd Highest = " << calculate2High(arr, n) << endl;
    return 0;
}
