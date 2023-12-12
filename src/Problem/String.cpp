#include "String.h"

#include <map>
#include <stack>
#include <string>

static std::map<char, char> charMap{};
static void initCharMapIfEmpty() {
    if (!charMap.empty()) {
        return;
    }

    charMap[')'] = '(';
    charMap[']'] = '[';
    charMap['}'] = '{';
}

static bool checkParenthesisBalance(const std::string& s) {
    initCharMapIfEmpty();

    std::stack<char> charStack;
    auto length = static_cast<int>(s.length());

    for (int i = 0; i < length; i++) {
        auto currentChar = s[static_cast<std::size_t>(i)];
        if (charStack.empty()) {
            charStack.push(currentChar);
        } else if ((charMap[currentChar] &&
                    charStack.top() == charMap[currentChar])) {
            charStack.pop();
        } else {
            charStack.push(currentChar);
        }
    }

    if (charStack.empty()) {
        std::cout << s << " is BALANCED\n";
        return true;
    }

    std::cout << s << " is NOT BALANCED\n";
    return false;
}

void Problem::ReverseString() {
    const std::string s{"Hello There"};

    std::cout << "Reversing " << s << '\n';

    const int length = static_cast<int>(s.length() - 1);

    for (int i = length; i >= 0; i--) {
        std::cout << s[static_cast<std::size_t>(i)];
    }

    std::cout << '\n';
}

void Problem::IsBalancedParenthesis() {
    checkParenthesisBalance("{()}[]");
    checkParenthesisBalance("{(}()[]");
    checkParenthesisBalance("{()}()]");
}

