#include <iostream>
#include <string>
#include "command_parser.hpp"
#include "calculator.hpp"
int main() {
    Calculator calc;
    command_parser::Command current_command;
    std::string input;
    
    std::cout << "\e[1;37mgmp_calc\e[0m by inxane\n" << std::endl;
    while (true) {
        calc.print_value();
        std::cout << std::endl << "\e[1;37m>\e[0m ";
        std::getline(std::cin, input);
        current_command = command_parser::parse(input);
        if (!current_command.success) {
            std::cout << "\e[1;31mERROR:\e[0m Invalid command." << std::endl;
            continue;
        }
        calc.compute(current_command);
    }
}
