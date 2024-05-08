#pragma once

#ifndef HEADER_H
#define HEADER_H
#pragma warning(disable:4996)
#include <stdio.h>;
#include <string.h>
#include <stdlib.h>

typedef struct Node {
    int value;
    struct Node* child[2];
    struct Node* parent;
} Node;

void PrintOutTree(Node* tree);

Node* create(int value);

Node* insert(Node* tree, Node* node);


#endif