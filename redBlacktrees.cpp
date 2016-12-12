#include <iostream>
#include <cstdlib>

using namespace std;

// enum nodeColor
// {
// 	red,
// 	black
// };

struct rbNode
{
	int data;
	char color;
	struct rbNode *left,*right,*parent;
};

struct rbNode *root=NULL;
struct rbNode *newNode(int data)
{
	struct rbNode *newnode=(struct rbNode*)malloc(sizeof(struct rbNode));
	newnode->data=data;
	newnode->color='r';
	newnode->left=newnode->right=newnode->parent=NULL;
	return newnode;
}

void swapColor(struct rbNode *a,struct rbNode *b)
{
	struct rbNode temp=*a;
	*a=*b;
	*b=temp;
}


void leftRotate(struct rbNode *root,struct rbNode* x)
{
	struct rbNode *y;
	y=x->right;
	x->right=y->left;
	if(y->left!=NULL)
	{
		y->left->parent=x;
	}
	y->parent=x->parent;

	if(x->parent==NULL)
	{
		root=y;
	}
	if(x->parent->left->data==x->data)x->parent->left=y;
	else x->parent->right=y;
	y->left=x;
	x->parent=y;
}

void rightRotate(struct rbNode *root,struct rbNode* x)
{
	struct rbNode *y;
	y = x->left; 
	x->left = y->right; 
	if ( y->right != NULL){
	    y->right->parent = x;
	}
	y->parent = x->parent;
	if( x->parent == NULL){
	    root = y;
	} 
	else if( x->data == x->parent->left->data){
	    x->parent->left = y;
	}
	else x->parent->right = y;
	y->right = x; 
	x->parent = y; 

	return;

}

void rbInsertFix(struct rbNode *root,struct rbNode *newnode)
{
	//cout << '0';
	struct rbNode *uncle=NULL;
	if(newnode->parent==NULL)
	{
		//cout<<"in";
		root->color='b';
		return;
	}
	while((newnode!=root) && (newnode->color!='b') && (newnode->parent->color=='r'))
	{
		//cout << "1";
		if(newnode->parent->parent->left==NULL || newnode->parent->parent->right==NULL)
		{
			newnode->color='b';
			return;
		}
		if(newnode->parent->data==newnode->parent->parent->left->data) 
		{
			//cout << "2";
			uncle=newnode->parent->parent->right;
			if(uncle->color=='r')
			{
				newnode->parent->color='b';
				uncle->color='b';
				newnode->parent->parent->color='r';
				newnode=newnode->parent->parent;
			}
			else
			{
				if(newnode==newnode->parent->right)
				{
					newnode=newnode->parent;
					leftRotate(root,newnode);
				}
				newnode->parent->color='b';
				newnode->parent->parent->color='r';
				rightRotate(root,newnode->parent->parent);

			}

		}

		else if(newnode->parent->data==newnode->parent->parent->right->data) 
		{
			uncle=newnode->parent->parent->left;
			//cout << "3";
			
			if( uncle->color=='r')
			{
				newnode->parent->color='b';
				uncle->color='b';
				newnode->parent->parent->color='r';
				newnode=newnode->parent->parent;
			}
			else
			{
				if(newnode==newnode->parent->left)
				{
					newnode=newnode->parent;
					rightRotate(root,newnode);
				}
				newnode->parent->color='b';
				newnode->parent->parent->color='r';
				leftRotate(root,newnode->parent->parent);

			}

		}

	}
	root->color='b';
}

void rbDelete(struct node* root, int key)
{
    // base case
    if (root == NULL) return root;
 
    // If the key to be deleted is smaller than the root's key,
    // then it lies in left subtree
    if (key < root->key)
        root->left = deleteNode(root->left, key);
 
    // If the key to be deleted is greater than the root's key,
    // then it lies in right subtree
    else if (key > root->key)
        root->right = deleteNode(root->right, key);
 
    // if key is same as root's key, then This is the node
    // to be deleted
    else
    {
        // node with only one child or no child
        if (root->left == NULL)
        {
            struct node *temp = root->right;
            free(root);
            return
        }
        else if (root->right == NULL)
        {
            struct node *temp = root->left;
            free(root);
            return;
        }
 
        // node with two children: Get the inorder successor (smallest
        // in the right subtree)
        struct node* temp = minValueNode(root->right);
 
        // Copy the inorder successor's content to this node
        root->key = temp->key;
 
        // Delete the inorder successor
        root->right = deleteNode(root->right, temp->key);
    }

    rbDeleteFix(root,)
    
}





void rbInsert(struct rbNode **root,int data){
	//cout<<"i m here";
	struct rbNode *z = newNode(data);
	z->color = 'r';
	struct rbNode *x = *root;
	struct rbNode *y=NULL;
	//cout<< "-2";
	// if ( root == NULL ){
	//     *root = z;
	//     (*root)->color = 'b';
	//     return;
	// }
	while ( x != NULL){
	    y = x;
	    if ( z->data < x->data)
	    {
	        x = x->left;
	    }
	    else x = x->right;
	}
	z->parent = y;
	if ( y == NULL){
	    *root = z;
	}
	else if( z->data < y->data ){
	    y->left = z;
	}
	else y->right = z;
	//cout << "-1";
	rbInsertFix(*root,z);


	return;
}

void inOrderTraversal(struct rbNode* root)
{
	if(root==NULL)
		return;
	inOrderTraversal(root->left);
	cout << root->data << root->color;
	inOrderTraversal(root->right);
}

int main(int argc, char const *argv[])
{
	
	int random=0;
	int loop = 1;
	while(loop)
	{
	    printf("\nRed Black Tree Management - Enter your choice : ");
	    printf("\n1\tInsert into RBT\n2\tDisplay RBT inorder\n");
	    int choice;
	    int data;
	    scanf("%d",&choice);
	    switch(choice){
	        case 1:
	        printf("\nEnter the integer you want to add : ");
	        scanf("%d",&data);
	        rbInsert(&root,data);
	        break;

	        case 2:
	        printf("\nInorder tree traversal left-root-right\n");
	        inOrderTraversal(root);
	        break;

	        default:
	        printf("\nInvalid Choice\n");
	    }
	    printf("\nPress '0' to terminate and '1' to continue : ");
	    scanf("%d",&loop);
	}		
	return 0;
}