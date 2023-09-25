#include <stdlib.h>
#include "deck.h"
/**
 * compare_cards - Compare two cards for sorting
 * @card1: Pointer to the first card
 * @card2: Pointer to the second card
 * Return: Negative value if card1 should come before card2,
 * Positive value if card1 should come after card2,
 * 0 if cards are equal.
 */

int compare_cards(const void *card1, const void *card2)
{

	const card_t *c1 = *((const card_t **)card1);
	const card_t *c2 = *((const card_t **)card2);
	int value_cmp = strcmp(c1->value, c2->value);

	if (value_cmp != 0)
		return (value_cmp);
	return (c1->kind - c2->kind);
}

/**
 * sort_deck - Sorts a deck of cards
 * @deck: Pointer to a pointer to the head of the deck
 */

void sort_deck(deck_node_t **deck)
{

	size_t deck_size = 0;
	deck_node_t *current = *deck;
	card_t *cards[52];
	size_t i;

	while (current != NULL)
	{
		cards[deck_size] = (card_t *)(current->card);
		current = current->next;
		deck_size++;
	}
	qsort(cards, deck_size, sizeof(card_t *), compare_cards);
	current = *deck;
	for (i = 0; i < deck_size; i++)
	{
		current->card = cards[i];
		current = current->next;
	}
}
