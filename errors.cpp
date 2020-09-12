#include "errors.hpp"

std::string Exception::getMessage() {
    return message;
}

int Exception::getCharPos() {
    return char_pos;
}

ParsingException::ParsingException(int char_pos) {
    message = "Parsing error occurred";
    char_pos = char_pos;
}