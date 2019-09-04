#include <stdio.h>

typedef struct linked_list
{
	int x;
	struct linked_list *next;
} node;

/* creates a new node */
node* create_node(int val){
	node *temp;
	temp = (node*)malloc(sizeof(node));
	temp->x = val;
	temp->next = NULL;
	return temp;
}

/* prints out the value of each element */
void print_list(node* n){
	while (n != NULL){
		printf("%d \n", n->x);
		n = n->next;
	}
}

/* inserts a new element after some existing element */
void insert_node(node *element, int val){
	element->next = (node*)malloc(sizeof(node));
	element->next->x = val;
	element->next->next = NULL;
}

/* deletes a certain element */
void delete_node(node **head, int val){
	node *temp = *head;
	node *prev;

	if (temp != NULL && temp->x == val)
	{
		*head = temp->next;
		free(temp);
		return;
	}

	while(temp != NULL && temp->x != val)
	{
		prev = temp;
		temp = temp->next;  
	}

	if (temp == NULL)
	{
		return;
	}

	prev->next = temp->next;

	free(temp);
}

int main()
{
	/* code */
	return 0;
}