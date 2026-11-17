#pragma once
#include <iostream>
using namespace std;
#include "lexer/token.cc"
#include "alias.cc"

bool is_num (char c) {
  return (c >= '0') && (c <= '9');
}

bool is_alpha (char c) {
  return (c >= 'a' && c <= 'z')
  || (c >= 'A' && c <= 'Z')
  || (c == '_');
}

bool is_alphanum (char c) {
  return is_num(c) || is_alpha(c);
}

bool is_whitespace (char c) {
  return c == ' ' || c == '\t' ||c == '\n';
}

class lexer {
  public:
  string src;
  u32 start, current;
  u32 ln, ch;

  lexer (string);

  bool is_at_end ();

  char peek ();
  char advance ();

  void skip_whitespace ();
  void skip_comments ();

  token lex_string ();
  token lex_number ();
  token lex_symbol ();
  token lex_char ();

  string get_substr ();

  token emit (TT);
  token next ();
};

lexer::lexer (string _src) {
  src = _src;
  start = 0;
  current = 0;
  ln = 1;
  ch = 1;
}

bool lexer::is_at_end () {
  return current >= src.length();
}

char lexer::peek () {
  if (is_at_end()) return '\0';
  return src[current];
}

char lexer::advance () {
  if (is_at_end()) return '\0';
  current++;
  return src[current - 1];
}

void lexer::skip_whitespace () {
  while (!is_at_end() && is_whitespace(peek())) advance();
}

void lexer::skip_comments () {
  if (!is_at_end() && peek() == '/') {
    while (!is_at_end() && peek() != '\n') advance();
  }
  advance();
}

token lexer::lex_string () {
  while (!is_at_end() && peek() != '"') {
    if (peek() == '\\') advance();
    advance();
  }
  advance();
  return emit(TT_String);
}

token lexer::lex_number () {
  bool i = true;
  bool d = true;
  while (!is_at_end() && is_num(peek())) advance();
  if (peek() == '.') {
    i = false;
    advance();
    while (!is_at_end() && is_num(peek())) advance();
    if (peek() == 'f') {
      advance();
      d = false;
    }
  }
  if (i) return emit(TT_Integer);
  if (d) return emit(TT_Double);
  return emit(TT_Float);
}

token lexer::lex_symbol () {
  while (is_alphanum(peek())) advance();
  if (get_substr() == "true") return emit(TT_True);
  if (get_substr() == "false") return emit(TT_False);
  if (get_substr() == "NULL") return emit(TT_Null);
  return emit(TT_Symbol);
}

token lexer::lex_char () {
  char y = advance(); // ch
  if (y == '\\') advance(); //for escaping
  advance(); // closing '
  return emit(TT_Char);
}

string lexer::get_substr () {
  return src.substr(start, current-start);
}

token lexer::emit (TT tt) {
  if (tt == TT_EOF) {
    return token (TT_EOF, "", ln, ch);
  }

  return token (tt, get_substr(), ln, ch);
}

token lexer::next () {
  skip_whitespace();
  if (is_at_end()) return emit(TT_EOF);
  if (peek() == '/') skip_comments();
  start = current;

  char c = advance();

  if (c == '+') return emit(TT_Plus);
  if (c == '-') return emit(TT_Dash);
  if (c == '*') return emit(TT_Star);
  if (c == '/') return emit(TT_Slash);

  if (c == '(') return emit(TT_LParen);
  if (c == ')') return emit(TT_RParen);

  if (c == '[') return emit(TT_LBracket);
  if (c == ']') return emit(TT_RBracket);

  if (c == '{') return emit(TT_LBrace);
  if (c == '}') return emit(TT_RBrace);

  if (c == ';') return emit(TT_Semicolon);
  if (c == '=') return emit(TT_Equals);

  if (c == '"') {
    return lex_string();
  }

  if (is_num(c)) {
    return lex_number();
  }

  if (is_alpha(c)) {
    return lex_symbol();
  }

  return emit(TT_EOF);
}