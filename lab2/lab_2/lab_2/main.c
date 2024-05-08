#include "Header.h";

int main() {
    Node* tree = create(4);
    Node* node1 = create(3);
    Node* node2 = create(2);
    Node* node3 = create(1);
    PrintOutTree(tree);
    printf("\n");

    tree = insert(tree, node1);
    tree = insert(tree, node2);
    tree = insert(tree, node3);
    PrintOutTree(tree);
    return 0;
}
