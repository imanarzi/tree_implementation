#include <stdio.h>
#include <stdlib.h>

int stack[100];
int top = -1;

int isEmpty(){
	return !(top + 1);
}

typedef struct node{
	int value;
	struct node * left;
	struct node * right;
} Node;


void print_sorted(Node * root){
	if(root == NULL)
		return;
	print_sorted(root->left);
	printf("%d\n", root->value);
	print_sorted(root->right);
}

void print_reverse(Node * root){
        if(root == NULL)
                return;
        print_sorted(root->right);
        printf("%d\n", root->value);
	print_sorted(root->left);
        //print_sorted(root->right);
	//printf("%d\n", root->value);
}

Node * new_node(int val){
	Node * temp = malloc(sizeof(Node));
	temp->value = val;
	temp->left = temp->right = NULL;
	return temp;
}

int main(){
	Node* root1 = new_node(5);
	root1->left = new_node(4);
	root1->right = new_node(7);
	root1->right->right = new_node(9);
	//print_sorted(root1);
	print_reverse(root1); 
}
