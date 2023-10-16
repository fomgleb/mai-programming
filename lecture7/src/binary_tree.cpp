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
    if (closest_node_to_data != nullptr && closest_node_to_data->data == data) return;

    shared_ptr<BinaryTree::Node> new_node = make_shared<BinaryTree::Node>();
    new_node->data = data;
    new_node->parent = closest_node_to_data;
    if (new_node->parent != nullptr) {
        if (data > new_node->parent->data) {
            new_node->parent->right = new_node;
        } else {
            new_node->parent->left = new_node;
        }
    }

    if (root == nullptr) {
        root = new_node;
    }
}

void BinaryTree::printTree() const {
    if (!root) return;

    deque<pair<const Node*, string>> nodes;
    nodes.push_back({root.get(), ""});

    while (!nodes.empty()) {
        auto [node, prefix] = nodes.front();
        nodes.pop_front();

        cout << prefix << (node->parent && node->parent->right.get() == node ? "right: " : "left: ");

        if(node->data.has_value()) {
            cout << node->data.value() << endl;
        } else {
            cout << "null" << endl;
        }

        prefix += (node->parent && node->parent->right.get() == node ? "    " : "|   ");

        if (node->right) {
            nodes.push_front({node->right.get(), prefix});
        }

        if (node->left) {
            nodes.push_front({node->left.get(), prefix});
        }
    }
}
