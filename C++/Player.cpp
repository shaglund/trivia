#include "Player.h"

void Player::move(int roll) {
    m_place += roll;
    if(m_place > 11)
        m_place -= 12;
}

void Player::pay() {
    m_purse++;
}

void Player::inPenaltyBox(bool val) { 
    m_inPenaltyBox = val;
}



