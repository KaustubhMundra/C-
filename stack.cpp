#include <iostream>

using namespace std;

struct Stacknode
{
	int data;
	struct Stacknode* next;
};

struct Stacknode* NewNode(int data)
{
	struct Stacknode* stacknode = (struct Stacknode*)malloc(sizeof(struct Stacknode));
	stacknode->data=data;
	stacknode->next=NULL;
	return stacknode;
}

int isEmpty(struct Stacknode* root)
{
	return !root;
}

void push(struct Stacknode **root,int data)
{
	struct Stacknode* stacknode = NewNode(data);
	stacknode->next=*root;
	*root=stacknode;
	printf("%d pushed to stack\n", data);
}

int pop(struct Stacknode **root)
{
	if(isEmpty(*root))
	{
		return INT_MIN;
	}
	struct Stacknode* temp=*root;
	*root=(*root)->next;
	int popped=temp->data;
	free(temp);
	return popped;
}

int peek(struct Stacknode* root)
{
    if(isEmpty(root))
        return INT_MIN;
    return root->data;
}



int main(int argc, char const *argv[])
{
	struct Stacknode* root = NULL;
 
    push(&root, 10);
    push(&root, 20);
    push(&root, 30);

    printf("%d popped from stack\n", pop(&root));
 
    printf("Top element is %d\n", peek(root));
 
	return 0;
}