#include <iostream>
#include <stack>
#include <cctype>
#include <string>

using namespace std;

int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0;
}

int apply(int a, int b, char op) {
    switch (op) {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/': return b != 0 ? a / b : 0;
    }
    return 0;
}

int evaluate(const string& expr) {
    stack<int> values;
    stack<char> ops;

    for (size_t i = 0; i < expr.size(); i++) {
        if (isspace(expr[i])) continue;

        if (isdigit(expr[i])) {
            int val = 0;
            while (i < expr.size() && isdigit(expr[i])) {
                val = val * 10 + (expr[i] - '0');
                i++;
            }
            values.push(val);
            i--;
        }
        else if (expr[i] == '(') {
            ops.push('(');
        }
        else if (expr[i] == ')') {
            while (!ops.empty() && ops.top() != '(') {
                int b = values.top(); values.pop();
                int a = values.top(); values.pop();
                values.push(apply(a, b, ops.top()));
                ops.pop();
            }
            ops.pop();
        }
        else {
            while (!ops.empty() && precedence(ops.top()) >= precedence(expr[i])) {
                int b = values.top(); values.pop();
                int a = values.top(); values.pop();
                values.push(apply(a, b, ops.top()));
                ops.pop();
            }
            ops.push(expr[i]);
        }
    }

    while (!ops.empty()) {
        int b = values.top(); values.pop();
        int a = values.top(); values.pop();
        values.push(apply(a, b, ops.top()));
        ops.pop();
    }

    return values.top();
}

int main() {
    string expr;
    cout << "Enter expression: ";
    getline(cin, expr);

    cout << "Result: " << evaluate(expr) << endl;
    return 0;
}
