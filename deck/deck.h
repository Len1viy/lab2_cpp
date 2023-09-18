//
// Created by vadim on 17.09.2023.
//

#ifndef _DECK_H
#define _DECK_H
#include <iostream>
#include "../cards/cards.h"


namespace Lab2 {
    class Deck{
    private:
        Card *deck;
        int count;
        int cardsMatrix[4][13];
        int head;
        int tail;
    public:
        Deck(void);
        Deck(int cnt);
        ~Deck(){};
        Card *getDeck() {
            return deck;
        }


        int getCount() {return count;}


        auto getCardMatrix() {return cardsMatrix;}
        void createCardsMatrix(int cnt);
        void deleteDublicateCardsMatrix();
        void changeCardsMatrix(int rang, int suit);

        std::ostream &printCardsMatrix(std::ostream &c);
        std::ostream &printDeck(std::ostream &c);
        friend void operator >> (Deck &self, Deck &other);

    };

}

#endif //_DECK_H
