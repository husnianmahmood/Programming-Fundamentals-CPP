#include <iostream>
using namespace std;

int main() {
    int row, column;
    cout << "Enter the number of rows: ";
    cin >> row;
    cout << "Enter the number of columns: ";
    cin >> column;

    int marks[100][100];
    int totalSum = 0;

    cout << "Enter the marks " << endl;
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < column; j++) {
            cout << "Enter mark for Row " << (i + 1) << ", Column " << (j + 1) << ": ";
            cin >> marks[i][j];
        }
    }

    for (int i = 0; i < row; i++) {
        for (int j = 0; j < column; j++) {
            totalSum = totalSum + marks[i][j];
        }
    }

    cout << endl;
    cout << "The total sum of all marks is: " << totalSum << endl;

    return 0;
}
