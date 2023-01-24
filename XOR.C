#include <stdio.h>
#include <stdlib.h>
struct Node {
int data;
struct Node* npx; // XOR of next and previous node
};
// Helper function to get XOR of two nodes
struct Node* XOR(struct Node* a, struct Node* b) {
return (struct Node*) ((unsigned int) (a) ^ ( unsigned int) (b));
}
// Function to add a node to the XOR linked list
void insert(struct Node** head, int data) {
// Allocate memory for the new node
struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
new_node->data = data;
new_node->npx = XOR(*head, NULL);
// If the list is not empty, update the npx of the current head
if (*head != NULL) {
struct Node* next = XOR((*head)->npx, NULL);
(*head)->npx = XOR(new_node, next);
}
*head = new_node;
}
// Function to find a pair whose sum is equal to 'k'
void findPair(struct Node* head, int k) {
struct Node* left = head;
struct Node* right = head;
struct Node* prev = NULL;
int found = 0;
while (left != NULL && right != NULL) {
if (left->data + right->data == k) {
printf("Pair found: (%d, %d)\n", left->data, right->data);
found = 1;
break;
}
else if (left->data + right->data < k) {
prev = left;
left = XOR(prev, right->npx);
}
else {
prev = right;
right = XOR(prev, left->npx);
}
}
if (!found) printf("No pair found whose sum is equal to %d\n", k);
}
int main() {
int k = 5;
struct Node* head = NULL;
insert(&head, 1);
insert(&head, 3);
insert(&head, 4);
insert(&head, 6);
insert(&head, 8);
findPair(head, k);
return 0;
}
