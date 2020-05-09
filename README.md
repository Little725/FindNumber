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

# In this program, a n*n matrix consisting of n^2 integers will be initialized. The participant does not know the matrix at the beginning. The participant will determine the 'n' by typing an integer, and is required to guess the number in the matrix. Each time if the participant gets the number existing in the matrix, the number (along with existing right numbers) will show up in the matrix. If the participant guesses a number not existing, his most previous right guess will be eliminated(i.e. the previous right number will disapprear in the matrix). After every guess, they can opt to end the game or continue with it. When he completes all numbers in a line (it can be a row, a column or a diagonal), he wins. Then he can choose to continue or exit. If he continue, another round will start from the beginning. Every time after the game, a game record is written to a .txt file.

# Functions

1. Generation of random game sets or events
The games takes from the player an integer each round, based on which it generates a radom matrix containing integers from 1~20 (including).

2. Data structures for storing game status
The games uses struct Node.

3. Dynamic memory management
It uses vector<int> numbers to store all the distinct integers in the matrix, and creates a linked list starting from head to store all the distinct guessed right integers. When the player's guess is correct, the moveon function adds the integer into the linked list,; whereas when the player's guess is wrong, the moveback function takes away one most previous guessed correct integer from the linked list. The display function prints the matrix which the player currently has.

4. File input/output
File input: it reads from "greetings.txt" to print a line upon the launch of the game, to welcome the player to the game.
File output: it creates and writes to a filed called "records", storing in lines the winning or leaving records of the player from each round.

5. Program codes in multiple files
There is one .cpp file containing the main code and five header files.


# Compilation and execution instructions.

Before starting, you will see on the screen a line of greetings ("Welcome to FindNumber!"), it is from a file named "greetings.txt".
As instructed, to start the game, input an integer (n) for the game to generate a n * n matrix with random integers 1~20 (including).
Input another integer following the instruction on the screen. This is used to generate the random matrix.
Now, you can start to guess which integer the matrix contains, and input one of your guesses.
If your guess is correct, a screen output of "You got a right answer!", and the partly revealed matrix will appear.The matrix only shows the correctly guessed integer(s), with other integers represented by an "*".
If not, you will see "Sorry, you got a wrong answer." on screen, followed in the next few lines a matrix with the progress by your last guess (i.e. if the guess is wrong, the game takes one step back for you).
After every guess, you can either enter "end" to quit the game, or start your next guess by entering another integer.
After you complete a row, a column, or a diagonal, you win this set and the screen will say "Congratulations! You won in x steps.", where "x" is the steps you take to complete the matrix.
After you win this set or choose to leave this set, you can see an output asking if you want to "play again" (it starts a new set for you), enter "yes" or "no" to play it again or quit the game.
The playing record (winning / ending output) of each set will be stored to file "records.txt".
