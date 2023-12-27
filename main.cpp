#include "Die.h"
#include <iostream>
#include <stdexcept>
#include <stdlib.h>
#include <time.h>

using namespace std;

int getTotal(Die&, Die&);

int main() {
  int numSides;
  // Comment 7: we want to initialize the total value of the player and computer as 0.
  int totalPlayer = 0;
  int totalCPU = 0;
  char again; // Comment 8: flag variable

  cout << "Let's play a game of 21!" << endl;
  cout << endl;
  cout << "---------------------------------" << endl;

  cout << "How many sides should a die have?" << endl;
  cout << "Type a positive integer here: ";
  cin >> numSides;

  // Comment 9: we need to put the seed here. If you put it in the roll() member function, it will generate the same number for die1 and die2.
  srand(time(NULL));

  Die die1 = Die(numSides);
  Die die2 = Die(numSides);

  cout << "\nWould you like to roll the dice?" << endl;
  cout << "Enter Y for yes or N for no: ";
  cin >> again;

  while (toupper(again) == 'Y') {
    // Comment 10: only when the total value is less than 21, we want to roll a die, otherwise the game is forcefully terminated.
    if (totalPlayer < 21) {
      die1.roll();
      die2.roll();
      totalCPU += getTotal(die1, die2);

      die1.roll();
      die2.roll();
      cout << "\nValue of Die 1: " << die1.getValue() << endl;
      cout << "Value of Die 2: " << die2.getValue() << endl;
      totalPlayer += getTotal(die1, die2);
      cout << "You have " << totalPlayer << " points." << endl;
      // Comment 11: when the player rolls the dice and the total value reaches 21 or more, we need to change the flag variable so that while loop terminates.
      if (totalPlayer >= 21)
        again = 'N';
      // Comment 12: we need if/else here otherwise the program asks again? Y/N regardless the total value is 21 or more.
      else {
        cout << "\nWould you like to roll the dice?" << endl;
        cout << "Enter Y for yes or N for no: ";
        cin >> again;
      }
    } else
      again = 'N';
  };

  // Comment 13: this means if the player rolls the dice at least once
  if (totalPlayer != 0) {
    cout << "\nThe CPU had " << totalCPU << " points." << endl;
    cout << "You had " << totalPlayer << " points." << endl;

    if (totalPlayer > totalCPU) {
      if (totalPlayer <= 21)
        cout << "\nCongratulations! You won!" << endl;
      else if (totalCPU <= 21)
        cout << "\nCPU won.. Better luck next time." << endl;
      else
        cout << "\nIt's a tie. Better luck next time." << endl;
    } else if (totalCPU > totalPlayer) {
      if (totalCPU <= 21)
        cout << "\nCPU won.. Better luck next time." << endl;
      else if (totalPlayer <= 21)
        cout << "\nCongratulations! You won!" << endl;
      else
        cout << "\nIt's a tie. Better luck next time." << endl;
    } else // Comment 14: if the total value of the player and CPU are the same
      cout << "\nIt's a tie. Better luck next time." << endl;
  } else
    cout << "\nSee you next time!" << endl;
}

int getTotal(Die& die1, Die& die2) { return die1.getValue() + die2.getValue(); }
