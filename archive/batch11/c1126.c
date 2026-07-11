#include <stdio.h>
#include <stdint.h>
enum Suit { CLUBS=0, DIAMONDS=1, HEARTS=2, SPADES=3 };
enum Rank { TWO=2,THREE,FOUR,FIVE,SIX,SEVEN,EIGHT,NINE,TEN,JACK,QUEEN,KING,ACE=14 };
struct Card {
    uint8_t suit;
    uint8_t rank;
};
int main(void) {
    struct Card c = {.suit=(uint8_t)HEARTS, .rank=(uint8_t)ACE};
    printf("c1126 card=%u,%u\n", (unsigned)c.suit, (unsigned)c.rank);
    return !(c.suit == (uint8_t)HEARTS && c.rank == (uint8_t)ACE);
}
