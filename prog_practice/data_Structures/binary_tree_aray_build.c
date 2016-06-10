//WAP to build an binary tree using array
//Using concept left child at (2n+1) position
//And right child at (2n+2) position
#include<stdio.h>
#include<stdlib.h>
#define MAX 10

struct NODE{
	char data;
	struct NODE *l;
	struct NODE *r;
};

char d[MAX] = {'A','B','C','D','K','F','\0','H','I','J'};

struct NODE *buildtree(int index);
void inorderTraversal(struct NODE *s);
void preorderTraversal(struct NODE *s);
void postorderTraversal(struct NODE *s);

//Driver function
int main(void){
	struct NODE *root;

	root = buildtree(0);
	printf("\nTree built\n\nInorder traversal: ");
	inorderTraversal(root);
	printf("\n\nPre Order traversal: ");
	preorderTraversal(root);
	printf("\n\nPost Order traversal: ");
	postorderTraversal(root);
	printf("\n");

	return 0;
}

struct NODE *buildtree(int index){
	struct NODE *temp;

	if(d[index] == '\0')
		return NULL;

	temp = (struct NODE *)malloc(sizeof(struct NODE));
	temp->data = d[index];
	temp->l = buildtree(2*index + 1);
	temp->r = buildtree(2*index + 2);

	return temp;
}

void inorderTraversal(struct NODE *s){

	if(s == NULL)
	return;

	inorderTraversal(s->l);
	printf("%c\t",s->data);
	inorderTraversal(s->r);
}

void postorderTraversal(struct NODE *s){

	if(s == NULL)
	return;

	postorderTraversal(s->l);
	postorderTraversal(s->r);
	printf("%c\t",s->data);
}

void preorderTraversal(struct NODE *s){

	if(s == NULL)
	return;

	printf("%c\t",s->data);
	preorderTraversal(s->l);
	preorderTraversal(s->r);
}