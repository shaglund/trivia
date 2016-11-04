#include "Game.h"
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <sstream>

using namespace std;

static string createTopicQuestion(const char *topic, int index)
{
    char indexStr[127];
    sprintf(indexStr, "%s Question %d", topic, index);
    return indexStr;
}

Game::Game() {
    for (int i = 0; i < 50; i++)
    {
        popQuestions.push_back(createTopicQuestion("Pop", i));
        scienceQuestions.push_back(createTopicQuestion("Science", i));
        sportsQuestions.push_back(createTopicQuestion("Sports", i));
        rockQuestions.push_back(createTopicQuestion("Rock", i));
    }
}

bool Game::isPlayable()
{
    return (howManyPlayers() >= 2);
}

bool Game::add(string playerName){
    players.push_back(Player(playerName));

    cout << playerName << " was added" << endl;
    cout << "They are player number " << players.size() << endl;
    currentPlayer = players.begin();
    return true;
}

int Game::howManyPlayers()
{
    return players.size();
}

void Game::roll(int roll)
{
    cout << currentPlayer->playerName() << " is the current player" << endl;
    cout << "They have rolled a " << roll << endl;
    bool isPlaying=true;

    if (currentPlayer->inPenaltyBox())
    {
        if (roll % 2 != 0)
        {
            cout << currentPlayer->playerName() << " is getting out of the penalty box" << endl;            
            isGettingOutOfPenaltyBox = true;
        }
        else
        {
            cout << currentPlayer->playerName() << " is not getting out of the penalty box" << endl;
            isPlaying = isGettingOutOfPenaltyBox = false;
        }
    }
    if (isPlaying)
    {
        moveCurrentPlayer(roll);
        askQuestion();
    }

}

void Game::moveCurrentPlayer(int roll) {
    currentPlayer->move(roll);
    cout << currentPlayer->playerName() << "'s new location is " << currentPlayer->place() << endl;
}

static void askTopicQuestion(list<string>& questions) {
    cout << questions.front() << endl;
    questions.pop_front();
}

void Game::askQuestion()
{
    cout << "The category is ";
    switch(currentPlayer->place() % 4) {
        case 0:
            cout << "Pop" << endl;
            askTopicQuestion(popQuestions);
            break;
        case 1:
            cout << "Science" << endl;
            askTopicQuestion(scienceQuestions);
            break;
        case 2:
            cout << "Sports" << endl;
            askTopicQuestion(sportsQuestions);
            break;
        default:
            cout << "Rock" << endl;
            askTopicQuestion(rockQuestions);
            break;
    }
}

bool Game::correctAnswer() {
    bool winner = true;
    if (currentPlayer->inPenaltyBox())
    {
        if (isGettingOutOfPenaltyBox)
        {
            currentPlayer->inPenaltyBox(false);
            winner = didPlayerWin();
        }
    }
    else
    {
        winner = didPlayerWin();
    }
    nextPlayer();
    return !winner;
    
}

bool Game::wrongAnswer()
{
    cout << "Question was incorrectly answered" << endl;
    cout << currentPlayer->playerName() + " was sent to the penalty box" << endl;
    currentPlayer->inPenaltyBox(true);
    nextPlayer();
    return true;
}


bool Game::didPlayerWin()
{
    cout << "Answer was correct!!!!" << endl;
    currentPlayer->pay();
    cout << currentPlayer->playerName()
         << " now has "
         << currentPlayer->coins()
        <<  " Gold Coins." << endl;
        
    return (currentPlayer->coins() == 6);
}

void Game::nextPlayer() {
    currentPlayer++;
    if (currentPlayer == players.end())
        currentPlayer = players.begin();
}
