#include <string>
#include <vector>
#include <stdexcept>

using std::string;
using std::vector;
using std::iostream;
using std::to_string;

class Question {
    string text;
    vector<string> answers;
    size_t correctAnswerIndex;
public:
    string getText();
    void setText(string text);
    void addAnswer(string text);
    vector<string> getAnswers();
    void setCorrectAnswerIndex(size_t newIndex);
    size_t getCorrectAnswerIndex();
};
