//montyhall.c
//performs 100000 runs of the monty hall problem

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char *argv[]) {
    
    printf("Running 100000 runs of the monty hall problem, swapping doors every time.\n");
    int prizedoor[3] = {0, 0, 0};
    int pickeddoor[3] = {0, 0, 0};
    int pick;
    int prize;
    int monty_reveal;
    int unopened_door;
    int wins = 0;
    int runs;
    float pctWins;
    srand(time(NULL));
    
    for(runs = 0; runs < 100000; runs++) {
    
    pick = rand() % 3;
    prize = rand() % 3;
    prizedoor[prize] = 1; //place a prize behind a door 
    pickeddoor[pick] = 1; //player picks a door

    do {
        monty_reveal = rand() % 3;
    } while (monty_reveal == pick || monty_reveal == prize);
    
    // Determine the unopened door for the player to switch to
    for (int i = 0; i < 3; i++) {
        if (i != pick && i != monty_reveal) {
            unopened_door = i;
            break;
        }
    }
    //player switches to the unopened door
    pickeddoor[pick] = 0;
    pick = unopened_door;
    pickeddoor[pick] = 1;

    if (pick == prize) {
        wins += 1;     
    }
    //reset the doors for the next run
    for (int i = 0; i < 3; i++) {
        prizedoor[i] = 0;
        pickeddoor[i] = 0;
    }
    }
    printf("%d wins\n", wins);
    printf("%d runs\n", runs);
    pctWins = ((float)wins / (float)runs) * 100.0;

    printf("Your win rate is: %f\n", pctWins);
    printf("Conclusion: You should swap doors every time!\n");
    
    printf("End of program. Press any key to quit. \n");
    while (getchar() != '\n'); // Clear the input buffer

    return 0;
}