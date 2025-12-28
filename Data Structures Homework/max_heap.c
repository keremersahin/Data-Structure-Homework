#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct {
    int array[MAX_SIZE];
    int size;
} MaxHeap;

void init(MaxHeap *h) {
    h->size = 0;
}

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void insert(MaxHeap *h, int veri) {
    if (h->size >= MAX_SIZE) return;
    
    int i = h->size;
    h->array[i] = veri;
    h->size++;
    
    while (i != 0 && h->array[(i - 1) / 2] < h->array[i]) {
        swap(&h->array[i], &h->array[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

int extractMax(MaxHeap *h) {
    if (h->size <= 0) return -1;
    if (h->size == 1) {
        h->size--;
        return h->array[0];
    }
    
    int root = h->array[0];
    h->array[0] = h->array[h->size - 1];
    h->size--;
    
    int i = 0;
    while (1) {
        int sol = 2 * i + 1;
        int sag = 2 * i + 2;
        int enBuyuk = i;
        
        if (sol < h->size && h->array[sol] > h->array[enBuyuk])
            enBuyuk = sol;
            
        if (sag < h->size && h->array[sag] > h->array[enBuyuk])
            enBuyuk = sag;
            
        if (enBuyuk == i) break;
        
        swap(&h->array[i], &h->array[enBuyuk]);
        i = enBuyuk;
    }
    
    return root;
}

void printHeap(MaxHeap *h) {
    for (int i = 0; i < h->size; i++) {
        printf("%d ", h->array[i]);
    }
    printf("\n");
}

int main() {
    MaxHeap h;
    init(&h);
    
    insert(&h, 3);
    insert(&h, 10);
    insert(&h, 12);
    insert(&h, 8);
    insert(&h, 2);
    insert(&h, 14); 
    
    printHeap(&h);
    
    printf("%d\n", extractMax(&h));
    printHeap(&h);
    
    return 0;
}