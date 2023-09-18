#include <iostream>
#include "cards/cards.h"
#include "input/input.h"
#include "deck/deck.h"

// 1 - ?
// 2 - ?
// 3 - ?
// 4 - ?


int main() {
    system("chcp 65001");
    srand(time(0));
//    Lab2::Card card1 = Lab2::Card();
//    Lab2::Card card2 = Lab2::Card();
//    Lab2::Card card3 = Lab2::Card();
//    Lab2::Deck dc = Lab2::Deck();
    Lab2::Deck dc(5);
    Lab2::Deck dc1(4);

//    std::cout << std::endl;

    try {
        dc.printDeck(std::cout);
        std::cout << std::endl;
        std::cout << "------------------" << std::endl;

        dc1.printDeck(std::cout);
        std::cout << std::endl;
        std::cout << "------------------" << std::endl;
        dc1 >> dc;
        dc.printDeck(std::cout);

        std::cout << std::endl;
        std::cout << "------------------" << std::endl;
        dc1.printDeck(std::cout);

    } catch (std::exception &exception) {
        std::cout << exception.what() << std::endl;
    }

//    int command;
//    help();
//    do {
//        std::cout << "Input command: ";
//        getNum(command);
//        try {
//            if (command == 1) {
//                Lab2::Card card = Lab2::Card();
//                int rang;
//                std::cout << "Input rang: ";
//                card.setRang(getNum(rang));
//            }
//        } catch (std::exception &exception) {
//            cout << exception.what() << endl;
//        }
//    }
//    while (command != 0);



    return 0;
}
