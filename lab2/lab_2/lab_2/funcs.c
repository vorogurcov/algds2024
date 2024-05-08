#include "Header.h"

void PrintOutTree(Node* tree) {
    if (!tree) return;
    printf("%d (", tree->value);
    if (tree->child[0]) {
        PrintOutTree(tree->child[0]);
    }
    printf(") (");
    if (tree->child[1]) {
        PrintOutTree(tree->child[1]);
    }
    printf(")");
}

Node* create(int value) {
    Node* res = (Node*)malloc(sizeof(Node));
    res->parent = NULL;
    res->child[0] = NULL;
    res->child[1] = NULL;
    res->value = value;
    return res;
}


