# Name: FindNumber
# Group 84
  He Litong (UID:3035535315)
  Qiu Zeyu (UID:3035534206)

# Description

# In this program, a n*n matrix consisting of n^2 integers will be initialized. Two participants do not know the matrix at the beginning. The first participant will determine the 'n' by typing an integer ranging from 2 to 8. They are required to guess the number in the matrix in turns. Each time if one gets the number existing in the matrix, the number （may be one or more than one） will show up in the matrix. If one guesses a number not existing, his most previous right guess will be eliminated(i.e. the previous right number will disapprear in the matrix). The one who first creates four numbers in a line (it can be a row, a column or a diagonal) wins. Then they can choose to continue or exist. If they continue, the second participant in the last game will be the first participant in this game and determine the size of matrix. Every time we will generate a random matrix.

# Functions

int main()

string init_answer (int n) // to generate a random answer matrix for each participate, with the size n*n

bool check (string input) // to check if the player's input is in the matrix

string moveon (bool check) // to show all of the correctly guessed numbers if return value of function “check” is “True”

string moveback (bool check) // to hide last correct numbers if return value of function “check” is “False”

bool if_win (string current[n,n]) // to check if any of the participants complete a line
