#include <iostream>

using namespace std;


struct node
{
    int data;
    struct node *next;
};
 

void push(struct node **head_ref, int data)
{
    struct node *ptr1 = (struct node *)malloc(sizeof(struct node));
    struct node *temp = *head_ref;
    ptr1->data = data;
    ptr1->next = *head_ref;
 
    
    if (*head_ref != NULL)
    {
        while (temp->next != *head_ref)
            temp = temp->next;
        temp->next = ptr1;
    }
    else
        ptr1->next = ptr1; 
 
    *head_ref = ptr1;
}
 

void printList(struct node *head)
{
    struct node *temp = head;
    if (head != NULL)
    {
        do
        {
            cout <<  temp->data<< "\n";
            temp = temp->next;
        }
        while (temp != head);
    }
}
 

int main()
{
    
    struct node *head = NULL;
 
    
    push(&head, 12);
    printList(head);
    cout << "\n";

    push(&head, 56);
    printList(head);

	cout << "\n";
    push(&head, 2);
    printList(head);
    cout << "\n";
    push(&head, 11);
 
    
    printList(head);
 
    return 0;
}
