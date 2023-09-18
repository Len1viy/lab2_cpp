//
// Created by vadim on 17.09.2023.
//

#include "deck.h"

// Добавление и удаление карт также можно реализовать через сдвиг (head - удаление, tail - добавление)
namespace Lab2 {
    Deck::Deck(int cnt) {
        if (cnt > 52) {
            int rang, suit;
            count = cnt;
            deck = new Card[cnt];
            createCardsMatrix(0);

            deleteDublicateCardsMatrix();


            for (int i = 52; i < count; i++) {
                rang = rand() % 13 + 2;
                suit = rand() % 4 + 1;
                deck[i].setRang(rang);
                deck[i].setSuit(suit);
                changeCardsMatrix(rang, suit);
            }
        }
        else {
            count = cnt;
            deck = new Card[count];
            createCardsMatrix(0);
            deleteDublicateCardsMatrix();
        }

    }
    Deck::Deck(void) {
        count = 52;
        deck = new Card[count];
        head = 0;
        tail = count - 1;
        createCardsMatrix(1);
        for (int i = 2; i < 15; i++) {
            for (int j = 1; j < 5; j++) {

                deck[(i-2) * 4 + (j - 1)].setRang(i);
                deck[(i-2) * 4 + (j - 1)].setSuit(j);
            }
        }
    }

    void Deck::createCardsMatrix(int cnt) {
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 14; j++) {
                cardsMatrix[i][j] = cnt;
            }
        }
    }

    std::ostream &Deck::printCardsMatrix(std::ostream &c) {
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 13; j++) {
                c << cardsMatrix[i][j] << " ";
            }
            c << std::endl;
        }
        return c;
    }

    std::ostream &Deck::printDeck(std::ostream &c) {
        for (int i = 0; i < count; i++) {
            deck[i].print(c);
        }
        return c;
    }

    void operator >> (Deck &self, Deck &other) {
        Deck newDeckForOther(other.count + 1);
        Deck newDeckForSelf(self.count - 1);
        for (int i = 0; i < other.count; i++) {
            newDeckForOther.deck[i].setRang(other.deck[i].getRang());
            newDeckForOther.deck[i].setSuit(other.deck[i].getSuit());
        }
        newDeckForOther.deck[other.count].setRang(self.deck[self.count - 1].getRang());
        newDeckForOther.deck[other.count].setSuit(self.deck[self.count - 1].getSuit());
        other = newDeckForOther;
        for (int i = 0; i < self.count; i++) {
            newDeckForSelf.deck[i].setRang(self.deck[i].getRang());
            newDeckForSelf.deck[i].setSuit(self.deck[i].getSuit());
        }
        self = newDeckForSelf;
    }


    void Deck::deleteDublicateCardsMatrix() {

        for (int i = 0; i < count; i++) {
            while (cardsMatrix[deck[i].getSuit() - 1][deck[i].getRang() - 2] == 1 && i < 52) {
                deck[i].setSuit(rand() % 4 + 1);
                deck[i].setRang(rand() % 13 + 2);
            }

            cardsMatrix[deck[i].getSuit() - 1][deck[i].getRang() - 2] += 1;
        }
    }

    void Deck::changeCardsMatrix(int rang, int suit) {
        cardsMatrix[suit - 1][rang - 2] += 1;
    }
}

