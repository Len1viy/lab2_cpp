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
        static const int reserveSize = 10;
        Card *deck;
        int countMax;
        int cardsMatrix[4][13];
        int top = 0;
        void resize(int new_size);
    public:
        Deck(void);
        Deck(int cnt);
        ~Deck(){delete[] deck;}

        Deck(const Deck &dc);
        Deck(Deck &&) noexcept;


        Card *getDeck() {
            return deck;
        }


        int getSize() {return top;}
        auto getCardMatrix() {return cardsMatrix;}
        int getMaxSize() {return countMax;}
        void createCardsMatrix(int cnt);
        void deleteDublicateCardsMatrix();
        void changeCardsMatrix(int rang, int suit, int op);
        void push(const Card & = Lab2::Card());
        void push(int nrang, int nsuit);
        Card pop(int index = 0);


        std::ostream &printCardsMatrix(std::ostream &c);
        std::ostream &printDeck(std::ostream &c);

        void mixing();

        int checkRepeated();
        Deck oneSuitDeck(int suit);
        void orderByRang();
        void orderBySuit();
        bool equal(const Deck &other);


        friend std::istream & operator<<(std::istream &, Deck &);
        friend std::ostream & operator>>(std::ostream &, Deck &);
        friend void operator >> (Deck &self, Deck &other);
        Card &operator[] (int index);
        Deck &operator=(const Deck&);
        void operator+=(Deck const &);
        Deck operator+(Deck const &);
        bool operator==(Deck &);
        void operator++();

    };

}

#endif //_DECK_H
