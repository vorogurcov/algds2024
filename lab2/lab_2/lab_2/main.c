#include "Header.h";

int main() {
    Node* tree = create(4);
    Node* node1 = create(3);
    PrintOutTree(tree);
    printf("\n");
    PrintOutTree(node1);
    return 0;
}
