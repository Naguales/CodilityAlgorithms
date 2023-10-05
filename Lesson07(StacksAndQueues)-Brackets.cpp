// 1. Brackets.

/**
 * A string S consisting of N characters is considered to be properly nested
 * if any of the following conditions is true:
 *       • S is empty;
 *       • S has the form "(U)" or "[U]" or "{U}" where U is a properly nested string;
 *       • S has the form "VW" where V and W are properly nested strings.
 * 
 * For example, the string "{[()()]}" is properly nested but "([)()]" is not.
 * 
 * Write a function:
 *       class Solution { public int solution(String S); }
 * that, given a string S consisting of N characters,
 * returns 1 if S is properly nested and 0 otherwise.
 * 
 * Write an efficient algorithm for the following assumptions:
 *       • N is an integer within the range [0..200,000];
 *       • string S is made only of the following characters: '(', '{', '[', ']', '}' and/or ')'.
 */

#include <string>
#include <stack>

int brackets(std::string& S)
{
    std::stack<char> brackets;  // A stack to store opening brackets.

    for (char c : S) {
        if (c == '(' || c == '{' || c == '[') {
            // If the character is an opening bracket, push it onto the stack.
            brackets.push(c);
        } else {
            // If the character is a closing bracket, check if it matches the top of the stack.
            if (brackets.empty() || (brackets.top() == '(' && c != ')')
                || (brackets.top() == '{' && c != '}')
                || (brackets.top() == '[' && c != ']')) {
                return 0;    
            }
            // Pop the top from the stack when an appropriate closing bracket is found.
            brackets.pop();
        }
    }

    return brackets.empty();
}
