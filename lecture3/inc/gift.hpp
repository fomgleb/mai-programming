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

class Gift {
    vector<Question*> questions;
    
    optional<Question*> parseOneQuestion(ifstream& giftFile);
    void parseGiftFile(ifstream& giftFile);
public:
    Gift(string giftFilePath);
    ~Gift();
};
