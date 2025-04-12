#include <iostream>
using namespace std;

const int SIZE = 14;
// save the puzzle into a 2-d array
void initBoard (string array[][SIZE]) {
    string holder = "";
    int i = 0;
    for (int p = 0; p < SIZE; p++) {
        getline(cin, holder);
        for (int j = 0; j < holder.length(); j += 2) {
            array[i][j / 2] = holder[j]; 
        }
        i++;
    }
}
// save the words we need to find in a 1-d array
void initWords (string array[], int size) {
    string holder = "";
    for (int i = 0; i < size; i ++) {
        cin >> holder;
        array[i] = holder;
    }
}

void printWordBoard(string wordBoard[][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            cout << wordBoard[i][j] << " ";  // Print each element
        }
        cout << endl;  // Print a new line after each row
    }
}

void printWordsToFind(string wordsToFind[], int size) {
    for (int i = 0; i < size; i++) {
        cout << wordsToFind[i] << " ";  // Print each element followed by a space
    }
    cout << endl;  // Print a newline after the last element
}

void up (string wordBoard[][SIZE], string wordsToFind[], int size, string the_word, int i, int j) {
    string result = "";
    bool found = false;
    while (i > 0 && !found) {
        result += wordBoard[i][j];
        if (result == the_word) {
            found = true;
            // delete it in the array after finding it
            for (int p = 0; p < size; p++) {
                if (wordsToFind[p] == the_word) {
                    wordsToFind[p] = "";
                }
            }
        }
        if (i < 0) {
            break;
        }
        i--;
    }
    if (found) {
        cout << the_word << " found at" << "(" << i << "," << j << ")" << "going up" << endl;
    }
}

void upright(string wordBoard[][SIZE], string wordsToFind[], int size, string the_word, int i, int j) {
    string result = "";
    bool found = false;
    while (i > 0 && j < SIZE && !found) {
        result += wordBoard[i][j];
        if (result == the_word) {
            found = true;
            // Delete it in the array after finding it
            for (int p = 0; p < size; p++) {
                if (wordsToFind[p] == the_word) {
                    wordsToFind[p] = "";
                }
            }
        }
        if (i < 0 || j >= SIZE) {
            break;
        }
        i--;
        j++;
    }
    if (found) {
        cout << the_word << " found at (" << i << "," << j << ") going up-right" << endl;
    }
}

void right(string wordBoard[][SIZE], string wordsToFind[], int size, string the_word, int i, int j) {
    string result = "";
    bool found = false;
    while (j < SIZE && !found) {
        result += wordBoard[i][j];
        if (result == the_word) {
            found = true;
            for (int p = 0; p < size; p++) {
                if (wordsToFind[p] == the_word) {
                    wordsToFind[p] = "";
                }
            }
        }
        if (j >= SIZE) {
            break;
        }
        j++;
    }
    if (found) {
        cout << the_word << " found at (" << i << "," << j << ") going right" << endl;
    }
}

void downright(string wordBoard[][SIZE], string wordsToFind[], int size, string the_word, int i, int j) {
    string result = "";
    bool found = false;
    while (i < SIZE && j < SIZE && !found) {
        result += wordBoard[i][j];
        if (result == the_word) {
            found = true;
            for (int p = 0; p < size; p++) {
                if (wordsToFind[p] == the_word) {
                    wordsToFind[p] = "";
                }
            }
        }
        if (i >= SIZE || j >= SIZE) {
            break;
        }
        i++;
        j++;
    }
    if (found) {
        cout << the_word << " found at (" << i << "," << j << ") going down-right" << endl;
    }
}

void down(string wordBoard[][SIZE], string wordsToFind[], int size, string the_word, int i, int j) {
    string result = "";
    bool found = false;
    while (i < SIZE && !found) {
        result += wordBoard[i][j];
        if (result == the_word) {
            found = true;
            for (int p = 0; p < size; p++) {
                if (wordsToFind[p] == the_word) {
                    wordsToFind[p] = "";
                }
            }
        }
        if (i >= SIZE) {
            break;
        }
        i++;
    }
    if (found) {
        cout << the_word << " found at (" << i << "," << j << ") going down" << endl;
    }
}

void downleft(string wordBoard[][SIZE], string wordsToFind[], int size, string the_word, int i, int j) {
    string result = "";
    bool found = false;
    while (i < SIZE && j >= 0 && !found) {
        result += wordBoard[i][j];
        if (result == the_word) {
            found = true;
            for (int p = 0; p < size; p++) {
                if (wordsToFind[p] == the_word) {
                    wordsToFind[p] = "";
                }
            }
        }
        if (i >= SIZE || j < 0) {
            break;
        }
        i++;
        j--;
    }
    if (found) {
        cout << the_word << " found at (" << i << "," << j << ") going down-left" << endl;
    }
}

void left(string wordBoard[][SIZE], string wordsToFind[], int size, string the_word, int i, int j) {
    string result = "";
    bool found = false;
    while (j >= 0 && !found) {
        result += wordBoard[i][j];
        if (result == the_word) {
            found = true;
            for (int p = 0; p < size; p++) {
                if (wordsToFind[p] == the_word) {
                    wordsToFind[p] = "";
                }
            }
        }
        if (j < 0) {
            break;
        }
        j--;
    }
    if (found) {
        cout << the_word << " found at (" << i << "," << j << ") going left" << endl;
    }
}

void upleft(string wordBoard[][SIZE], string wordsToFind[], int size, string the_word, int i, int j) {
    string result = "";
    bool found = false;
    while (i > 0 && j > 0 && !found) {
        result += wordBoard[i][j];
        if (result == the_word) {
            found = true;
            for (int p = 0; p < size; p++) {
                if (wordsToFind[p] == the_word) {
                    wordsToFind[p] = "";
                }
            }
        }
        if (i < 0 || j < 0) {
            break;
        }
        i--;
        j--;
    }
    if (found) {
        cout << the_word << " found at (" << i << "," << j << ") going up-left" << endl;
    }
}

int main() {
    string wordBoard[SIZE][SIZE];
    initBoard (wordBoard);
    int size = 0;
    cin >> size;
    string wordsToFind[size];
    initWords (wordsToFind, size);
    printWordBoard (wordBoard);
    cout << size << endl;
    printWordsToFind (wordsToFind, size);
    for (int k = 0; k < size; k++) {
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                up(wordBoard, wordsToFind, size, wordsToFind[k], i, j);
                upright(wordBoard, wordsToFind, size, wordsToFind[k], i, j);
                right(wordBoard, wordsToFind, size, wordsToFind[k], i, j);
                downright(wordBoard, wordsToFind, size, wordsToFind[k], i, j);
                down(wordBoard, wordsToFind, size, wordsToFind[k], i, j);
                downleft(wordBoard, wordsToFind, size, wordsToFind[k], i, j);
                left(wordBoard, wordsToFind, size, wordsToFind[k], i, j);
                upleft(wordBoard, wordsToFind, size, wordsToFind[k], i, j);
            }
        }
        if (wordsToFind[k] != "") {
            cout << wordsToFind[k] << " not found" << endl;
        }
    }
}


