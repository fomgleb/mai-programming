#pragma once

#include <memory>
#include <optional>
#include <string>
#include <iostream>
#include <deque>

using std::optional;
using std::nullopt;
using std::deque;
using std::pair;
using std::string;
using std::cout;
using std::endl;
using std::unique_ptr;

class BinaryTree {
    struct Node {
        optional<int> data = nullopt;
        Node* parent;
        unique_ptr<Node> left = nullptr;
        unique_ptr<Node> right = nullptr;
    };
    unique_ptr<Node> root = nullptr;

    Node* GetClosestNodeToDataValue(int data) const;
public:
    void InsertData(int data);
    void PrintTree() const;
};
