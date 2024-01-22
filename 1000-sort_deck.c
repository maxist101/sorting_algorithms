#include "deck.h"

int _strcmp(const char *a, const char *b);
char obtain_num(deck_node_t *card);
void sort_card(deck_node_t **deck);
void sort_value(deck_node_t **deck);
void sort_deck(deck_node_t **deck);

/**
 * _strcmp - func compares two str
 * @a: First str
 * @b: Second str
 *
 * Return: 0
 */
int _strcmp(const char *a, const char *b)
{
	while (*a && *b && *a == *b)
	{
		a++;
		b++;
	}

	if (*a != *b)
		return (*a - *b);
	return (0);
}

/**
 * obtain_num - Func gets numerical val
 * @card: Ptr to a deck_node_t card
 *
 * Return: Value
 */
char obtain_num(deck_node_t *card)
{
	if (_strcmp(card->card->value, "Ace") == 0)
		return (0);
	if (_strcmp(card->card->value, "1") == 0)
		return (1);
	if (_strcmp(card->card->value, "2") == 0)
		return (2);
	if (_strcmp(card->card->value, "3") == 0)
		return (3);
	if (_strcmp(card->card->value, "4") == 0)
		return (4);
	if (_strcmp(card->card->value, "5") == 0)
		return (5);
	if (_strcmp(card->card->value, "6") == 0)
		return (6);
	if (_strcmp(card->card->value, "7") == 0)
		return (7);
	if (_strcmp(card->card->value, "8") == 0)
		return (8);
	if (_strcmp(card->card->value, "9") == 0)
		return (9);
	if (_strcmp(card->card->value, "10") == 0)
		return (10);
	if (_strcmp(card->card->value, "Jack") == 0)
		return (11);
	if (_strcmp(card->card->value, "Queen") == 0)
		return (12);
	return (13);
}

/**
 * sort_card - Func sort a deck of cards
 * @deck: Ptr to the head
 */
void sort_card(deck_node_t **deck)
{
	deck_node_t *u, *v, *w;

	for (u = (*deck)->next; u != NULL; u = w)
	{
		w = u->next;
		v = u->prev;
		while (v != NULL && v->card->kind > u->card->kind)
		{
			v->next = u->next;
			if (u->next != NULL)
				u->next->prev = v;
			u->prev = v->prev;
			u->next = v;
			if (v->prev != NULL)
				v->prev->next = u;
			else
				*deck = u;
			v->prev = u;
			v = u->prev;
		}
	}
}

/**
 * sort_value - Func sort a deck of cards
 * @deck: Ptr to the head
 */
void sort_value(deck_node_t **deck)
{
	deck_node_t *u, *v, *w;

	for (u = (*deck)->next; u != NULL; u = w)
	{
		w = u->next;
		v = u->prev;
		while (v != NULL &&
		       v->card->kind == u->card->kind &&
		       obtain_num(v) > obtain_num(u))
		{
			v->next = u->next;
			if (u->next != NULL)
				u->next->prev = v;
			u->prev = v->prev;
			u->next = v;
			if (v->prev != NULL)
				v->prev->next = u;
			else
				*deck = u;
			v->prev = u;
			v = u->prev;
		}
	}
}

/**
 * sort_deck - Func sort a deck of cards
 * @deck: Ptr to the head
 */
void sort_deck(deck_node_t **deck)
{
	if (deck == NULL || *deck == NULL || (*deck)->next == NULL)
		return;

	sort_card(deck);
	sort_value(deck);
}
