#include "gift.hpp"

int main() {
    std::ofstream outputFile("output.txt", std::ios::out);
    Gift gift("input.gift");
    for (auto question : gift.getQuestions()) {
        outputFile << question->getText() << std::endl;
        vector<string> answers = question->getAnswers();
        for (size_t i = 0; i < answers.size(); i++) {
            outputFile << (i == question->getCorrectAnswerIndex() ? '+' : '-')
                << " " << answers[i] << std::endl;
        }
        outputFile << std::endl;
    }
    return 0;
}
