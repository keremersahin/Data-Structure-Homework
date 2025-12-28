#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX 100

typedef struct {
    char items[MAX];
    int top;
} Stack;

void init(Stack *s) {
    s->top = -1;
}

int isEmpty(Stack *s) {
    return s->top == -1;
}

void push(Stack *s, char c) {
    if (s->top >= MAX - 1) return;
    s->items[++(s->top)] = c;
}

char pop(Stack *s) {
    if (isEmpty(s)) return '\0';
    return s->items[(s->top)--];
}

char peek(Stack *s) {
    if (isEmpty(s)) return '\0';
    return s->items[s->top];
}

int priority(char c) {
    if (c == '^') return 3;
    if (c == '*' || c == '/') return 2;
    if (c == '+' || c == '-') return 1;
    return 0;
}

int isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}

void infixToPostfix(char* infix, char* postfix) {
    Stack s;
    init(&s);
    int i = 0; 
    int k = 0; 
    
    while (infix[i] != '\0') {
        char token = infix[i];
        
        if (isalnum(token)) {
            postfix[k++] = token;
        }
        else if (token == '(') {
            push(&s, token);
        }
        else if (token == ')') {
            while (!isEmpty(&s) && peek(&s) != '(') {
                postfix[k++] = pop(&s);
            }
            pop(&s);
        }
        else if (isOperator(token)) {
            while (!isEmpty(&s) && priority(peek(&s)) >= priority(token)) {
                postfix[k++] = pop(&s);
            }
            push(&s, token);
        }
        i++;
    }
    
    while (!isEmpty(&s)) {
        postfix[k++] = pop(&s);
    }
    
    postfix[k] = '\0';
}

int main() {
    char infix[MAX] = "A+B*C-D";
    char postfix[MAX];
    
    infixToPostfix(infix, postfix);
    printf("Infix: %s\n", infix);
    printf("Postfix: %s\n", postfix);

    return 0;
}