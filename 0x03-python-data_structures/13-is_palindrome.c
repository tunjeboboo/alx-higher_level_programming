#include "lists.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * _palindrome - checks for palindrome in a linked list
 * @head: pointer to head node
 * @temp: temporary pointer to travers list
 *
 * Return: pointer to head node if palindrome, NULL other wise
 */

listint_t *_palindrome(listint_t *head, listint_t *temp)
{
	listint_t *node;

	if (temp == NULL)
		return (head);
	node = _palindrome(head, temp->next);
	if (node != NULL && temp->n == node->n)
	{
		if (node->next == NULL)
			return (head);
		return (node->next);
	}
	return (NULL);
}

/**
 * is_palindrome - checks if a singly linked list is a palindrome.
 * @head: pointer to head node
 *
 * Return: 1 if palindrome 0 otherwise
 */

int is_palindrome(listint_t **head)
{
	listint_t *temp;

	if (!*head || (*head)->next == NULL)
		return (1);
	temp = *head;
	if (_palindrome(*head, temp))
		return (1);
	return (0);
}
