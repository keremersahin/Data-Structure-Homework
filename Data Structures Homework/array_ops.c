#include <stdio.h>

#define KAPASITE 100

typedef struct {
    int data[KAPASITE];
    int size;
} ArrayList;

void init(ArrayList *list) {
    list->size = 0;
}

void insert(ArrayList *list, int index, int veri) {
    if (list->size >= KAPASITE || index < 0 || index > list->size) return;

    for (int i = list->size; i > index; i--) {
        list->data[i] = list->data[i - 1];
    }

    list->data[index] = veri;
    list->size++;
}

void deleteElement(ArrayList *list, int index) {
    if (index < 0 || index >= list->size) return;

    for (int i = index; i < list->size - 1; i++) {
        list->data[i] = list->data[i + 1];
    }

    list->size--;
}

void printArray(ArrayList *list) {
    for (int i = 0; i < list->size; i++) {
        printf("%d ", list->data[i]);
    }
    printf("\n");
}

int main() {
    ArrayList list;
    init(&list);

    insert(&list, 0, 10);
    insert(&list, 1, 20);
    insert(&list, 1, 15);
    printArray(&list);

    deleteElement(&list, 1);
    printArray(&list);

    return 0;
}