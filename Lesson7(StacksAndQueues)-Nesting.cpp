// 3. Nesting.

/**
 * A string S consisting of N characters is called properly nested if:
 *       • S is empty;
 *       • S has the form "(U)" where U is a properly nested string;
 *       • S has the form "VW" where V and W are properly nested strings.
 * 
 * For example, string "(()(())())" is properly nested but string "())" isn't.
 * 
 * Write a function:
 *       class Solution { public int solution(String S); }
 * that, given a string S consisting of N characters,
 * returns 1 if string S is properly nested and 0 otherwise.
 * 
 * Write an efficient algorithm for the following assumptions:
 *       • N is an integer within the range [0..1,000,000];
 *       • string S is made only of the characters '(' and/or ')'.
 */

#include <string>
#include <stack>

int nesting(std::string& S)
{
    std::stack<char> brackets;  // A stack to store opening brackets.
    
    for (char c : S) {
        // If the character is an opening bracket, push it onto the stack.
        if (c == '(') {
            brackets.push(c);
        } else {
            // If the character is a closing bracket, check if it matches the top of the stack.
            if (brackets.empty() || (brackets.top() == '(' && c != ')')) {
                return 0;    
            }
            // Pop the top from the stack when a closing bracket is encountered.
            brackets.pop();
        }
    }

    return brackets.empty();
}
