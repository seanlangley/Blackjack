//
//  classFiles.cpp
//  blackjack
//
//  Created by Sean Langley on 6/30/16.
//  Copyright © 2016 Sean Langley. All rights reserved.
//
#include <iostream>
#include <stdio.h>
#include "classFiles.h"

//////////////////////////////////////////
///////Money Class
//////////////////////////////////////////
bool money::placeBet(int bet)
{
    total -= bet;
    
    if(total <= 0)
        return false;
    currentBet = bet;
    
    std::cout << "Current money total: " << getMoney() << std::endl;
    return true;
}


//////////////////////////////////////////
///////PlayerHand class
//////////////////////////////////////////
playerHand::playerHand()
{
    
    for(int i = 0; i < 2; i++)
        addCard();
    stand = false;
    
}


int playerHand::getCardSum()
{
    int cardSum = 0;
    for(std::list<card>::iterator it = myHand.begin(); it != myHand.end(); it++)
    {
        cardSum += it->number;
    }
    return cardSum;
}

void playerHand::addCard()
{
    int card = rand() % 14;
    struct card newCard;
    newCard.faceFlag = false;
    
    if(card >= 10)
    {
        newCard.number = 10;
        switch(card)
        {
            case 10:
                newCard.name = "10";
                
                break;
            case 11:
                newCard.name = "Jack";
                break;
            case 12:
                newCard.name = "Queen";
                break;
            case 13:
                newCard.name = "King";
                break;
            default:
                std::cout << "Error selecting cards... \n";
                exit(1);
        }
    }
    
    else if(card == 0)
    {
        newCard.number = 1;
        newCard.name = "Ace";
    }
    else
    {
        newCard.number = card;
        card += '0';
        newCard.name = card;
        
    }
    if(newCard.faceFlag == true)
        newCard.number = 10;
    
    myHand.push_back(newCard);
    
}



void playerHand::removeCard()
{
    myHand.pop_back();
}

void playerHand::listCards()
{
    for(std::list<card>::iterator it = myHand.begin(); it != myHand.end(); it++)
    {
        std::cout << it->name << " ";
        
    }
    cout << endl;
}


//////////////////////////////////////////
///////DealerHand class
//////////////////////////////////////////

void dealerHand::listCards()
{
    card temp = *handBegin();
    std::cout << temp.name << " ";
    
    std::list<card>::iterator it = handBegin();
    std::advance(it, 1);
    for(; it != handEnd(); it++)
    {
        std::cout << "X ";
    }
    std::cout << std::endl;
}





















