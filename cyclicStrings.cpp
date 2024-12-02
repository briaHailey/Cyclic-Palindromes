/* Name: Bria Weisblat
Date: 11/18/2022
Section: 4
Assignment: Homework 6 Extra Credit Problem - Cyclic Palindromes
Due Date: 11/18/2022
About this project: This program searches for palindromes in user-entered strings by rotating the characters
in the strings to see if it forms a palindrome after each rotation.
Assumptions: Assume that the user will only enter the proper type of data. Assume that when this program
checks for a palindrome, it ignores case and spaces. Assume that each string will only contain lower and
uppercase letters, numerals, and spaces. Assume that you will have a maximum of 500 strings and 500
characters per string.


All work below was performed by Bria Weisblat */

#include <iostream>
#include <cctype>
#include <string>
#include <cstring>

using namespace std;

//Function Declarations
bool checkPalin(char arr[100]);
string checkPasscodes(char mat[][500], int numStrings);

int main() {
    char mat[500][500];
    cout << "Enter the strings: ";
    int i =0;
    bool emptyString = false;
    int numStrings = 0;

    // Stop allowing the user to enter strings once they enter a blank string
    while (!emptyString) {
        numStrings++;
        // Read in strings
        cin.getline(mat[i], 500);
        // If the string is empty
        if (strcmp(mat[i], "\0") == 0)
            emptyString = true;
        i++;
    }

    cout << "The palindrome passocdes are: " << endl << checkPasscodes(mat, numStrings);

    return 0;
}

// Function Definitions


bool checkPalin(char arr[]) {
    // Calculates the number of characters per string
    int numChars = strlen(arr);
    bool isPalin;

    int palinCount = 0;
    // cin.ignore('');
    int j = 0;
    int k = 0;
    // For each rotation
    for (int i = 0; i < numChars / 2; i++) {
        // Ignore spaces on the left
        if (arr[i+j] == ' ')
            j++;
        // Ignore spaces on the right
        if (arr[numChars-1-i-k] == ' ')
            k++;
        // Disregard character case when checking for palindromes
        if (tolower(arr[i + j]) == tolower(arr[numChars - 1 - i - k]))
            palinCount++;
    }

    // If each letter lines up to create a palindrome
    if (palinCount == numChars / 2)
        isPalin = true;
    else {
        isPalin = false;
    }

    int numRot = 0;

    // Rotates the string until a palindrome is found or until it has been fully rotated
    while (isPalin == false && numRot < numChars) {
        char lastIndex = arr[numChars - 1];

        // Shift each character in the string after arr[0] one index to the right
        for (int i = numChars -1 ; i > 0; i--) {
            arr[i] = arr[i-1];
        }

        // Puts the last character into the first index
        arr[0] = lastIndex;


        int palinCount = 0;

        int j = 0;
        int k = 0;
        // For each rotation
        for (int i = 0; i < numChars / 2; i++) {
            // Ignore spaces on the left
            if (arr[i+j] == ' ')
                j++;
            // Ignore spaces on the right
            if (arr[numChars-1-i-k] == ' ')
                k++;
            // Disregard character case when checking for palindromes
            if (tolower(arr[i + j]) == tolower(arr[numChars - 1 - i - k]))
                palinCount++;
        }

        // If each letter lines up to create a palindrome
        if (palinCount == numChars / 2)
            isPalin = true;
        else {
            isPalin = false;
        }
        numRot++;
    }
    return isPalin;
}

string checkPasscodes(char mat[][500], int numStrings){
    string fill;
    // For each string
    for (int i=0; i < numStrings; i++) {
        // See if the string contains a palindrome (originally or after rotation)
        if (checkPalin(mat[i]) == true){
            fill = fill + mat[i] + '\n';
        }

    }
    return fill;
}

