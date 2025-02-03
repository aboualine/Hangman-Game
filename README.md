# Hangman Game in C

This is a simple Hangman game implemented in C.  The player tries to guess a secret word by suggesting letters.  If the player guesses all the letters before running out of tries, they win!

## How to Compile and Run

1.  **Clone the repository:**
    ```bash
    git clone https://github.com/aboualine/Hangman-Game.git
    cd hangman
    ```

2.  **Compile the code:**
    ```bash
    gcc hangman.c -o hangman
    ```

3.  **Run the game:**
    ```bash
    ./hangman
    ```

## How to Play

1.  The game will display the secret word with underscores representing the unknown letters.
2.  You have a limited number of tries (6).
3.  Enter a letter and press Enter.
4.  If the letter is in the secret word, it will be revealed.
5.  If the letter is not in the word, you lose a try.
6.  If you guess all the letters correctly, you win!
7.  If you run out of tries, you lose.

## Features

*   Random word selection from a list.
*   Case-insensitive input (you can enter uppercase or lowercase letters).
*   Checks for duplicate guesses (you won't be penalized for guessing the same letter twice).
*   Clear prompts and output messages.

## Contributing

Contributions are welcome!  Feel free to submit pull requests for bug fixes, new features, or improvements.


## Word List

The current word list is defined within the `hangman.c` file.  You can modify it to add or remove words.

## Future Improvements

*   Implement different difficulty levels.
*   Add a scoring system.
*   Improve the user interface (consider using a library like ncurses for a more interactive experience).
*   Allow the user to choose the word category.
