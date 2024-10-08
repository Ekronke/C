#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct node {
	int data;
	struct node* next;
};
typedef struct node node_t;

void print_list(node_t* node) {
	printf("%d\n", node->data);
	if (node->next != NULL) {
		print_list(node->next);
	}
}

node_t* search(node_t* head, int target) {
    node_t* current = head;
    while (current != NULL) {
        if (current->data == target) {
            return current;  
        }
        current = current->next;
    }
    return NULL;  
}


int main() {
	node_t n1, n2, n3;
	node_t *head;

	n1.data = 1;
	n2.data = 2;
	n3.data = 3;
	
	head = &n3;
	n1.next = &n2;
	n2.next = &n3;
	n3.next = NULL;

	print_list(n1.next);

	return 0;
}	
