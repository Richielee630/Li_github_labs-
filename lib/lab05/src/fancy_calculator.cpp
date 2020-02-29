#include "fancy_calculator.h"
#include "stack.h"
#include "queue.h"
#include <cmath>
#include <string>
#include <sstream>

namespace lab5{
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

    void calculator::convert_to_postfix(lab5::queue infix_expression) {
        //fifo postfix_expression
        lab5::stack stack = lab5::stack();
        while(!(infix_expression.isEmpty())){
            if(IsOperand(infix_expression.top())){
                postfix_expression.enqueue(infix_expression.top());
            }else if(is_operator(infix_expression.top())){
                if(stack.isEmpty()||stack.top() == "(" || operator_priority(infix_expression.top()) > operator_priority(stack.top())){
                    stack.push(infix_expression.top());
                }else{
                    while(!stack.isEmpty() && is_operator(stack.top()) && operator_priority(stack.top())>=operator_priority(infix_expression.top())){
                        postfix_expression.enqueue(stack.top());
                        stack.pop();
                    }
                    stack.push(infix_expression.top());
                }
            }else if(infix_expression.top() == "(" ){
                stack.push(infix_expression.top());
            }else if(infix_expression.top() == ")"){
                while(stack.top()!="("){
                    postfix_expression.enqueue(stack.top());
                    stack.pop();
                }
                stack.pop();
            }
            infix_expression.dequeue();
        }
        while(!stack.isEmpty()){
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

    std::istream &operator>>(std::istream &stream, calculator &RHS) {
        std::string get;
        std::string input;
        while(stream >> get){
            input += get;
        }
        RHS = calculator(input);
        return stream;
    }

    int calculator::calculate() {
        lab5::stack stack;
        lab5::queue pe = postfix_expression;
        while(!pe.isEmpty()){
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

    std::ostream &operator<<(std::ostream &stream, calculator &RHS) {
        std::stringstream st;
        lab5::queue fifo_inter;
        st << "Infix: ";
        while(!RHS.infix_expression.isEmpty()){
            st << RHS.infix_expression.top();
            fifo_inter.enqueue(RHS.infix_expression.top());
            RHS.infix_expression.dequeue();
            if(!RHS.infix_expression.isEmpty()){
                st<<",";
            }
        }
        RHS.infix_expression = fifo_inter;
        lab5::queue fifo_inter2;
        st << "\nPostfix: ";
        while(!RHS.postfix_expression.isEmpty()){
            st << RHS.postfix_expression.top();
            fifo_inter2.enqueue(RHS.postfix_expression.top());
            RHS.postfix_expression.dequeue();
            if(!RHS.postfix_expression.isEmpty()){
                st << ",";
            }
        }
        RHS.postfix_expression = fifo_inter2;
        stream << st.str();
        return stream;
    }

    bool calculator::is_operator(std::string input_string) {
        return input_string == "+" || input_string == "-" || input_string == "*" || input_string == "/" || input_string == "^";
    }

    bool calculator::IsOperand(std::string input_string) {
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
            return 0;
        }
        if(operator_in == "/" || operator_in == "*"){
            return 1;
        }
        return 2;
    }


    // AUXILIARY FUNCTIONS
    bool is_number(std::string input_string);

    bool is_operator(std::string input_string);

    int get_number(std::string input_string);

    std::string get_operator(std::string input_string);

    int operator_priority(std::string operator_in);

}

