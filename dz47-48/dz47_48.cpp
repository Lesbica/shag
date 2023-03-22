#include <iostream>
#include <vector>
#include <string>
#include <cstring>

void ConvertStringToChar(char** destArray, std::string* srcArray, int size) {
    for (int i = 0; i < size; i++) {
        destArray[i] = new char[srcArray[i].size() + 1];
        strncpy_s(destArray[i], srcArray[i].size() + 1, srcArray[i].c_str(), srcArray[i].size() + 1);
    }
    destArray[size] = nullptr;
}


void SplitText(std::string scrText, char delimeterChar, std::string** destArray, size_t* size) {
    std::vector<std::string> words;
    std::string word;
    for (char c : scrText) {
        if (c == delimeterChar) {
            if (!word.empty()) {
                words.push_back(word);
                word.clear();
            }
        } else {
            word += c;
        }
    }
    if (!word.empty()) {
        words.push_back(word);
    }
    *size = words.size();
    *destArray = new std::string[*size];
    for (size_t i = 0; i < *size; i++) {
        (*destArray)[i] = words[i];
    }
}


int main() {
    std::string text = "This, is, a, sample, text";
    char** charArray = new char*[4];
    ConvertStringToChar(charArray, new std::string[4] {"This", "is", "a", "test"}, 4);

    std::string* strArray;
    size_t size;
    SplitText(text, ',', &strArray, &size);

    std::cout << "ConvertStringToChar(): ";
    for (int i = 0; i < 4; i++) {
        std::cout << charArray[i] << " ";
    }
    std::cout << std::endl;

    std::cout << "SplitText(): ";
    for (size_t i = 0; i < size; i++) {
        std::cout << strArray[i] << " ";
    }
    std::cout << std::endl;

    for (int i = 0; i < 4; i++) {
        delete[] charArray[i];
    }
    delete[] strArray;

    return 0;
}