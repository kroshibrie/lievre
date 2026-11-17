#pragma once
using namespace std;
#include <vector>
#include <optional>
#include <variant>
#include <unique_ptr.h>
#include "lexer/token.cc"

namespace ast {

  struct ast {};

  struct program : ast {
    vector <toplevel> _toplevels;
  };

  struct toplevel : ast {};

  struct parameter : ast {
    type _type;
    token _name;
  };

  struct func_sign : toplevel {
    token _name;
    vector <parameter> _parameters;
  };

  struct func_decl : toplevel {
    func_sign _signature;
    block _block;
  };

  struct block : statement {
    vector <statement> _statements;
  };

  struct statement : ast {};

  struct return_stmt : statement {
    optional <expression> _expression;
  };

  struct continue_stmt : statement {};

  struct break_stmt : statement {};

  struct if_stmt : statement {
    expression _expression;
    vector <elif_clause> _elif_clauses;
    optional <else_clause> _else_clause;
    block _block;
  };

  struct elif_clause : ast {
    expression _expression;
    block _block;
  };

  struct else_clause : ast {
    block _block;
  };

  struct while_stmt : statement {
    expression _expression;
    block _block;
  };

  struct do_while_stmt : statement {
    expression _expression;
    block _block;
  };

  struct decl_stmt : statement {};

  struct assign_stmt : decl_stmt {
    type _type;
    lhs _lhs;
    expression _expression;
  };

  struct lhs : ast {};

  struct symbol_lhs : lhs {
    token _symbol;
  };

  struct index_lhs : lhs {
    lhs _lhs;
    variant <lhs, literal> _index;
  };

  struct dot_lhs : lhs {
    lhs _lhs;
    lhs _rhs;
  };

  struct arrow_lhs : lhs {
    lhs _lhs;
    lhs _rhs;
  };

  struct expression : ast {};

  struct synth : expression {
    vector <assign_stmt> _assign_stmts;
  };

  struct inplace : expression {
    lhs _lhs;
    token _op;
    expression _expression;
  };

  struct ternary : expression {
    unique_ptr <expression> _condition;
    unique_ptr <expression> _truthy;
    unique_ptr <expression> _falsey;
  };

  struct binary : expression {
    token _op;
    unique_ptr <expression> _lhs;
    unique_ptr <expression> _rhs;
  };

  struct unary : expression {
    token _op;
    unique_ptr <expression> _lhs;
  };

  struct primary : expression {};

  struct group : primary {
    vector <expression> _expressions;
  };

  struct function_call : primary {
    lhs _name;
    vector <expression> _arguments;
  };

  struct comp_literal : ast {
    optional <type> _type;
    list_literal _list_literal;
  };

  struct list_literal : ast {
    vector <designated_init> _designated_inits;
  };

  struct designated_init : ast {
    optional <token> _name;
    expression _literal;
  };

  struct literal : primary {};

  struct null_literal : literal {};

  struct string_literal : literal {
    token _value;
  };

  struct integer_literal : literal {
    token _value;
  };

  struct double_literal : literal {
    token _value;
  };

  struct float_literal : literal {
    token _value;
  };

  struct char_literal : literal {
    token _value;
  };

  struct type : ast {};

  struct defined_type : type {
    token _type;
  };

  struct pointer_type : type {
    unique_ptr <type> _type;
  };

  struct reference_type : type {
    unique_ptr <type> _type;
  };

  struct generic_type : type {
    unique_ptr <type> _type;
    vector <type> _arguments;
  };

}