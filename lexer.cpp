#include "lexer.hpp"
#include <string>

InputStream::InputStream(std::vector<char> source) {
  a_source = source;
  a_pos = 0;
}

char InputStream::next() {
  if(!eof()) return a_source[a_pos++];
  else return '\0';
}

char InputStream::peek() {
  if(!eof()) return a_source[a_pos];
  else return '\0';
}

bool InputStream::eof() {
  if(a_pos >= a_source.size()) return true;
  else return false;
}

TokenStream::TokenStream(InputStream* input) {
  a_input = input;
}

Token TokenStream::peek() {
    if (!a_input->eof()) {
        if (is_id(a_input->peek())) {
            return {ID, std::vector<char>{a_input->peek()}};
        } else if (is_digit(a_input->peek())) {
            std::vector<char> numbers;
            while (is_digit(a_input->peek())) {
                numbers.push_back(a_input->peek());
                a_input->next();
            }
            return {NUM, numbers};
        } else if (is_operator(a_input->peek())) {
            switch(a_input->peek()) {
                case '+':
                    return {Plus, std::vector<char>{a_input->peek()}};
                case '-':
                    return {Minus, std::vector<char>{a_input->peek()}};
                case '/':
                    return {ForwardSlash, std::vector<char>{a_input->peek()}};
                case '*':
                    return {Asterisk, std::vector<char>{a_input->peek()}};
                case '%':
                    return {Modulo, std::vector<char>{a_input->peek()}};
            }
            a_input->next();
        } 
        else {
            return {UNEXPECTED, std::vector<char>{}};
        }   
    } else {
        return {EOFT, std::vector<char>{}};
    }
}

bool TokenStream::eof() {
    if (a_input->eof()) return true;
    else return false;
}

bool TokenStream::is_whitespace(char ch) {
    switch(ch) {
        case ' ':
        case '\t':
        case '\r':
        case '\n':
            return true;
        default:
            return false;
    }
}

bool TokenStream::is_digit(char ch) {
    if(ch <= '9' && ch >= '0') return true;
    else return false;
}

// turns an ascii number into an int
int ascii_number_to_int(char ch) {
  return (int)ch;
}

bool is_ascii_alpha(char ch) {
  if(
    (ch >= 'a' && ch <= 'z') // lower case
    || (ch >= 'A' && ch <= 'Z') // upper case
    || ch == '_' // underscore
  ) return true;
  else return false;
}

bool TokenStream::is_symbol(char ch) {
  switch(ch) {
    case '{':
    case '}':
    case '[':
    case ']':
    case '(':
    case ')':
    case ';':
      return true;
    default:
      return false;
  }
}

bool TokenStream::is_operator(char ch) {
    switch(ch) {
        case '%':
        case '^':
        case '+':
        case '-':
        case '*':
        case '/':
        case '!':
        case '|':
        case '<':
        case '>':
        case '=':
            return true;
        default:
            return false;
    }
}

bool TokenStream::is_id(char ch) {
    if(TokenStream::is_id_start(ch) || is_digit(ch)) return true;
    else return false;
}

bool TokenStream::is_id_start(char ch) {
  if(is_ascii_alpha(ch)) return true;
  else return false;
}