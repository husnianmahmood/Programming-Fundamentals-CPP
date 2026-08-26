#include <iostream>
using namespace std;

int main() {
    int row, column;
    cout << "Enter the number of rows: ";
    cin >> row;
    cout << "Enter the number of columns: ";
    cin >> column;

    int records[100][100];
    cout << "enter the daily records " << endl;
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < column; j++) {
            cout << "Enter value for Row " << (i + 1) << ", Column " << (j + 1) << ": ";
            cin >> records[i][j];
        }
    }

    int finalResult = records[0][0];
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < column; j++) {
            if (i == 0 && j == 0) {
                // Skip subtracting the first element from itself
            } else {
                finalResult = finalResult - records[i][j];
            }
        }
    }

    cout << endl;
    cout << "The final result after subtraction is: " << finalResult << endl;

    return 0;
}
