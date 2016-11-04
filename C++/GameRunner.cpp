#include <stdlib.h>
#include "Game.h"

int main()
{
    Game aGame;
    bool notAWinner=true;

    aGame.add("Chet");
    aGame.add("Pat");
    aGame.add("Sue");

    while(aGame.isPlayable() && notAWinner)
    {
        aGame.roll(rand() % 5 + 1);

        if (rand() % 9 == 7)
        {
            notAWinner = aGame.wrongAnswer();
        }
        else
        {
            notAWinner = aGame.correctAnswer();
        }
    };

}
