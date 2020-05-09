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

int main()

int** init_matrix(int n) // to generate a random answer matrix for each participate, with the size n*n

void numberset(vector<int> &all_num, int** matrix, int n)
  // generate a vector that contains all the distinct numbers in the initial matrix

bool existence(vector<int> all_num, int n)
  // check if the input number is in the vector(as mentioned before)

void insert(Node * & head, int n)
  //insert the new right number to the end of existing right numbers

void moveon (int** matrix, int n, Node * & head) 
  // to show all of the correctly guessed numbers if return value of function “check” is “True”

void moveback (int** matrix, int n, Node * & head) 
  // to hide last correct numbers if return value of function “check” is “False”

bool if_win (int** matrix, int n, Node * & head)
  // to check if any of the participants complete a line


# Compilation and execution instructions.


Before starting, you will see on the screen a line of greetings ("Welcome to FindNumber!"), it is from a file named "greetings.txt".
To start the game, input a integer (n) for the game to generate a n * n matrix with random integers 1~20 (including).
No screen output for now.
Now, you can start to guess which integers the matrix contains, and input one of your guesses.
If your guess is correct, a screen output of "Yes", and the partly revealed matrix will appear.
If not, you will see a "No" on screen, and a matrix with the progress by your last guess (i.e. if the guess is wrong, the game takes one step back for you).
The matrix only shows the correctly guessed integer(s), with other integers represented by an "*".
Then you can either enter "end" to quit the game, or start your next guess by entering another integer, with the same output patterns above, until you get all the integers correct.
After having all the correct answers, the screen will say "Congratulations! You won in x steps.", where "x" is the steps you take to complete the matrix.
Then you will see an output asking if you want to play this again, enter "cont" or "end" to play it again or quit the game.
The playing record (winning output) of each round will be stored to file "records.txt".
