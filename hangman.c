#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 20
#define MAX_TRIES 6

// Function to choose a random word from the list
char *chooseWord(const char *wordList[], int listSize) {
    srand(time(NULL)); // Seed the random number generator
    int randomIndex = rand() % listSize;
    return (char *)wordList[randomIndex]; // Return a pointer to the chosen word
}

int main() {
    const char *wordList[] = {"apple", "banana", "orange", "grape", "kiwi", "mango", "pineapple", "watermelon"};
    int listSize = sizeof(wordList) / sizeof(wordList[0]);

    char *secretWord = chooseWord(wordList, listSize);
    int wordLength = strlen(secretWord);
    char guessedWord[MAX_WORD_LENGTH];
    for (int i = 0; i < wordLength; i++) {
        guessedWord[i] = '_'; // Initialize guessed word with underscores
    }
    guessedWord[wordLength] = '\0'; // Null-terminate the string

    int tries = 0;
    char guessedLetters[MAX_TRIES]; // Store guessed letters
    int numGuessedLetters = 0;

    printf("Welcome to Hangman!\n");

    while (tries < MAX_TRIES) {
        printf("\nSecret word: %s\n", guessedWord);
        printf("Tries remaining: %d\n", MAX_TRIES - tries);

        char guess;
        printf("Enter your guess: ");
        scanf(" %c", &guess);  // Note the space before %c to consume any leftover newline

        guess = tolower(guess); // Convert guess to lowercase for case-insensitivity

        // Check if the letter has already been guessed
        int alreadyGuessed = 0;
        for (int i = 0; i < numGuessedLetters; i++) {
            if (guessedLetters[i] == guess) {
                alreadyGuessed = 1;
                break;
            }
        }

        if (alreadyGuessed) {
            printf("You've already guessed that letter.\n");
            continue; // Ask for a new guess
        }


        guessedLetters[numGuessedLetters++] = guess; // Add the guessed letter to the list

        int correctGuess = 0;
        for (int i = 0; i < wordLength; i++) {
            if (secretWord[i] == guess) {
                guessedWord[i] = guess;
                correctGuess = 1;
            }
        }

        if (!correctGuess) {
            printf("Incorrect guess.\n");
            tries++;
        }

        // Check if the player has won
        if (strcmp(guessedWord, secretWord) == 0) {
            printf("\nCongratulations! You guessed the word: %s\n", secretWord);
            return 0; // End the game
        }
    }

    printf("\nYou ran out of tries. The word was: %s\n", secretWord);

    return 0;
}