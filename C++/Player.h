#include <string>

#ifndef PLAYER_H
#define PLAYER_H

class Player
{
private:
    std::string m_name;
    int m_place;
    int m_purse;
    bool m_inPenaltyBox;
    
public:
    Player(std::string& name) : m_name(name),m_place(0),m_purse(0),m_inPenaltyBox(false) {};
    
    bool inPenaltyBox() const { return m_inPenaltyBox; };
    const std::string& playerName() const { return m_name; };
    int place() const { return m_place; };
    int coins() const { return m_purse; };
    
    void inPenaltyBox(bool val);
    void move(int roll);
    void pay();
};

#endif // PLAYER_H
