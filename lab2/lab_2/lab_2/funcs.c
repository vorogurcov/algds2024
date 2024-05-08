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

int side(Node* node) {
    return (node->parent->child[1] == node);
}

void attach(Node* node, int side, Node* new_node) {
    if (new_node) {
        new_node->parent = node;
    }
    node->child[side] = new_node;
}

void rotate(Node* node) {
    Node* p = node->parent;
    int i = side(node);
    if (p->parent) {
        attach(p->parent, side(p), node);
    }
    else {
        node->parent = NULL;
    }
    attach(p, i, node->child[!i]);
    attach(node, !i, p);
}

void splay(Node* node) {
    while (node->parent) {
        if (node->parent && node->parent->parent) {
            if (side(node) == side(node->parent)) {
                rotate(node->parent);
            }
            else {
                rotate(node);
            }
        }
        rotate(node);
    }
}

Node* insert(Node* tree, Node* node) {
    if (!tree) {
        tree = node;
        return tree;
    }
    Node* y = tree;
    while (1) {
        Node** nw = &y->child[node->value > y->value];
        if (!*nw) {
            *nw = node;
            (*nw)->parent = y;
            tree = *nw;
            splay(*nw);
            return tree;
        }
        y = *nw;
    }
    return tree;
}

