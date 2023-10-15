#pragma once

#include <memory>

class BinaryTree {
    struct Node {
        int data;
        std::unique_ptr<Node> left;
        std::unique_ptr<Node> right;
    } root;
};
