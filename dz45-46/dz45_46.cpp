#include <iostream>
#include <string>

void ReplaceText(std::string& s, const char* oldText, const char* newText) {
    size_t pos = 0;
    while ((pos = s.find(oldText, pos)) != std::string::npos) {
        s.replace(pos, strlen(oldText), newText);
        pos += strlen(newText);
    }
}

void InsertTextInPosition(std::string& text, const char* str, int* arrayPositions, int size) {
    int offset = 0;
    for (int i = 0; i < size; i++) {
        int pos = arrayPositions[i] + offset;
        text.insert(pos, str);
        offset += strlen(str);
    }
}

int main() {
    std::string text = "The quick brown fox jumps over the lazy dog.";
    std::cout << "Original text: " << text << std::endl;
    
    ReplaceText(text, "quick", "slow");
    std::cout << "Text after replacing 'quick' with 'slow': " << text << std::endl;
    
    int positions[] = {4, 19, 30};
    InsertTextInPosition(text, "red ", positions, 3);
    std::cout << "Text after inserting 'red ' at positions 4, 19, and 30: " << text << std::endl;
    
    return 0;
}