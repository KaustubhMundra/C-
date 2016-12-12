#include <iostream>

using namespace std;


struct node
{
	int data;
	struct node *next;
	struct node *prev;
};

void push(struct node** head_ref, int new_data)
{
    
    struct node* new_node = (struct node*) malloc(sizeof(struct node));
 
    
    new_node->data  = new_data;
 
    new_node->next = (*head_ref);
    new_node->prev = NULL;
 
    if((*head_ref) !=  NULL)
      (*head_ref)->prev = new_node ;
 
    (*head_ref)    = new_node;
}

void insertAfter(struct node* prev_node, int new_data)
{
    
    if (prev_node == NULL)
    {
        printf("the given previous node cannot be NULL");
        return;
    }
 
    struct node* new_node =(struct node*) malloc(sizeof(struct node));
 
    new_node->data  = new_data;
 
    new_node->next = prev_node->next;
 
    prev_node->next = new_node;
 
    new_node->prev = prev_node;
 
    if (new_node->next != NULL)
      new_node->next->prev = new_node;
}

void append(struct node** head_ref, int new_data)
{
    struct node* new_node = (struct node*) malloc(sizeof(struct node));
 
    struct node *last = *head_ref;  /* used in step 5*/
 
   	new_node->data  = new_data;
 
    new_node->next = NULL;
 
    if (*head_ref == NULL)
    {
        new_node->prev = NULL;
        *head_ref = new_node;
        return;
    }
 
    while (last->next != NULL)
        last = last->next;
 
    last->next = new_node;
 
    new_node->prev = last;
 
    return;
}

/* Function to delete a node in a Doubly Linked List.
   head_ref --> pointer to head node pointer.
   del  -->  pointer to node to be deleted. */
void deleteNode(struct node **head_ref, struct node *del)
{
  /* base case */
  if(*head_ref == NULL || del == NULL)
    return;
 
  /* If node to be deleted is head node */
  if(*head_ref == del)
    *head_ref = del->next;
 
  /* Change next only if node to be deleted is NOT the last node */
  if(del->next != NULL)
    del->next->prev = del->prev;
 
  /* Change prev only if node to be deleted is NOT the first node */
  if(del->prev != NULL)
    del->prev->next = del->next;     
 
  /* Finally, free the memory occupied by del*/
  free(del);
  return;
}     
 

void printList(struct node *node)
{
    struct node *last;
    printf("\nTraversal in forward direction \n");
    while (node != NULL)
    {
        printf(" %d ", node->data);
        last = node;
        node = node->next;
    }
 
    printf("\nTraversal in reverse direction \n");
    while (last != NULL)
    {
        printf(" %d ", last->data);
        last = last->prev;
    }
}
 

int main()
{
    struct node* head = NULL;
    append(&head, 6);
 
    push(&head, 7);
 
    push(&head, 1);
 
    append(&head, 4);

    insertAfter(head->next, 8);

    deleteNode(&head, head);
 
    printList(head);
 
    
    return 0;
}