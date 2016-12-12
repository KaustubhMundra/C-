#include <iostream>

using namespace std;

struct node
{
	int data;
	struct node *next;
};

void printList(struct node *n)
{
	cout<< "\n";
	while(n!=NULL)
	{

		cout << n->data << " " ;
		n=n->next;
	}
}

void push(struct node **head,int data)
{
	struct node *new_node=(struct node*)malloc(sizeof(struct node));
	new_node->data=data;
	new_node->next=*head;
	*head=new_node;
	// cout << "done";
}

void insertAfter(struct node *prev,int data)
{
	if(prev==NULL)cout << "Prev. node can't be NULL";

	struct node *new_node=(struct node*)malloc(sizeof(struct node));
	new_node->data=data;
	new_node->next=prev->next;
	prev->next=new_node;
}

void append(struct node **head,int data)
{
	struct node *new_node=(struct node *)malloc(sizeof(struct node));

	struct node *last=*head;

	new_node->data=data;
	new_node->next=NULL;

	if(*head==NULL)
	{
		*head=new_node;
		return;
	}

	while(last->next!=NULL)
	{
		last=last->next;
	}

	last->next=new_node;
}

void deleteNodeByKey(struct node **head,int key)
{
	struct node *temp=*head,*prev;

	if(temp!=NULL && temp->data==key)
	{
		*head=temp->next;
		free(temp);
		return;
	}

	while(temp!=NULL && temp->data!=key)
	{
		prev=temp;
		temp=temp->next;
	}

	if(temp==NULL)return;

	prev->next=temp->next;

	free(temp);
}

void deleteNodeByposition(struct node **head, int position)
{
	struct node *temp=*head, *new_node;;

	if(head==NULL)
	{
		return;
	}

	if(position==0)
	{
		*head=temp->next;
		free(temp);
		return;
	}

	for(int i=0; temp!=NULL && i<position-1; i++)
    {
    	temp = temp->next;
    }

    if(temp==NULL || temp->next==NULL)
    {
    	return;
    }

    
    new_node=temp->next->next;
    free(temp->next);
    temp->next=new_node;
}


int get_length_iterative(struct node* head)
{
    int count = 0;  
    struct node* current = head;
    while (current != NULL)
    {
        count++;
        current = current->next;
    }
    cout << "\n"<<count;
    return count;
}

int get_length_recursive(struct node *head)
{
	
	if(head==NULL)
	{
		return 0;
	}

	return 1 + get_length_recursive(head->next);
}

void swapNodes(struct node **head_ref, int x, int y)
{
   
   if (x == y) return;
 
   struct node *prev_x = NULL, *curr_x = *head_ref;
   while (curr_x && curr_x->data != x)
   {
       prev_x = curr_x;
       curr_x = curr_x->next;
   }
 
   struct node *prev_y = NULL, *curr_y = *head_ref;
   while (curr_y && curr_y->data != y)
   {
       prev_y = curr_y;
       curr_y = curr_y->next;
   }
 
   if (curr_x == NULL || curr_y == NULL)
       return;
 
   if (prev_x != NULL)
       prev_x->next = curr_y;
   else 
       *head_ref = curr_y;  
 
   
   if (prev_y != NULL)
       prev_y->next = curr_x;
   else  
       *head_ref = curr_x;
 
   struct node *temp = curr_y->next;
   curr_y->next = curr_x->next;
   curr_x->next  = temp;
}


void reverse(struct node** head_ref)
{
    struct node* prev   = NULL;
    struct node* current = *head_ref;
    struct node* next;
    while (current != NULL)
    {
        next  = current->next;  
        current->next = prev;   
        prev = current;
        current = next;
    }
    *head_ref = prev;
}
 


int main(int argc, char const *argv[])
{
	struct node *head=NULL;
	struct node *second=NULL;
	struct node *third=NULL;

	head=(struct node *)malloc(sizeof(struct node));
	second=(struct node *)malloc(sizeof(struct node));
	third=(struct node *)malloc(sizeof(struct node));

	head->data=1;
	head->next=second;


	second->data=2;
	second->next=third;

	third->data=3;
	third->next=NULL;

	printList(head);
	push(&head,0);
	printList(head);
	insertAfter(head->next,5);
	printList(head);
	append(&head,9);
	printList(head);
	deleteNodeByKey(&head,5);
	printList(head);
	deleteNodeByposition(&head,2);
	printList(head);
	get_length_iterative(head);
	{	
	int l=get_length_recursive(head);
	cout << "\n" << l;
	}
	swapNodes(&head,1,3);
	printList(head);
	reverse(&head);
	printList(head);

	return 0;
	

}