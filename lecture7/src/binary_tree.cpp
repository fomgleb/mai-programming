#include "binary_tree.hpp"

shared_ptr<BinaryTree::Node> BinaryTree::GetClosestNodeToDataValue(int data) const {
    shared_ptr<BinaryTree::Node> current_node = root;
    while (current_node != nullptr) {
        if (current_node->data == data) {
            return current_node;
        }

        shared_ptr<BinaryTree::Node> next_node = data > current_node->data
            ? current_node->right
            : current_node->left;

        if (next_node == nullptr) {
            return current_node;
        }

        current_node = next_node;
    }
    return current_node;
}

void BinaryTree::InsertData(int data) {
    shared_ptr<BinaryTree::Node> closest_node_to_data = GetClosestNodeToDataValue(data);
    if (closest_node_to_data->data == data) return;

    shared_ptr<BinaryTree::Node> new_node = make_shared<BinaryTree::Node>(data, closest_node_to_data);
    if (data > new_node->parent->data) {
        new_node->parent->right = new_node;
    } else {
        new_node->parent->left = new_node;
    }
}
