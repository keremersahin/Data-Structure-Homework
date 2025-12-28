#include <stdio.h>

#define MAX_TREE 15

char tree[MAX_TREE];

void initTree() {
    for(int i=0; i<MAX_TREE; i++) {
        tree[i] = '\0';
    }
}

void setRoot(char key) {
    if (tree[0] == '\0') tree[0] = key;
}

void setLeft(char key, int parentIndex) {
    int myIndex = (parentIndex * 2) + 1;
    if (tree[parentIndex] != '\0') tree[myIndex] = key;
}

void setRight(char key, int parentIndex) {
    int myIndex = (parentIndex * 2) + 2;
    if (tree[parentIndex] != '\0') tree[myIndex] = key;
}

void printTree() {
    for (int i = 0; i < MAX_TREE; i++) {
        if (tree[i] != '\0')
            printf("%c ", tree[i]);
        else
            printf("- ");
    }
    printf("\n");
}

int main() {
    initTree();

    setRoot('A');
    setLeft('B', 0);
    setRight('C', 0);
    
    setLeft('D', 1);
    setRight('E', 1);
    
    setRight('F', 2);

    printTree();

    return 0;
}