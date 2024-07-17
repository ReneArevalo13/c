// Write a C program to play a guessing game with the user that is equivalent to the Python program below. 
// Your program should use a while loop and multi-way branch if (i.e. use else if).

/* while True:
    try:
        line = input()
    except:  # If we get EOF
        break
    line = line.strip()
    guess = int(line)
    if guess == 42:
        print('Nice work!')
        break
    elif guess < 42 :
        print('Too low - guess again')
    else :
        print('Too high - guess again')
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    int guess;
    while(scanf("%d", &guess) != EOF) {
        if (guess == 42) {
            printf("Nice work!");
            break;
        }
        else if (guess < 42) {
            printf("Too low - guess again\n");
        }
        else {
            printf("Too high - guess again\n");
        }
    }
}
