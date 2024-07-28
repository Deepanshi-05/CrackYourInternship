class Solution {
public:
    int calculate(string s) {
        std::stack<int> stack;
    int currentNumber = 0;
    char operation = '+';
    for (size_t i = 0; i < s.length(); ++i) {
        char currentChar = s[i];
        
        if (isdigit(currentChar)) {
            currentNumber = currentNumber * 10 + (currentChar - '0');
        }
        
        if (!isdigit(currentChar) && !isspace(currentChar) || i == s.length() - 1) {
            if (operation == '+') {
                stack.push(currentNumber);
            } else if (operation == '-') {
                stack.push(-currentNumber);
            } else if (operation == '*') {
                int top = stack.top();
                stack.pop();
                stack.push(top * currentNumber);
            } else if (operation == '/') {
                int top = stack.top();
                stack.pop();
                stack.push(top / currentNumber);
            }
            operation = currentChar;
            currentNumber = 0;
        }
    }
    
    int result = 0;
    while (!stack.empty()) {
        result += stack.top();
        stack.pop();
    }
    return result;
    }
};