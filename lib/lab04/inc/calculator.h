#ifndef CMPE126S20_LABS_CALCULATOR_H
#define CMPE126S20_LABS_CALCULATOR_H

#include "lifo.h"
#include "fifo.h"
#include "expressionstream.h"

namespace lab4{
    class calculator {
        lab3::fifo infix_expression;
        lab3::fifo postfix_expression;

        void parse_to_infix(std::string &input_expression); //PRIVATE function used for converting input string into infix notation
        void convert_to_postfix(lab3::fifo infix_expression); //PRIVATE function used for converting infix FIFO to postfix


    public:
        calculator();   //Default constructor
        calculator(std::string &input_expression); // Constructor that converts input_expression to infix and postfix upon creation
        friend std::istream& operator>>(std::istream& stream, calculator& RHS); //Store the infix and postfix expression in calculator

        int calculate(); //Return the calculation of the postfix expression
        friend std::ostream& operator<<(std::ostream& stream, calculator& RHS); //Stream out overload. Should return in the format "Infix: #,#,#,#\nPostfix: #,#,#,#"
        bool is_operator(std::string input_string);
        bool IsOperand(std::string input_string);
        bool isParen(std::string input_string);
        bool is_number(std::string input_string);
        int get_number(std::string input_string);
        std::string get_operator(std::string input_string);
        int operator_priority(std::string operator_in);
        int IsRightAssociative(std::string op);
        int GetOperatorWeight(std::string op);
        int HasHigherPrecedence(std::string op1, std::string op2);

            //return (input_string >= "0" && input_string <= "9");
        };
    }

#endif //CMPE126S20_LABS_CALCULATOR_H
