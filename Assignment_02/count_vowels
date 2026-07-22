#include <iostream>
using namespace std;

int countVowels(char word[]) {
    int count = 0;
    for (int i = 0; word[i] != '\0'; i++) {
        if (word[i] == 'a' || word[i] == 'e' || word[i] == 'i' || word[i] == 'o' || word[i] == 'u' ||
            word[i] == 'A' || word[i] == 'E' || word[i] == 'I' || word[i] == 'O' || word[i] == 'U') {
            count++;
        }
    }
    return count;
}

int main() {
    char word[100];
    cin >> word;
    cout << "Total Vowels: " << countVowels(word) << endl;
    return 0;
}
