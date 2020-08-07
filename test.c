#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct node {
    node* next;
    node* prev;
    int val;
};

node* newNode(node* pr, int val) {
    struct node* new_node = (struct node*) malloc(sizeof(struct node)); 
    new_node->val  = val; 
    new_node->next = NULL;
    new_node->prev = pr;
    return new_node;
}

void push(node* pr, int val) {
    node* cur = newNode(pr, val);
    pr = cur;
}

void pop(node* cur, node* head, node* tail) {
    if (cur->next != NULL && cur-> prev != NULL) {
        cur->next->prev = cur->prev;
        cur->prev->next = cur->next;
    } else if (cur->prev != NULL) {
        if (tail == cur)
            tail = cur->prev;
        cur->prev->next = NULL;
    } else if (cur->next != NULL) {
        if (head == cur)
            head = cur->next;
        cur->next->prev = NULL;
    } else head = NULL;
    free(cur);
}

void traverse(node* root) {
    while (root != NULL) {
        printf("%d\n", root->val);
        root = root->next;
    }
}

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        node* arr; 
        node* head = arr;
        node* tail = arr;
        int n, k;
        scanf("%d %d", &n, &k);
        int i;
        for (i = 0; i < n; i++) {
            int a;
            scanf("%d", &a);
            if (head == NULL) {
                push(tail, a);
                head = tail;
            } else {
                push(tail, a);
            }
        }
        traverse(head);
    }
    return 0;
}