//WAP to impliment Binary search tree and all the operations of binary search tree
#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#define MAX 10

struct NODE{
	struct NODE *lc;
	char data;
	struct NODE *rc;
};

void insert(struct NODE **root,char data);
void del(struct NODE **root, char data);
void search(struct NODE **parent, struct NODE **x, char data, int *found);
void inOrderTraversal(struct NODE *root);
void preOrdertraversal(struct NODE *root);
void postOrderTraversal(struct NODE *root);

//Driver function
int main(void){
	struct NODE *root = NULL;
	char item[MAX] = {'E','D','C','B','K','F','A','H','N','J'};
	int i = 0;

	while(i < 10){
		insert(&root, item[i]);
		i++;
	}

	printf("\nBinary search tree before deletion:\n");
	printf("Inorder traversal:\n");
	inOrderTraversal(root);

	printf("\n\nPreorder traversal:\n");
	preOrdertraversal(root);
	
	printf("\n\nPostorder traversal:\n");
	postOrderTraversal(root);

	printf("\nDeleting 'H'\n");
	del(&root, 'H');
	printf("\n\nBinary search tree after deletion of 'H':\n");

	printf("Inorder traversal:\n");
	inOrderTraversal(root);
	printf("\n\n");

	return 0;
}

void insert(struct NODE **root, char data){
	printf("\nInserting..%c\n",data);
	if(*root == NULL){
		*root = (struct NODE *)malloc(sizeof(struct NODE));
		if(*root == NULL){
			printf("\nMemory not availabe for new node\n");
			return;
		}

		(*root)->data = data;
		(*root)->lc = NULL;
		(*root)->rc = NULL;
		return;
	}

	if(data >= (*root)->data)
		insert(&((*root)->rc), data);
	else
		insert(&((*root)->lc), data);

}

void inOrderTraversal(struct NODE *root){
	if(root == NULL){
		return;
	}

	inOrderTraversal(root->lc);
	printf("%c\t",root->data);
	inOrderTraversal(root->rc);
}

void preOrdertraversal(struct NODE *root){
	if(root == NULL)
		return;

	printf("%c\t",root->data);
	preOrdertraversal(root->lc);
	preOrdertraversal(root->rc);
}

void postOrderTraversal(struct NODE *root){
	if(root == NULL)
		return;

	postOrderTraversal(root->lc);
	postOrderTraversal(root->rc);
	printf("%c\t",root->data);
}

void search(struct NODE **parent, struct NODE **x, char data, int *found){
	if(*x == NULL){
		printf("\n%c Not found!\n",data);
		*found = 0;
		return;
	}

	if((*x)->data == data){
		*found = 1;
		printf("\n%c Found!\n",data);
		return;
	}
	else if(data > (*x)->data){
		*parent = *x;
		*x = ((*x)->rc);
		search(parent, x, data, found);
	}
	else{
		*parent = *x;
		*x = ((*x)->lc);
		search(parent, x, data, found);
	}

	return;
}

void del(struct NODE **root, char data){
	struct NODE *parent, *x, *xsucc;
	int found;

	if((*root) == NULL){
		printf("\nTree is empty!\n");
		return;
	}
	/*******Initializing*********/
	parent = NULL;
	x = *root;
	xsucc = NULL;
	found = 0;
	/***************************/

	printf("\n\nSearching %c...\n",data);
	search(&parent, &x, data, &found);

	if(found){
		/*******CASE (D)****************/
		if(x->lc != NULL && x->rc != NULL){
			xsucc = x->rc;

			while(xsucc->lc != NULL){
				parent = xsucc;
				xsucc = xsucc->lc;
			}

			x->data = xsucc->data; /* copying the data of xsucc into the node to be deleted*/
			x = xsucc;             /*Now makind the pointer x point to the xsucc and reducing problem to case A or case B*/
		}

		/****************CASE (A)********/
		if(x->lc == NULL && x->rc == NULL){
			free(x);
			printf("\n%c Deleted!\n",data);
			return;
		}

		/***************CASE (B)************/
		else if(x->lc != NULL && x->rc == NULL){
			if(x->data < parent->data)
				(parent->lc) = (x->lc); //making parent of x the parent of x->leftChild
			else
				(parent->rc) = (x->lc); //making parent of x the parent of x->rightChild

			free(x);
			printf("\n%c Deleted!\n",data);
			return;
		}
		else if(x->lc == NULL && x->rc != NULL){
			if(x->data < parent->data)
				(parent->lc) = (x->rc); //making parent of x the parent of x->leftChild
			else
				(parent->rc) = (x->rc); //making parent of x the parent of x->rightChild

			free(x);
			printf("\n%c Deleted!\n",data);
			return;
		}
	}
}