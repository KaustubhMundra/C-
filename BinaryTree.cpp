#include <iostream>

using namespace std;

struct node
{
	int data;
	struct node *left;
	struct node* right;
};

struct node *newNode(int data)
{
	struct node *treeNode=(struct node*)malloc(sizeof(struct node));
	treeNode->data=data;
	treeNode->left=NULL;
	treeNode->right=NULL;
	return treeNode;
}

void printInorder(struct node* root)
{
	if (root==NULL)return;

	printInorder(root->left);
	cout << root->data;
	printInorder(root->right);
}

void printPreorder(struct node* root)
{
	if (root==NULL)return;
	cout << root->data;
	printPreorder(root->left);
	printPreorder(root->right);
}

void printPostorder(struct node* root)
{
	if (root==NULL)return;

	printPostorder(root->left);
	printPostorder(root->right);
	cout << root->data;
}







int main(int argc, char const *argv[])
{
	struct node *root=newNode(1);
	root->left=newNode(2);
	root->right=newNode(3);
	root->left->left=newNode(4);
	root->left->right=newNode(5);
	printInorder(root);
	cout << "\n";
	printPreorder(root);
	cout << "\n";
	printPostorder(root);


	return 0;
}