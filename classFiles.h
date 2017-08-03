//
//  Header.h
//  blackjack
//
//  Created by Sean Langley on 5/15/16.
//  Copyright © 2016 Sean Langley. All rights reserved.
//

#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>
#include <list>
using namespace std;

#ifndef Header_h
#define Header_h

struct card
{
    std::string name;
    int number;
    bool faceFlag;
    
};

class money
{
public:
    money()
        :total(100){}
    bool placeBet(int bet);
    
    /** Inline Functions **/
    inline int getMoney(){return total;}
private:
    int total;
    int currentBet;
    
};


class playerHand
{
public:
    playerHand();
    ~playerHand(){return;}
    int getCardSum();
    void listCards();
    void addCard();
    void removeCard();
    
    /** Inline Functions **/
    inline void setStand(){stand = true;}
    inline bool didStand(){return stand;}
    inline std::list<card>::iterator handBegin(){return myHand.begin();}
    inline std::list<card>::iterator handEnd(){return myHand.end();}
    inline money* getMoney(){return &myMoney;}
private:
    std::list<card> myHand;
    money myMoney;
    bool stand;
    
};



class dealerHand : public playerHand
{
public:
    virtual ~dealerHand(){return;}
    virtual void listCards();
};






#endif /* Header_h */
