#include <stdio.h>
#include <stdlib.h>
typedef struct node{
        int value;
        struct node * left;
        struct node * right;
} Node;

typedef struct qnode{
	Node * value;
	struct qnode * next;
} QNode;

int empty = 1;
QNode* q;// = calloc(1, sizeof(QNode));

void enqueue(QNode* front, Node * val){
	if(empty){
		front->value = val;
		empty = 0;
		return;
	}
	empty = 0;
	QNode * temp = calloc(1, sizeof(QNode));
	temp->value = val;
	QNode * p = front;
	while(p->next){
		p = p->next;
	}

	p->next = temp;
	q = front;
}

Node * dequeue(QNode * front){
	if(empty)
		return NULL;
	if(front->next == NULL){
		empty = 1;
		Node * qq = front->value;
	//	free(front);
//		printf("here");
		return qq;
	}
	QNode * temp = front;
	front = front->next;
	q = front;
	Node * t = temp->value;
	//free(temp);
	return t;
}

int isEmpty(QNode * front){
	if(empty)
		return 1;
	return 0;
}
	
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
        print_reverse(root->right);
        printf("%d\n", root->value);
	print_reverse(root->left);
}

int num_leaves(Node * root){
	if(root == NULL)
		return 0;
	q = malloc(sizeof(QNode));
	int leaves = 0;
	empty = 1;
	enqueue(q, root);
	while(!empty){
		Node * temp = dequeue(q);
		if(temp->right  != NULL){
			enqueue(q, temp->right);
//			printf("right tree added: %d\n", temp->right->value);
		}
		if(temp->left != NULL){
			enqueue(q, temp->left);
//			printf("left tree added: %d\n", temp->left->value);
		}
		if(temp->right == NULL && temp->left == NULL){
			leaves++;
//			printf("leaf found: %d\n", temp->value);
		}
		printf("%d\n", empty);
	}
	free(q);
	return leaves;
	
}
Node * new_node(int val){
	Node * temp = malloc(sizeof(Node));
	temp->value = val;
	temp->left = temp->right = NULL;
	return temp;
}

void free_all(Node * root){
	if(root == NULL)
                return;
        free_all(root->right);
        free_all(root->left);
	free(root);
}	

int main(){
	Node* root1 = new_node(5);
	root1->left = new_node(4);
	root1->right = new_node(7);
	root1->right->right = new_node(9);
	root1->right->left = new_node(6);
	printf("SORTED: \n");
	print_sorted(root1);
	printf("REVERSE: \n");
	print_reverse(root1); 
	printf("NUMBER OF LEAVES: %d\n", num_leaves(root1));		
	free_all(root1);
	return 0;
}
