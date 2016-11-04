#include <iostream>
#include <list>
#include <vector>
#include "Player.h"
using namespace std;

#ifndef GAME_H_
#define GAME_H_

class Game{

private:
    vector<Player> players;

    list<string> popQuestions;
    list<string> scienceQuestions;
    list<string> sportsQuestions;
    list<string> rockQuestions;

    vector<Player>::iterator currentPlayer;
    bool isGettingOutOfPenaltyBox;

    void askQuestion();
    bool didPlayerWin();
    void nextPlayer();
    void moveCurrentPlayer(int roll);

public:
    Game();
    bool isPlayable();
    bool add(string playerName);

    int howManyPlayers();
    void roll(int roll);
    bool correctAnswer();
    bool wrongAnswer();

};

#endif /* GAME_H_ */
