#pragma once

#include <memory>
#include <optional>
#include <string>
#include <iostream>
#include <deque>

using std::optional;
using std::shared_ptr;
using std::make_shared;
using std::nullopt;
using std::deque;
using std::pair;
using std::string;
using std::cout;
using std::endl;

class BinaryTree {
    struct Node {
        optional<int> data = nullopt;
        shared_ptr<Node> parent = nullptr;
        shared_ptr<Node> left = nullptr;
        shared_ptr<Node> right = nullptr;
    };
    shared_ptr<Node> root = nullptr;

    shared_ptr<Node> GetClosestNodeToDataValue(int data) const;
public:
    void InsertData(int data);
    void printTree() const;
};
