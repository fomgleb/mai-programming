#include "question.hpp"

string Question::getText() const {
    return text;
}

void Question::setText(string text) {
    this->text = text;
}

void Question::addAnswer(string text) {
    answers.push_back(text);
}

vector<string> Question::getAnswers() const {
    return answers;
}

void Question::setCorrectAnswerIndex(size_t newIndex) {
    if (newIndex >= answers.size()) {
        throw std::out_of_range("Index '" + to_string(newIndex) + "' is out of range (0, " +
            to_string(answers.size()) + ")");
    }
    correctAnswerIndex = newIndex;
}

size_t Question::getCorrectAnswerIndex() const {
    return correctAnswerIndex;
}
