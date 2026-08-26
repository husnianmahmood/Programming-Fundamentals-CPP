#include <iostream>
using namespace std;

int countEvenNumbers(int arr[], int size) {
    int count = 0;
    for (int i = 0; i < size; i++) {
        if (arr[i] % 2 == 0) {
            count++;
        }
    }
    return count;
}

int countOddNumbers(int arr[], int size) {
    int count = 0;
    for (int i = 0; i < size; i++) {
        if (arr[i] % 2 != 0) {
            count++;
        }
    }
    return count;
}

int main() {
    int N;
    cout << "Enter Size of Array: ";
    cin >> N;
    
    int numbers[100];
    for (int i = 0; i < N; i++) {
        cout << "Enter value in index " << i << ": ";
        cin >> numbers[i];
    }

    int evenResult = countEvenNumbers(numbers, N);
    int oddResult = countOddNumbers(numbers, N);

    cout << "Number of Even numbers in Array: " << evenResult << endl;
    cout << "Number of Odd numbers in Array: " << oddResult << endl;
    
    return 0;
}
