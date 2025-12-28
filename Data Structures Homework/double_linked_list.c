#include <stdio.h>
#include <stdlib.h>

typedef struct n {
    int data;
    struct n *next;
    struct n *prev;
} node;

node* createNode(int veri) {
    node* yeni = (node*)malloc(sizeof(node));
    yeni->data = veri;
    yeni->next = NULL;
    yeni->prev = NULL;
    return yeni;
}

void append(node** root, int veri) {
    node* yeni = createNode(veri);
    if (*root == NULL) {
        *root = yeni;
        return;
    }
    node* iter = *root;
    while (iter->next != NULL) {
        iter = iter->next;
    }
    iter->next = yeni;
    yeni->prev = iter;
}

void insertAfter(node* root, int aranan, int veri) {
    node* iter = root;
    while (iter != NULL && iter->data != aranan) {
        iter = iter->next;
    }
    if (iter == NULL) return;
    
    node* yeni = createNode(veri);
    yeni->next = iter->next;
    iter->next = yeni;
    yeni->prev = iter;
    
    if (yeni->next != NULL) {
        yeni->next->prev = yeni;
    }
}

void deleteNode(node** root, int silinecek) {
    node* iter = *root;
    while (iter != NULL && iter->data != silinecek) {
        iter = iter->next;
    }
    if (iter == NULL) return;
    
    if (iter == *root) {
        *root = iter->next;
        if (*root != NULL) {
            (*root)->prev = NULL;
        }
    } else {
        if (iter->prev != NULL) iter->prev->next = iter->next;
        if (iter->next != NULL) iter->next->prev = iter->prev;
    }
    free(iter);
}

void printList(node* root) {
    node* iter = root;
    while (iter != NULL) {
        printf("%d <-> ", iter->data);
        iter = iter->next;
    }
    printf("NULL\n");
}

int main() {
    node* root = NULL;
    append(&root, 10);
    append(&root, 20);
    append(&root, 30);
    printList(root);
    
    insertAfter(root, 20, 25);
    printList(root);
    
    deleteNode(&root, 10);
    printList(root);
    
    return 0;
}