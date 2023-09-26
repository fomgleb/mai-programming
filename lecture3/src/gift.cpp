#include "gift.hpp"

optional<Question*> Gift::parseOneQuestion(std::ifstream& giftFile) {
    Question* question = new Question;
    stringstream questionNameStream;
    stringstream answerNameStream;

    char symbol;
    bool symbolInQuestionName = true;
    bool symbolInAnswers = false;
    bool symbolInAnswerName = false;
    bool currentAnswerIsCorrect = false;
    while (giftFile.get(symbol)) {
        switch (symbol) {
        case '{':
            if (symbolInQuestionName) {
                symbolInQuestionName = false;
                symbolInAnswers = true;
                question->setText(trim_copy(questionNameStream.str()));
            }
            break;
        case '}':
            if (symbolInAnswerName) {
                question->addAnswer(trim_copy(answerNameStream.str()), currentAnswerIsCorrect);
            }
            return question;
            break;
        case '~':
            if (symbolInAnswerName) {
                question->addAnswer(trim_copy(answerNameStream.str()), currentAnswerIsCorrect);
                answerNameStream.str(string());
                answerNameStream.clear();
            } else {
                symbolInAnswerName = true;   
            }

            currentAnswerIsCorrect = false; break; 
        case '=': 
            if (symbolInAnswerName) {
                question->addAnswer(trim_copy(answerNameStream.str()), currentAnswerIsCorrect);
                answerNameStream.str(string());
                answerNameStream.clear();
            } else {
                symbolInAnswerName = true;
            }

            currentAnswerIsCorrect = true; break;
        default:
            if (symbolInQuestionName) {
                questionNameStream << (symbol == '\n' ? ' ' : symbol);
            } else if (symbolInAnswerName) {
                answerNameStream << symbol;
            }
        }
    }

    delete question;
    return nullopt;
}

void Gift::parseGiftFile(ifstream& giftFile) {
    while (auto question = parseOneQuestion(giftFile)) {
        questions.push_back(question.value());
    }
}

Gift::Gift(string giftFilePath) {
    ifstream giftFile(giftFilePath);
    if(giftFile.fail()) {
        throw std::runtime_error("Failed to open: " + giftFilePath);
    }
    parseGiftFile(giftFile);
}

Gift::~Gift() {
    for (auto question : questions) {
        delete question;
    }
    questions.clear();
}
