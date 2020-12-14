#pragma once
#include "command_parser.hpp"
#include <gmp.h>
#include <gmpxx.h>
#include <string>
#include <iostream>

class Calculator {
    public:
        Calculator() {
            mpf_set_default_prec(1024);
            mpf_init(value);
            mpf_init(argument);
        }
        ~Calculator() {
            mpf_clear(value);
            mpf_clear(argument);
        }
        void compute(const command_parser::Command& command) {
            if (command.argument.length() != 0) mpf_set_str(argument, command.argument.c_str(), 10);
            switch (command.operation) {
                case command_parser::Operation::ADD:
                    mpf_add(value, value, argument);
                    break;
                case command_parser::Operation::SUBTRACT:
                    mpf_sub(value, value, argument);
                    break;
                case command_parser::Operation::MULTIPLY:
                    mpf_mul(value, value, argument);
                    break;
                case command_parser::Operation::DIVIDE:
                    mpf_div(value, value, argument);
                    break;
                case command_parser::Operation::POWER:
                    mpf_pow_ui(value, value, std::stoul(command.argument.c_str())); 
                    break;
                case command_parser::Operation::PRECISION:
                    mpf_set_prec(value, std::stoul(command.argument.c_str()));
                    break;
                case command_parser::Operation::ABS:
                    mpf_abs(value, value);
                    break;
                case command_parser::Operation::CLEAR:
                    std::cout << "\e[2J\e[0;0H";
                    break;
                case command_parser::Operation::FACTORIAL:
                    mpf_floor(value, value);
                    mpf_abs(value, value);
                    mpf_t counter;
                    mpf_init(counter);
                    mpf_set(counter, value);
                    while (mpf_cmp_ui(counter, 1) != 0) {
                        mpf_sub_ui(counter, counter, 1);
                        mpf_mul(value, value, counter);
                    }
                    mpf_clear(counter);
                    break;
            }
        }
        void print_value() {
            gmp_printf("%.Ff", value);
        }
    private:
        mpf_t value, argument;
};
