#define CATCH_CONFIG_MAIN
#include "../../catch.hpp"
#include "../deck/deck.cpp"
#include "../../SimpleClass/cards/cards.cpp"


TEST_CASE("DeckStaticConstructor") {
    SECTION("DefaultConstructor") {
        Lab2::Deck deck;
        REQUIRE(deck.getSize() == 52);
        REQUIRE(deck.checkRepeated() == 0);
    }
    SECTION("InitConstructor") {
        Lab2::Deck deck(15);
        REQUIRE(deck.getSize() == 15);
        REQUIRE(deck.checkRepeated() == 0);
        Lab2::Deck deck1(60);
        REQUIRE(deck1.getSize() == 60);
        REQUIRE(deck1.checkRepeated() == 1);
    }
    SECTION("TestExseptions") {
        Lab2::Deck deck(100);
        REQUIRE_THROWS(deck.push());
    }
}

TEST_CASE("DeckStaticMethods", "Setters") {
    SECTION("Setters") {
        Lab2::Deck deck(50);
        Lab2::Card card(11, 2);
        deck[10].setRang(10);
        deck[10].setSuit(2);
        REQUIRE(deck[10].getSuit() == 2);
        REQUIRE(deck[10].getRang() == 10);
        deck.push(5, 4);
        REQUIRE(deck.getDeck()[deck.getSize() - 1].getRang() == 5);
        REQUIRE(deck.getDeck()[deck.getSize() - 1].getSuit() == 4);
        deck[40] = card;
        REQUIRE(deck[40].getRang() == 11);
        REQUIRE(deck[40].getSuit() == 2);
    }
//    SECTION("METHODS") {
//        Lab2::Card card;
//        card.setSuit(2);
//        card.setRang(10);
//        REQUIRE(card.getRang() == 10);
//        REQUIRE(card.getSuit() == 2);
//        REQUIRE(card.formatString() == "10♥");
//        Lab2::Card card1(4, 2);
//        REQUIRE(card1.getRang() == 4);
//        REQUIRE(card1.getSuit() == 2);
//        Lab2::Card card2(10, 3);
//        REQUIRE(card <=> card1 == std::strong_ordering::greater);
//        REQUIRE(card1 <=> card == std::strong_ordering::less);
//        REQUIRE_THROWS(card2 <=> card);
//    }
}