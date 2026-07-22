#include <iostream>
using namespace std;

void checkInitials(char array[], char toCheck) {
    bool found = false;
    for (int i = 0; i < 11; i++) {
        if (array[i] == toCheck) {
            found = true;
            break;
        }
    }

    if (found) {
        cout << "Player is playing on the team" << endl;
    } else {
        cout << "Player is NOT playing on the team" << endl;
    }
}

int main() {
    char team[11];
    char toCheck;

    for (int i = 0; i < 11; i++) {
        cout << "Enter Initial of Player " << i + 1 << ": ";
        cin >> team[i];
    }

    cout << "Enter the Initial of the Player you want to check: ";
    cin >> toCheck;

    checkInitials(team, toCheck);
    return 0;
}
