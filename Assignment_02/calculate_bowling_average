#include <iostream>
using namespace std;

double getBowlingAverage(int runsConceded, int wicketsTaken) {
    if (wicketsTaken == 0) {
        return 0.0;
    } else {
        return (double)runsConceded / wicketsTaken;
    }
}

int main() {
    int runs, wickets;
    cout << "    Bowling Average Calculator    " << endl;
    cout << "Enter the total runs conceded: ";
    cin >> runs;
    cout << "Enter the total wickets taken: ";
    cin >> wickets;

    cout << endl;
    cout << "Bowling Average: " << getBowlingAverage(runs, wickets) << endl;

    return 0;
}
