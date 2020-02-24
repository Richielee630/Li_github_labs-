#include <string>
#include "calculator.h"
namespace lab4 {
    void calculator::parse_to_infix(std::string &input_expression) {
//        lab3::fifo the_queue = lab3::fifo();
        std::string infix;
        for (int i = 0; i < input_expression.size(); i++)
        {
            infix[i] =
        }
    }

    void calculator::convert_to_postfix(lab3::fifo infix_expression) {
        lab3::lifo the_stack = lab3::lifo();
        std::string postfix;
//        for (int i = 0; i < infix_expression.size(); i++) {

//            // Scanning each character from left.
//            // If character is a delimiter, move on.
//            if (infix_expression[i] = "" || infix_expression[i] = ",") continue;
            // If character is operator, pop two elements from stack, perform operation and push the result back.
            if (is_operator(infix_expression.top()))
            {
                while (!the_stack.is_empty() && the_stack.top() != "(" &&
                HasHigherPrecedence(the_stack.top(), infix_expression.top()))
                {
                    postfix += the_stack.top();
                    the_stack.pop();
                }
                the_stack.push(infix_expression.top());
            }
                // Else if character is an operand
            else if (IsOperand(infix_expression.top()))
            {
                postfix += infix_expression.top();
            }
            else if (infix_expression.top() == "(") {
                the_stack.push(infix_expression.top());

            } else if (infix_expression.top() == ")") {
                while (!the_stack.is_empty() && the_stack.top() != "(") {
                    postfix += the_stack.top();
                    the_stack.pop();
                }
                the_stack.pop();
            }
//        }
        while(!the_stack.is_empty()) {
            postfix += the_stack.top();
            the_stack.pop();
        }
    }

    calculator::calculator() {

    }

    calculator::calculator(std::string &input_expression) {

    }

    std::istream &operator>>(std::istream &stream, calculator &RHS) {
        return stream;
    }

    int lab4::calculator::calculate() {
        return 0;
    }

    std::ostream &operator<<(std::ostream &stream, calculator &RHS) {
        return stream;
    }

    bool calculator::is_operator(std::string input_string) {
        return input_string == "+" || input_string == "-" || input_string == "*" || input_string == "/" ||
               input_string == "$";

    }

    bool calculator::isParen(std::string input_string) {
        return false;
    }

    bool calculator::is_number(std::string input_string) {
        return false;
    }

    int calculator::get_number(std::string input_string) {
        return 0;
    }

    std::string calculator::get_operator(std::string input_string) {
        return std::string();
    }

    int calculator::operator_priority(std::string operator_in) {
        return 0;
    }

    int calculator::GetOperatorWeight(std::string op) {
        int weight = -1;
        switch (op) {
            case '+':
            case '-':
                weight = 1;
                break;
            case '*':
            case '/':
                weight = 2;
                break;
            case '^':
                weight = 3;
                break;
        }
        return weight;
    }

    int calculator::HasHigherPrecedence(std::string op1, std::string op2) {
        int op1Weight = GetOperatorWeight(op1);
        int op2Weight = GetOperatorWeight(op2);

        // If operators have equal precedence, return true if they are left associative.
        // return false, if right associative.
        // if operator is left-associative, left one should be given priority.
        if(op1Weight == op2Weight)
        {
            if(IsRightAssociative(op1)) return false;
            else return true;
        }
        return op1Weight > op2Weight;
        return 0;
    }

    bool calculator::IsOperand(std::string input_string) {
        if(input_string >= "0" && input_string <= "9") return true;
        if(input_string >= "a" && input_string <= "z") return true;
        return input_string >= "A" && input_string <= "Z";
    }

    int calculator::IsRightAssociative(std::string op) {
        return op == "^";
    }

    // AUXILIARY FUNCTIONS

    bool is_operator(std::string input_string);

    bool isParen(std::string input_string);

    bool is_number(std::string input_string);

    int get_number(std::string input_string);

    std::string get_operator(std::string input_string);

    int operator_priority(std::string operator_in);

}