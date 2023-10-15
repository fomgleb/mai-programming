#pragma once

#include <memory>
#include <optional>

using std::optional;
using std::shared_ptr;
using std::nullopt;

class BinaryTree {
    struct Node {
        optional<int> data = nullopt;
        shared_ptr<Node> left = nullptr;
        shared_ptr<Node> right = nullptr;
    };
    shared_ptr<Node> root = nullptr;

    shared_ptr<Node> GetNodeByData(int data);
};
