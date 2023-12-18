#include <random>
#include <string>
#include <unordered_set>
#include <vector>

using std::string;
using std::vector;
using std::unordered_set;

string generate_random_string(const int length, const string& allowed_chars) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, allowed_chars.length() - 1);
    string result;
    for (int i = 0; i < length; ++i) {
        result += allowed_chars[dis(gen)];
    }
    return result;
}

int generate_random_number(const int min, const int max) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(min, max);
    return dis(gen);
}

uint32_t jenkins_one_at_a_time_hash(const string& input) {
    uint32_t hash = 0;
    for (char c : input) {
        hash += static_cast<unsigned char>(c);
        hash += hash << 10;
        hash ^= hash >> 6;
    }
    hash += hash << 3;
    hash ^= hash >> 11;
    hash += hash << 15;
    return hash;
}

int main() {
    const string allowed_chars = "abcdefghijklmnopqrstuvwxyz0123456789";
    const size_t num_random_strings = 10000;
    const size_t num_random_strings_kit = 100;

    std::set<string> random_strings;
    random_strings.reserve(num_random_strings);
    while (random_strings.size() < num_random_strings) {
        random_strings.insert(generate_random_string(3, allowed_chars));
    }

    vector<string> special_random_strings;
    special_random_strings.reserve(num_random_strings_kit * allowed_chars.size());
    for (int i = 0; i < num_random_strings_kit; i++) {
        string random_string = generate_random_string(3, allowed_chars);
        int random_symbol_index = generate_random_number(0, 2);
        for (auto allowed_char : allowed_chars) {
            random_string[random_symbol_index] = allowed_char;
            special_random_strings.push_back(random_string);
        }
    }

    unordered_set<string> random_string_hashes;
    random_string_hashes.reserve(num_random_strings);

    return 0;
}
