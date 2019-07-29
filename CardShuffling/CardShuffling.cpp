// CardShuffling.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define CARDS 52
#define FACES 13

struct  card
{
	const char *face;
	const char *suit;
};

typedef struct card Card;

void fillDeck(Card * const wDeck, const char * wFace[], const char * wSuit[]);
void shuffle(Card * const wDeck);
void deal(const Card * const wDeck);


int main(void)
{


	Card deck[CARDS];// define an array of cards (the deck)

	// initalize the array of pointers 13 in all
	const char *face[] = { "Ace", "Duece", "Three", "Four", "Five", "Six",
				"Seven", "Eight", "Nine", "Ten", "Jack", "Queen", "King" };


	const char *suit[] = { "Hearts", "Diamonds", "Clubs", "Spades" };

	srand(time(NULL));

	fillDeck(deck, face, suit); //   fill the deck with cards

	printf_s("    ============        Original Deal       ==================    \n");
	deal(deck);//                    deal out all 52 cards
	printf_s("\n");
	printf_s("    ==========================================================    \n");

	shuffle(deck);//                 put the cards in a random order
	printf_s("\n");
	printf_s("    ============        Shuffled Deal       ==================    \n");
	
	deal(deck);//                    deal out all 52 cards
	 
	system("Pause");
	return 0;
}

void fillDeck(Card * const wDeck, const char * wFace[], const char * wSuit[]) {
	// loop thru the deck 
	for (size_t i = 0; i < CARDS; i++) {

		wDeck[i].face = wFace[i % FACES];
		wDeck[i].suit = wSuit[i / FACES];
	}
}

void shuffle(Card * const wDeck) {
	// loop thru the deck and randomly swap cards
	for (size_t i = 0; i < CARDS; i++) {
		size_t j = rand() % CARDS;
		Card temp = wDeck[i];
		wDeck[i] = wDeck[j];
		wDeck[j] = temp;
	}
}

void deal(const Card * const wDeck){
	// loop thru the deck
	for (size_t i = 0; i < CARDS; i++) {
		printf_s("%5s of %-8s%s", wDeck[i].face, wDeck[i].suit, (i + 1) % 4 ? " " : "\n");
	}
}


