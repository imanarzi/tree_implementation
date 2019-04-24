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
//		free(front);
//		printf("here");
		return qq;
	}
	QNode * temp = front;
	front = front->next;
	q = front;
	Node * t = temp->value;
	free(temp);
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
		if(temp->right != NULL){
			enqueue(q, temp->right);
		}
		if(temp->left != NULL){
			enqueue(q, temp->left);
		}
		if(temp->right == NULL && temp->left == NULL){
			leaves++;
		}
	}
	free(q);
	return leaves;
	
}

int num_full_nodes(Node * root){
        if(root == NULL)
                return 0;
        q = malloc(sizeof(QNode));
        int full_nodes = 0;
        empty = 1;
        enqueue(q, root);
        while(!empty){
                Node * temp = dequeue(q);
                if(temp->right  != NULL){
                        enqueue(q, temp->right);
                }
                if(temp->left != NULL){
                        enqueue(q, temp->left);
                }
                if(temp->right != NULL && temp->left != NULL){
                        full_nodes++;
                }
        }
        free(q);
        return full_nodes;

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
	printf("NUMBER OF FULL NODES: %d\n", num_full_nodes(root1));
	free_all(root1);

	Node* root2 = new_node(12);
        root2->right = new_node(127);
        root2->right->left = new_node(31);
        root2->right->right = new_node(130);
        printf("SORTED: \n");
        print_sorted(root2);
        printf("REVERSE: \n");
        print_reverse(root2);
        printf("NUMBER OF LEAVES: %d\n", num_leaves(root2));
        printf("NUMBER OF FULL NODES: %d\n", num_full_nodes(root2));
        free_all(root2);
	
	Node* root3 = new_node(27);
        root3->left = new_node(12);
        root3->left->left = new_node(11);
        root3->left->left->left = new_node(7);
        printf("SORTED: \n");
        print_sorted(root3);
        printf("REVERSE: \n");
        print_reverse(root3);
	printf("NUMBER OF LEAVES: %d\n", num_leaves(root3));
        printf("NUMBER OF FULL NODES: %d\n", num_full_nodes(root3));
        free_all(root3);
	
	return 0;
}
