#include <iostream>

using namespace std;

struct Stacknode
{
	char data;
	struct Stacknode *next;
};

struct Stacknode *newNode(char data)
{
	struct Stacknode *stacknode=(struct Stacknode *)malloc(sizeof(struct Stacknode));
	stacknode->data=data;
	stacknode->next=NULL;
	return stacknode;
}

int isEmpty(struct Stacknode *root)
{
	return !root;
}

int peek(struct Stacknode *root)
{
	return root->data;
} 

int pop(struct Stacknode **root)
{
	
	struct Stacknode* temp=*root;
	*root=(*root)->next;
	char popped=temp->data;
	free(temp);
	return popped;
}

void push(struct Stacknode **root,char data)
{
	struct Stacknode* stacknode=newNode(data);
	stacknode->next=*root;
	*root=stacknode;	
}

int isOperand(char a)
{
	return (a>='0' && a<='9');
}

int precedence(int a)
{
	switch(a)
	{
	case '+':
	case '-': return 1;

	case '*':
	case '/': return 2;

	case '^': return 3;
	}
	return -1;
}

int infixToPostfix(char* exp)
{
	int i,k=0;

	for (int i = 0; i < strlen(exp); ++i)
	{
		if(isOperand(exp[i]))
	{
		exp[k++] = exp[i];
	}
	
	else if(exp[i]=='(')
	{
		push(&root,exp[i]);
	}

	



	char data;
	data=exp[i];
	struct Stacknode *stacknode=newNode(data);

		// You will have to check if the the data corresponding to 'i'th index of exp is operand or not. In case of operand
	}
}


int main(int argc, char const *argv[])
{
	struct Stacknode* root = NULL;	


	char exp[] = "1+2*3";

	infixToPostfix(exp);
	return 0;
	return 0;
}