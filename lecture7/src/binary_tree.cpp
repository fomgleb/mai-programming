#include "binary_tree.hpp"

shared_ptr<BinaryTree::Node> BinaryTree::GetNodeByData(int data) {
    shared_ptr<BinaryTree::Node> current_node = root;
    while (current_node != nullptr) {
        if (current_node->data == data) {
            return current_node;
        }
        current_node = current_node->data > data ? current_node->right : current_node->left;
    }

    return nullptr;
}
