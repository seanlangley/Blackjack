//
//  main.cpp
//  blackjack
//
//  Created by Sean Langley on 5/15/16.
//  Copyright © 2016 Sean Langley. All rights reserved.
//

#include <iostream>
#include "classFiles.h"
#include "gameController.h"




void play()
{
    
    playerHand* yourHand = new playerHand;
    dealerHand* dealerHand = new class dealerHand;
    
    
    
    for(;;)
    {
        std::cout << "Your cards: " << std::endl;
        yourHand->listCards();
        std::cout << "Dealer's cards: " << std::endl;
        dealerHand->listCards();
        
/////////////////////////////
//Bets are placed here
//////////////////////////////
        placeBets(yourHand);
        
        
        if(playerTurn(yourHand))
        {
            if(yourHand->didStand())
                break;
            continue;
        }
        else if(didBust(yourHand))
        {
            std::cout << "Your cards: " << std::endl;
            yourHand->listCards();
            std::cout << "Bust!" << std::endl;
            return;
        }
    }
    std::cin.ignore();
    std::cout << "Press enter to start dealer's turn: " << std::endl;
    std::cin.ignore();
    
    for(;;)
    {
        dealerHand->playerHand::listCards();
        std::cout << "Press enter to continue";
        std::cin.ignore();
        
        if(dealerHand->getCardSum() >= 17) break;
        
        
        dealerHand->addCard();
        
        if(didBust(dealerHand))
        {
            std::cout << "Dealer Bust! \nYou win!" << std::endl;
            return;
        }
        else if(dealerHand->getCardSum() >= 17) break;
        
        else continue;
    }
    std::cout << "Dealer's cards: ";
    dealerHand->playerHand::listCards();
    
    std::cout << "Your cards: ";
    yourHand->listCards();
    
    
    if(yourHand->getCardSum() > dealerHand->getCardSum())
        std::cout << "You win!" << std::endl;
    else
        std::cout << "You lose!" << std::endl;
    
    
    
    
}



int main() {

    
    srand(static_cast<unsigned> (time(NULL)));
    std::cout << "Welcome to blackjack! Press any key to continue..." << std::endl;
    std::cin.ignore();
    std::cout << "Starting money: $100" << std::endl;
    play();
    
    for(;;)
    {
        
        std::cout << "Play again? (y/n)";
        char k;
        cin >> k;
        
        if(k == 'y')
        {
            std::cout << std::endl;
            play();
            continue;
        }
        else if(k == 'n')
        {
            std::cout << "Goodbye." << std::endl;
            break;
        }
        else
            continue;
    }
}











