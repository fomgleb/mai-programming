#pragma once

#include "question.hpp"
#include "string_trimmer.hpp"
#include <fstream>
#include <sstream>
#include <optional>

using std::ifstream;
using std::stringstream;
using std::optional;
using std::nullopt;
using std::shared_ptr;

class Gift {
    vector<shared_ptr<Question>> questions;

    optional<shared_ptr<Question>> parseOneQuestion(ifstream& giftFile);
    void parseGiftFile(ifstream& giftFile);
public:
    Gift(string giftFilePath);
    ~Gift();
};
