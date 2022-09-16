#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)

typedef struct ListNode {
    char data;
    struct ListNode* prev, * next;
}ListNode;

void init(ListNode* H, ListNode* T) {
    H->next = T;
    T->prev = H;
}

void add(ListNode* H, int r, char c) {
    ListNode* node = (ListNode*)malloc(sizeof(ListNode));
    ListNode* P = H;
    ListNode* Q = P;

    for (int i = 1; i <= r; i++) {
        Q = P;
        P = P->next;
        if (P == NULL) {
            printf("invalid position\n");
            return;
        }
    }
    node->data = c;
    node->prev = Q;
    node->next = P;
    Q->next = node;
    P->prev = node;

}

void delete(ListNode* H, ListNode* T, int r) {
    ListNode* P = H;
    for (int i = 1; i <= r; i++) {
        P = P->next;
        if (P == T) {
            printf("invalid position\n");
            return;
        }
    }
    P->next->prev = P->prev;
    P->prev->next = P->next;
    free(P);
}

void get(ListNode* H, ListNode* T, int r) {
    ListNode* P = H;
    for (int i = 1; i <= r; i++) {
        P = P->next;
        if (P == T) {
            printf("invalid position\n");
            return;
        }
    }
    printf("%c\n", P->data);
}

void print(ListNode* H, ListNode* T) {

    for (ListNode* P = H->next; P != T; P = P->next) {
        printf("%c", P->data);
    }
    printf("\n");
}

int main() {

    ListNode* H = (ListNode*)malloc(sizeof(ListNode));
    ListNode* T = (ListNode*)malloc(sizeof(ListNode));

    init(H, T);

    int N;
    scanf("%d", &N);
    getchar();

    for (int i = 0; i < N; i++) {
        char o;
        scanf("%c", &o);

        if (o == 'A') {
            int r;
            char e;
            scanf("%d %c", &r, &e);
            add(H, r, e);
        }
        else if (o == 'D') {
            int r;
            scanf("%d", &r);
            delete(H, T, r);
        }
        else if (o == 'G') {
            int r;
            scanf("%d", &r);
            get(H, T, r);
        }
        else if (o == 'P') {
            print(H, T);
        }
        getchar();
    }
    return 0;
}