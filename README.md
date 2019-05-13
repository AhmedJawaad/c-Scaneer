# c-Scaneer
this is scanner for compiler written in c++ that useses c++ regular expersion made by principles of oop like classes and headers
the language specification 

 the application can read from file or from consol line by line

Lexical Considerations

1) Keywords: The following are keywords.
int, if.while,print, read,return, true , false
They are all reserved, which means they cannot be used as identifiers
2) Identifiers: [A-Z$][a-z]+
3) Whitespaces: (spaces, tabs, and carriage returns) serves to separate tokens,
otherwise; they are ignored.
4) true and false are Boolean constant.
5) An integer constant is specified in decimal and leading zeroes are allowed.
digit⟶ [-]?[0-9]+
6) Constant [1-9][0-9] *| 0
7) Operators and punctuation characters used by the language includes:
=
==
===
+ 
- 
*
!=
! ; , [ ] ( ) { }
8) Comments are discarded.
a. A single line comment is started by<!--.*-> and extends to the end of
the line.
b. A Blockstetment Comment start with /* and end with the first
subsequent */ . Any symbol is allowed in a comment except the
sequence */ which ends the current comment. Blockstetment
comments do not nest.
