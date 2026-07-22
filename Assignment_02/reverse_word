#include <iostream>
using namespace std;

void reverseWord(char word[], int size) {
    int start = 0;
    int end = size - 1;
    while (start < end) {
        char temp = word[start];
        word[start] = word[end];
        word[end] = temp;
        start = start + 1;
        end = end - 1;
    }
}

int main() {
    int size;
    char word[100];

    cout << "    Puzzle Game: Word Reverser    " << endl;
    cout << "Enter the number of letters in your word: ";
    cin >> size;
    cout << "Enter the word to reverse: ";
    cin >> word;

    reverseWord(word, size);
    cout << endl;
    cout << "Reversed Word: " << word << endl;

    return 0;
}
