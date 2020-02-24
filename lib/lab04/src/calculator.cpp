#include <string>
#include <sstream>
#include <math.h>
#include "calculator.h"
namespace lab4 {
    void calculator::parse_to_infix(std::string &input_expression) {
        lab1::expressionstream stream(input_expression);
        while(true){
            std::string next = stream.get_next_token();
            if( next == std::string("\0")){
                break;
            }
            infix_expression.enqueue(next);
        }
    }

    void calculator::convert_to_postfix(lab3::fifo infixExpression) {
        //fifo postfix_expression
        lab3::lifo stack = lab3::lifo();
        while(!(infixExpression.is_empty())){
            if(IsOperand(infixExpression.top())){
                postfix_expression.enqueue(infixExpression.top());
            }else if(is_operator(infixExpression.top())){
                if(stack.is_empty()||stack.top() == "(" || operator_priority(infixExpression.top()) > operator_priority(stack.top())){
                    stack.push(infixExpression.top());
                }else{
                    while(!stack.is_empty() && is_operator(stack.top()) && operator_priority(stack.top())>=operator_priority(infixExpression.top())){
                        postfix_expression.enqueue(stack.top());
                        stack.pop();
                    }
                    stack.push(infixExpression.top());
                }
            }else if(infixExpression.top() == "(" ){
                stack.push(infixExpression.top());
            }else if(infixExpression.top() == ")"){
                while(stack.top()!="("){
                    postfix_expression.enqueue(stack.top());
                    stack.pop();
                }
                stack.pop();
            }
            infixExpression.dequeue();
        }
        while(!stack.is_empty()){
            postfix_expression.enqueue(stack.top());
            stack.pop();
        }
    }

    calculator::calculator():infix_expression(),postfix_expression() {

    }

    calculator::calculator(std::string &input_expression):infix_expression() ,postfix_expression(){
        parse_to_infix(input_expression);
        convert_to_postfix(infix_expression);
    }


    int calculator::calculate() {
        lab3::lifo stack;
        lab3::fifo pe = postfix_expression;
        while(!pe.is_empty()){
            if(IsOperand(pe.top())){
                stack.push(pe.top());
            }else{
                int right = std::stoi(stack.top());
                stack.pop();
                int left = std::stoi(stack.top());
                stack.pop();
                int result = 0;
                if(pe.top() == "+"){
                    result = right + left;
                }else if (pe.top() == "-"){
                    result = left - right;
                }else if (pe.top() == "*"){
                    result = left * right;
                }else if (pe.top() == "/"){
                    result = left/right;
                }else if (pe.top() == "^"){
                    result = pow(left,right);
                }
                stack.push(std::to_string(result));
            }
            pe.dequeue();
        }
        return std::stoi(stack.top());
    }


    bool calculator::is_operator(std::string input_string) {
        return input_string == "+" || input_string == "-" || input_string == "*" || input_string == "/" || input_string == "^";
    }

    bool calculator::IsOperand(std::string input_string){
        return is_number(input_string);
    }

    bool calculator::is_number(std::string input_string) {
        if(input_string.empty()){
            return false;
        }
        auto it = input_string.begin();
        if(*it == '+' || *it == '-'){
            ++it;
        }
        //when input string is "+" or "-"
        if(it == input_string.end()){
            return false;
        }
        while(it != input_string.end()){
            if(*it < '0' || *it >'9'){
                return false;
            }
            ++it;
        }
        return true;
    }

    int calculator::operator_priority(std::string operator_in) {
        if(operator_in == "+" || operator_in == "-"){
            return 0;//low priority
        }
        if(operator_in == "/" || operator_in == "*"){
            return 1;//high priority
        }
        return 2;//for "^"
    }

    std::ostream &operator<<(std::ostream &stream, calculator &RHS) {
        std::stringstream st;
        lab3::fifo fifo_inter;
        st << "Infix: ";
        while(!RHS.infix_expression.is_empty()){
            st << RHS.infix_expression.top();
            fifo_inter.enqueue(RHS.infix_expression.top());
            RHS.infix_expression.dequeue();
            if(!RHS.infix_expression.is_empty()){
                st<<",";
            }
        }
        RHS.infix_expression = fifo_inter;
        lab3::fifo fifo_inter2;
        st << "\nPostfix: ";
        while(!RHS.postfix_expression.is_empty()){
            st << RHS.postfix_expression.top();
            fifo_inter2.enqueue(RHS.postfix_expression.top());
            RHS.postfix_expression.dequeue();
            if(!RHS.postfix_expression.is_empty()){
                st << ",";
            }
        }
        RHS.postfix_expression = fifo_inter2;
        stream << st.str();
        return stream;
    }

    std::istream &operator>>(std::istream &stream, calculator &RHS) {
        std::string get;
        std::string input;
        while(stream >> get){
            input += get;
        }
        RHS = calculator(input);
        return stream;
    }

}