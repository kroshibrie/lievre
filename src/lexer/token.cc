#pragma once
#include <string>
#include "alias.cc"

// otherwise my fucking editor wont shut up FUCK YOU VSC
typedef string string;

enum TT {
  TT_EOF,

  TT_Symbol, // asdf
  TT_String, // "asdf"
  TT_Char,   // 'c'
  TT_Integer, // 1234
  TT_Float,   // 124.3f
  TT_Double,  // 43.2
  TT_True,
  TT_False,
  TT_Null,

  TT_Plus, // +
  TT_Dash, // -
  TT_Star, // *
  TT_Slash, // /

  TT_LParen, // ()
  TT_RParen,
  TT_LBracket, // []
  TT_RBracket,
  TT_LBrace, // {}
  TT_RBrace,

  TT_Semicolon, // ;
  TT_Equals, // =
};

class token {
  public:
  TT tokentype;
  string span;
  u32 ln, ch;

  token (TT, string, u32, u32);
};

token::token (TT _tokentype, string _span, u32 _ln, u32 _ch) {
  tokentype = _tokentype;
  span = _span;
  ln = _ln;
  ch = _ch;
}