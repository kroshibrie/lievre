#include <iostream>
#include <stdio.h>
#include <fstream>
#include <string>
#include <CLI/CLI.hpp>
using namespace std;
#include "lexer/lexer.cc"
#include "alias.cc"

void lex_file (string filename) {
  ifstream ifs (filename);
  string content ( (istreambuf_iterator<char>(ifs)), (istreambuf_iterator<char>()) );

  lexer l (content);

  while (!l.is_at_end()) {
    token tk = l.next();
    printf("token %s len %lld id %d\n", tk.span.c_str(), tk.span.length(), tk.tokentype);
  }

  return;
}

int main (int argc, char** argv) {
  CLI::App app {FG_TC(100, 100, 200) "liev language compiler" RESET};
  argv = app.ensure_utf8(argv);

  vector<string> filenames;
  app.add_option("files", filenames, "Input files")
  ->option_text("filenames")
  ->check(CLI::ExistingFile)
  ->required();

  bool verbose = false;
  app.add_flag("-v,--verbose", verbose, "Enable verbose output");

  CLI11_PARSE(app, argc, argv);

  lex_file(filenames[0]);

  return 0;
}