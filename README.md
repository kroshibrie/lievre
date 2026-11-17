# the liévre project

the **liévre project** is a language and compiler set made for teaching and dissecting the inner workings of a compiler, consisting of:

- **liev**, a statically & weakly typed programming language 
- **evre**, liev's companion compiler

as of right now, the project is still under construction:

- ✅ liev grammar spec *( [grammar](#grammar) [specs/grammar.ebnf](specs/grammar.ebnf) )*
- ✅ lexical analysis
- 🚧 syntactical analysis *( recursive descent [multiple parsers?](#multiparsers) )*
- ❌ syntactical analysis *( shift-reduce [multiple parsers?](#multiparsers) )*
- ❌ intermediate representation
- ❌ code generation
- ❌ standard library

## liévre's goal
i've noticed in my endless scowering of the interwebs that there exists a big gap in knowledge between resources that explain compilers in a "dumbed down" format, and actual battle-tested manuscripts of pages upon pages of text that a beginner in the compiler area can't be expected to understand

of course, both serve their purpose very well. those who want to have a tiny grasp on how the compiler reads code and spits out an executable are satisfied with a superficial explanation of what a lexer and parser are, and how rudimentary code generation works

on the other hand, those who want to make the next C compiler have all of the books in the world avaliable detailing every single internal choice, minute detail, and moment the programmer sneezed when writing the code

my *(and **liévre**'s)* goal is to provide a bridge for the people who dont know much about compilers, and want to know much about compilers without having to sit through the slog that is reading a book filled to the brim with jargon and footnotes *(ironic considering the namesake)*

## ai usage
**no ai is used in writing the code for this project.**  
*(locally ran)* ai *(qwen 3.5)* is occasionally used to revise hand-written code, finding bugs, and debugging

<a id="grammar"></a>

## grammar & philosophy
**liev**'s grammar is based on its three biggest influences:
- C *(++, occasionally)*
- Kotlin
- Ruby *(mostly reflected in the stdlib, tbd)*

additionally, **liev**'s philosophy and standard library are based on:
- Ruby
- [revo](https://revo.lung.fyi/)

**liev** makes use of C's ambiguous `type identifier` grammar for three reasons:
- it provides a grammar that's more intuitive to understand to someone already familiar with C/C++
- tackling the explanation of how the actual C compiler tackles this ambiguous syntax *(the "lexer hack")*
- i like it better than the `identifier: type` syntax

<a id="multiparsers"></a>

## multiple parsers?
yes there's multiple parsers

the goal of the **liévre project** is to show how all parts of a compiler work, and part of that "all" includes every *(reasonable)* alternative you can choose from and implement

this includes both of the "main" alternatives for a parser, complete with exploring their benefits, downsides, and reasons why you would implement them over the other depending on your language

## where is the education part
the material regarding constructing the compiler is being made into a youtube video whose script is being written alongside the code for the compiler, as to not miss anything

this is, although, an entire compiler, so it'll take a bit of time to even finish, letalone finish the video itself

as of right now, the video is aimed toward Q2/Q3 2027