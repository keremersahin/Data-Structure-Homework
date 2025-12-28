#include <stdio.h>
#include <stdlib.h>

typedef struct n {
    int data;
    struct n *next;
} node;

void append(node** root, int veri) {
    node* yeni = (node*)malloc(sizeof(node));
    yeni->data = veri;
    
    if (*root == NULL) {
        *root = yeni;
        yeni->next = *root;
        return;
    }
    
    node* iter = *root;
    while (iter->next != *root) {
        iter = iter->next;
    }
    
    iter->next = yeni;
    yeni->next = *root;
}

void printList(node* root) {
    if (root == NULL) return;
    node* iter = root;
    do {
        printf("%d -> ", iter->data);
        iter = iter->next;
    } while (iter != root);
    printf("\n");
}

void deleteNode(node** root, int silinecek) {
    if (*root == NULL) return;
    
    if ((*root)->data == silinecek && (*root)->next == *root) {
        free(*root);
        *root = NULL;
        return;
    }
    
    node* iter = *root;
    node* prev = NULL;
    
    while (iter->data != silinecek) {
        if (iter->next == *root) return;
        prev = iter;
        iter = iter->next;
    }
    
    if (iter == *root) {
        node* last = *root;
        while (last->next != *root) {
            last = last->next;
        }
        *root = iter->next;
        last->next = *root;
        free(iter);
    } else {
        prev->next = iter->next;
        free(iter);
    }
}

int main() {
    node* root = NULL;
    append(&root, 10);
    append(&root, 20);
    append(&root, 30);
    
    printList(root);
    deleteNode(&root, 10);
    printList(root);
    
    return 0;
}