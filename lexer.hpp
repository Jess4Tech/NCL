#ifndef LEXER_H
#define LEXER_H

#include <vector>
#include <string>

enum TokenKind {
  ID, // Identifier
  KW, // Keyword
  NUM, // 0-9
  Comment,
  UNEXPECTED,
  LParen, // (
  RParen, // )
  LBrack, // [
  RBrack, // ]
  LCurly, // {
  RCurly, // }
  LessThan, // <
  GreaterThan, // >
  Equal, // =
  Plus, // +
  Minus, // -
  Asterisk, // *
  Modulo, // %
  ForwardSlash, // /
  BackSlash, // \
  Pound, // #
  Comma, // ,
  Period, // .
  Colon, // :
  SemiColon, // ;
  SingleQuote, // '
  DoubleQuote, // "
  EOL, // End of Line, \0
  EOFT // End of File Token
};

struct Token {
  TokenKind type;
  std::vector<char> val;
};

class InputStream {
  private:
    std::vector<char> a_source;
    unsigned int a_pos;

  public:
    InputStream(std::vector<char> source);

    char next();
    char peek();
    bool eof();
};

class TokenStream {
  private:
    InputStream* a_input;

    bool is_whitespace(char ch);
    bool is_digit(char ch);
    bool is_alpha(char ch);
    bool is_keyword(char ch);
    bool is_id(char ch);
    bool is_id_start(char ch);
    bool is_symbol(char ch);
    bool is_operator(char ch);

  public:
    TokenStream(InputStream* input);

    Token next();
    Token peek();
    bool eof();
};

#endif