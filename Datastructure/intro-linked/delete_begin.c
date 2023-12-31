#include <stdio.h>
#include <stdlib.h>

struct			Node
{
	int			data;
	struct Node	*next;
};

void	pop_begin(int pos, struct Node **head)
{
	struct Node	*temp;

	temp = *head;
	if (pos == 0)
	{
		*head = temp->next;
		free(temp);
		return ;
	}
}

void	array_to_linked_list(struct Node **head, int *arr, int size)
{
	int			i;
	struct Node	*current;

	if (size == 0)
	{
		*head = NULL;
		return ;
	}
	*head = (struct Node *)malloc(sizeof(struct Node));
	(*head)->data = arr[0];
	(*head)->next = NULL;
	i = 0;
	current = *head;
	for (i = 1; i < size; i++)
	{
		/* code */
		current->next = (struct Node *)malloc(sizeof(struct Node));
		current = current->next;
		current->data = arr[i];
		current->next = NULL;
	}
}

void	display(struct Node *node)
{
	// as linked list will end when Node is Null
	printf("Head ");
	while (node != NULL)
	{
		printf("-> [%d] ", node->data);
		node = node->next;
	}
	printf("\n");
}

int	main(void)
{
	struct Node	*head;
	int			arr[] = {1, 2, 3, 4, 5};
	int			size;

	size = sizeof(arr) / sizeof(arr[0]);
	array_to_linked_list(&head, arr, size);
	display(head);
	pop_begin(0, &head);
	display(head);
}
