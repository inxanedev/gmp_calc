#pragma once
#include <algorithm>
#include <cctype>
#include <string>
#include <sstream>

namespace command_parser {
    enum Operation {
        ADD, SUBTRACT, MULTIPLY,
        DIVIDE, POWER, PRECISION,
        ABS, CLEAR, FACTORIAL,
        SQRT, FLOOR, CEIL, RESET,
        HELP
    };
    struct Command {
        bool success;
        Operation operation;
        std::string argument;
    };
    Command parse(std::string& str) {
        Command result;
        result.success = true;
        std::transform(str.begin(), str.end(), str.begin(), [](unsigned char c) {
            return std::tolower(c);
        });
        std::istringstream ss(str);
        std::string current;
        ss >> current;
        if      (current == "add")   result.operation = Operation::ADD;
        else if (current == "sub")   result.operation = Operation::SUBTRACT;
        else if (current == "mul")   result.operation = Operation::MULTIPLY;
        else if (current == "div")   result.operation = Operation::DIVIDE;
        else if (current == "pow")   result.operation = Operation::POWER;
        else if (current == "prec")  result.operation = Operation::PRECISION;
        else if (current == "abs")   result.operation = Operation::ABS;
        else if (current == "clr")   result.operation = Operation::CLEAR;
        else if (current == "fact")  result.operation = Operation::FACTORIAL;
        else if (current == "sqrt")  result.operation = Operation::SQRT;
        else if (current == "ceil")  result.operation = Operation::CEIL;
        else if (current == "floor") result.operation = Operation::FLOOR;
        else if (current == "reset") result.operation = Operation::RESET;
        else if (current == "help")  result.operation = Operation::HELP;
        else result.success = false;
        ss >> result.argument;
        return result;
    }
}
