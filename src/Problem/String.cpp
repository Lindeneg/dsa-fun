#include "String.h"

#include <iostream>
#include <map>
#include <string>

#include "../List/Stack.h"

static std::map<char, char> charMap{};
static void initCharMapIfEmpty() {
    if (!charMap.empty()) {
        return;
    }

    charMap[')'] = '(';
    charMap[']'] = '[';
    charMap['}'] = '{';
}

/* This solution uses a stack. Push opening brackets
 * onto stack and compare stackTop against found closing brackets.
 *
 * Expr: [ { } ]
 * Stack: -> TOP
 *
 * 1) Find opening bracket and push to stack.
 *
 * Stack: [
 *
 * 2) Opening bracket found.
 *
 * Stack: [ {
 *
 * 3) Closing bracket found. Must be same as stackTop.
 *
 * Stack: [
 *
 * 4) Closing bracket found, must be same as stackTop
 *
 * Stack:
 *
 * 5) Expression exhausted. If stack is empty, expression
 *    is balanced, else the brackets in stack are not closed.
 * */
static bool checkParenthesisBalance(const std::string& s) {
    initCharMapIfEmpty();

    List::Stack<char> charStack;
    auto length = static_cast<int>(s.length());

    for (int i = 0; i < length; i++) {
        auto currentChar = s[static_cast<std::size_t>(i)];
        if (charStack.IsEmpty()) {
            charStack.Push(currentChar);
        } else if ((charMap[currentChar] &&
                    charStack.Top() == charMap[currentChar])) {
            charStack.Pop();
        } else {
            charStack.Push(currentChar);
        }
    }

    if (charStack.IsEmpty()) {
        std::cout << s << " is BALANCED\n";
        return true;
    }

    std::cout << s << " is NOT BALANCED\n";
    return false;
}

// find str length and iterate over indices from
// length - 1 up until zero inclusive.
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

