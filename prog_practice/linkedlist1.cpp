//Linked list example
#include<iostream>
using std::cin;
using std::cout;
using std::endl;

struct Node{
	int data;
	struct Node* next;
};

void Print(Node *head){
	if(NULL == head)
		;
	else{
		cout<< head->data << endl;
		Print(head->next);
	}
}

int main(){
	int count = 0;
	Node *nodeNext;
	Node *fnode;
	bool choice = true;
	while(choice){
		Node *node = new Node();
	        if(node == NULL){
                	cout << endl << "Memory full";
			choice = false;
			if(count != 0)
				nodeNext->next = NULL;
			else
				fnode = NULL;
       		}
		else{
			if(count == 0){
				fnode = node;
				count = 1;
			}
			else{
				nodeNext->next = node;
			}
			cout << "enter data\t";
			cin >> node->data;
			cout << "Want to enter more ?(y/n)\t";
			char ch;
			cin >> ch;
			if('y' == ch || 'Y' == ch){
				choice = true;
				nodeNext = node;
				node = NULL;
			}
			else{
				choice = false;
				node->next = NULL;
			}
		}
	}
	Print(fnode);
	return 0;
}
