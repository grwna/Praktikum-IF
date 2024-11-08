#include <stdio.h>
#include <string.h>
#include "mesinkata.h"  // Include mesinkata and mesinkarakter utilities

// Define a structure to map words to numbers
typedef struct {
    char *word;
    int value;
} NumberWord;

// Array for word-number mappings
NumberWord words[] = {
    {"nol", 0}, {"satu", 1}, {"dua", 2}, {"tiga", 3}, {"empat", 4},
    {"lima", 5}, {"enam", 6}, {"tujuh", 7}, {"delapan", 8}, {"sembilan", 9},
    {"sepuluh", 10}, {"sebelas", 11},
    {"seratus", 100}, {"seribu", 1000}
};

// Function to find the numeric value for a word
int findNumberValue(char *word) {
    for (int i = 0; i < sizeof(words) / sizeof(NumberWord); i++) {
        if (strcmp(words[i].word, word) == 0) {
            return words[i].value;
        }
    }
    return -1;  // If no match is found
}

// Function to clear the current word buffer after processing each word
void clearWordBuffer() {
    currentWord.Length = 0;
    memset(currentWord.TabWord, 0, sizeof(currentWord.TabWord));
}

// Function to process the input and replace word numbers with numeric values
void processSentence() {
    STARTWORD();  // Start reading the sentence
    
    while (!EndWord) {
        int currentNumber = 0;
        int tempValue = 0;
        int multiplier = 1;
        int isNumberPhrase = 0;  // Changed to int instead of boolean for compatibility

        // Check if the current word is a number word
        while (!EndWord && (tempValue = findNumberValue(currentWord.TabWord)) != -1) {
            isNumberPhrase = 1;

            // Handle special cases like "ratus", "ribu"
            if (strcmp(currentWord.TabWord, "ratus") == 0) {
                multiplier = 100;  // Multiply current number by 100 for "ratus"
            } else if (strcmp(currentWord.TabWord, "ribu") == 0) {
                multiplier = 1000; // Multiply current number by 1000 for "ribu"
            } else {
                currentNumber += tempValue; // Add the value of other number words
            }

            ADVWORD();  // Move to the next word
        }

        // If a number phrase was detected, print the number
        if (isNumberPhrase) {
            printf("%d", currentNumber * multiplier);
        } else {
            // Print the current word if it's not a number
            printf("%s", currentWord.TabWord);
        }

        // Add a space after the word or number (except for the last word)
        if (!EndWord) {
            printf(" ");
        }

        // Clear the word buffer to prevent leftover characters
        clearWordBuffer();

        // Advance to the next word
        ADVWORD();  // Ensure we always move to the next word after processing
    }
}

int main() {
    processSentence();
    return 0;
}
