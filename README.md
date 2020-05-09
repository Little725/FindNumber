# Name: FindNumber
# Group 84
  He Litong (UID:3035535315)
  Qiu Zeyu (UID:3035534206)

# FindNumber
# Name: FindNumber
# Group 84
  He Litong (UID:3035535315)
  Qiu Zeyu (UID:3035534206)

# Description

# In this program, a n*n matrix consisting of n^2 integers will be initialized. The participant does not know the matrix at the beginning. The participant will determine the 'n' by typing an integer, and is required to guess the number in the matrix. Each time if they gets the number existing in the matrix, the number （may be one or more than one） will show up in the matrix. If they guesses a number not existing, their most previous right guess will be eliminated(i.e. the previous right number will disapprear in the matrix). After every guess, they can opt to end the game or continue with it. When they completes all numbers in a line (it can be a row, a column or a diagonal), they wins. Then they can choose to continue or exit. If they continue, another round will start from the beginning.

# Functions

1. Generation of random game sets or events
The games takes from the player an integer each round, based on which it generates a radom matrix containing integers from 1~20 (including).

2. Data structures for storing game status
The games uses struct Node.

3. Dynamic memory management
It stores all the correct integers in vector<int> numbers, all the distinct guessed integers in a linked linked from struct Node. When the player's guess is correct, the moveon function adds the integer into the linked list,; whereas when the player's guess is wrong, the moveback function takes away one most previous guessed correct integer from the linked list. The display function prints the matrix which the player currently has.

4. File input/output
File input: it reads from "greetings.txt" to print a line upon the launch of the game, to welcome the player to the game.
File output: it creates and writes to a filed called "records", storing in lines the winning records of the player from each round.

5. Program codes in multiple files
Our program has only one file.

6. Proper indentation and naming styles
The program has proper indentation and naming styles with meaningful variable names, which makes the codes easily intelligible. e.g. "matrix" represents the matrix generated, and "checkrow" in the function row_win means the number of guessed integer in the row under checking.

7. In-code documentation


# Compilation and execution instructions.

Before starting, you will see on the screen a line of greetings ("Welcome to FindNumber!"), it is from a file named "greetings.txt".
To start the game, input a integer (n) for the game to generate a n * n matrix with random integers 1~20 (including).
Input another integer following the screen output. This is used to generate the random matrix.
Now, you can start to guess which integers the matrix contains, and input one of your guesses.
If your guess is correct, a screen output of "You got a right answer!", and the partly revealed matrix will appear.The matrix only shows the correctly guessed integer(s), with other integers represented by an "*".
If not, you will see "Sorry, you got a wrong answer." on screen, followed in the next few lines a matrix with the progress by your last guess (i.e. if the guess is wrong, the game takes one step back for you).
After every guess, you can either enter "end" to quit the game, or start your next guess by entering another integer, with the same output patterns above, until you get all the integers correct.
After having all the correct answers, the screen will say "Congratulations! You won in x steps.", where "x" is the steps you take to complete the matrix.
After you win a game or leaving a game after some guess(es), you can see an output asking if you want to play this again, enter "yes" or "no" to play it again or quit the game.
The playing record (winning output) of each round will be stored to file "records.txt".
