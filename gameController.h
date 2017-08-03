//
//  gameController.h
//  blackjack
//
//  Created by Sean Langley on 6/27/16.
//  Copyright © 2016 Sean Langley. All rights reserved.
//
#include "classFiles.h"
#ifndef gameController_h
#define gameController_h

bool didBust(playerHand* hand)
{
    if(hand->getCardSum() > 21) return true;
    else return false;
}


void placeBets(playerHand* yourHand)
{
    std::cout << "\nFive dollars to play (Five dollars have been subtracted automatically)" << std::endl;
    int bet;
    
loop:
    std::cout << "How much would you like to bet? (5/10/25/50/100)" << std::endl;
    cin >> bet;
    
    money* temp = yourHand->getMoney();

    switch(bet)
    {
        case 5:
            if(temp->placeBet(5) == false){
                std::cout << "No money left!" << std::endl;
                return;
            }
            
            else break;
        case 10:
            if(temp->placeBet(10) == false){
                std::cout << "No money left!" << std::endl;
                return;
            }
            else break;
        case 25:
            if(temp->placeBet(25) == false){
                std::cout << "No money left!" << std::endl;
                return;
            }
            break;
        case 50:
            if(temp->placeBet(50) == false){
                std::cout << "No money left!" << std::endl;
                return;
            }
            break;
        case 100:
            if(temp->placeBet(100) == false){
                std::cout << "No money left!" << std::endl;
                return;
            }
            break;
        default:
            std::cout << "You must place a bet" << std::endl;
            goto loop;
            break;
    }
}



bool playerTurn(playerHand* yourHand)
{
    int cardSum = yourHand->getCardSum();
    
    if(cardSum > 21)
    {
        cout << "Bust!" << endl;
        return false;
    }
    
    std::cout << "Hit or stand? (h/s)" << std::endl;
    char move;
    
    
    for(;;)
    {
        bool flag = true;
        std::cin >> move;
        switch (move)
        {
            case 'h':
            {
                yourHand->addCard();
                if(yourHand->getCardSum() > 21)
                    return false;
                
                break;
            }
                
            case 's':
                yourHand->setStand();
                break;
            default:
                flag = false;
                
        }
        
        if(flag == true)
            break;
        else
            continue;
        
        
    }
    return true;
    
}

bool dealerTurn(dealerHand* dealerHand)
{
    int cardSum = dealerHand->getCardSum();
    
    if(cardSum >= 17)
        return false;
    else
        return true;
}



#endif /* gameController_h */







