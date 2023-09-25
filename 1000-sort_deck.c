#include <stdlib.h>
#include "deck.h"

int compare_cards(const void *a, const void *b)
{
    const card_t *card_a = (*(const deck_node_t **)a)->card;
    const card_t *card_b = (*(const deck_node_t **)b)->card;

    // Compare the kind first
    if (card_a->kind != card_b->kind)
        return card_a->kind - card_b->kind;

    // If the kind is the same, compare the value
    // Note: Assuming the card values are in the order "Ace" to "King"
    const char *values[] = {"Ace", "2", "3", "4", "5", "6", "7", "8", "9", "10", "Jack", "Queen", "King"};
    int value_a = 0;
    int value_b = 0;
    for (int i = 0; i < 13; i++) {
        if (card_a->value == values[i])
            value_a = i;
        if (card_b->value == values[i])
            value_b = i;
    }

    return value_a - value_b;
}

void sort_deck(deck_node_t **deck)
{
    // Count the number of cards
    int count = 0;
    deck_node_t *current = *deck;
    while (current) {
        count++;
        current = current->next;
    }

    // Create an array of deck_node_t pointers
    deck_node_t **deck_array = malloc(count * sizeof(deck_node_t *));
    if (!deck_array)
        return;

    // Copy the deck into the array
    current = *deck;
    for (int i = 0; i < count; i++) {
        deck_array[i] = current;
        current = current->next;
    }

    // Sort the array using qsort
    qsort(deck_array, count, sizeof(deck_node_t *), compare_cards);

    // Rearrange the linked list based on the sorted array
    *deck = deck_array[0];
    for (int i = 0; i < count - 1; i++) {
        deck_array[i]->next = deck_array[i + 1];
        deck_array[i + 1]->prev = deck_array[i];
    }
    deck_array[count - 1]->next = NULL;

    free(deck_array);
}
