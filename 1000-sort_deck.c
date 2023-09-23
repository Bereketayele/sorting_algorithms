#include <stdio.h>
#include <stdlib.h>
#include "deck.h"

/**
 * compare_cards - Comparator function for qsort to compare two cards
 * @card1: Pointer to the first card
 * @card2: Pointer to the second card
 *
 * Return: Negative value if card1 is less than card2,
 *         0 if card1 is equal to card2,
 *         Positive value if card1 is greater than card2
 */
int compare_cards(const void *card1, const void *card2)
{
    const card_t *c1 = *(const card_t **)card1;
    const card_t *c2 = *(const card_t **)card2;

    if (c1->kind != c2->kind)
        return (c1->kind - c2->kind);
    return (strcmp(c1->value, c2->value));
}

/**
 * sort_deck - Sorts a deck of cards in ascending order
 * @deck: Pointer to the head of the deck
 */
void sort_deck(deck_node_t **deck)
{
    size_t deck_size = 0;
    deck_node_t *node = *deck;
    card_t *cards[52];

    while (node != NULL)
    {
        cards[deck_size] = (card_t *)node->card;
        node = node->next;
        deck_size++;
    }

    qsort(cards, deck_size, sizeof(card_t *), compare_cards);

    for (size_t i = 0; i < deck_size; i++)
    {
        if (i == 0)
            cards[i]->kind = SPADE;
        else if (cards[i]->value != cards[i - 1]->value)
            cards[i]->kind = (kind_t)(cards[i - 1]->kind + 1);
        (*deck)->card = cards[i];
        (*deck) = (*deck)->next;
    }
}
