//
// Created by vadim on 17.09.2023.
//

#ifndef _DECK_H
#define _DECK_H
#include <iostream>
#include "../../SimpleClass/cards/cards.h"


namespace Lab2 {
    class Deck{
    private:
        int top = 0;
        static const int countMax = 100;
        Card deck[countMax];
        int cardsMatrix[4][13];
    public:
        Deck(void);
        Deck(int cnt);
        ~Deck(){};


        Card *getDeck() {
            return deck;
        }


        int getSize() {return top+1;}
        auto getCardMatrix() {return cardsMatrix;}
        int getMaxSize() {return countMax;}
        void createCardsMatrix(int cnt);
        void deleteDublicateCardsMatrix();
        void changeCardsMatrix(int rang, int suit, int op);
        void push(const Card & = Lab2::Card());
        void push(int nrang, int nsuit);
        Card pop();

        void operator+(Deck &);

        std::ostream &printCardsMatrix(std::ostream &c);
        std::ostream &printDeck(std::ostream &c);
        friend void operator >> (Deck &self, Deck &other);

        void mixing();

        int checkRepeated();
        Card &operator[] (int index);
        Deck oneSuitDeck(int suit);
        void orderByRang();
        void orderBySuit();
    };

}

#endif //_DECK_H
