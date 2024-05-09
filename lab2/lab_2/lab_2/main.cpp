#include "Header.h";


int main(int argc, char*argv[]) {
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

    if(find(tree, 1) == node3)
        printf("\nWORKS!");

    if (extremum(tree,0) == tree)
        printf("\nWORKS!");

    if (extremum(tree, 2) == node1)
        printf("\nDOES NOT WORK!");

    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
