#include "binary_tree.hpp"

int main() {
    BinaryTree binaryTree;

    binaryTree.InsertData(124);
    binaryTree.InsertData(1);
    binaryTree.InsertData(20);
    binaryTree.InsertData(39);
    binaryTree.InsertData(8);
    binaryTree.InsertData(9);
    binaryTree.InsertData(3);
    binaryTree.InsertData(-18);
    binaryTree.InsertData(299);
    binaryTree.InsertData(35);
    binaryTree.InsertData(143);
    binaryTree.InsertData(311);
    binaryTree.InsertData(2);


    binaryTree.printTree();

    return 0;
}
