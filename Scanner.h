/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Scanner.h
 * Author: anas
 *
 * Created on April 23, 2019, 6:13 PM
 */

#ifndef SCANNER_H
#define SCANNER_H
#include <iostream>
#include <string>
#include <cstring>
#include <regex>
#include <list>
using namespace std;

class Scanner {
    private:

    string regarray[25][2] = {
        {"Keyword", "if|int|while|print|read|return|true[^;]|false[^;]"},
        {"ID", "([A-Z$])[a-z]*"},
        {"const_sys", "([1-9])([0-9])*|0"},
        {"Integer_sys", "[-]?[0-9]+"},
        {"Boolean_sys", "true|false"},
        {"Assign", "="},
        {"comparison", "(==)"},     
        {"plus", "[+]"},
        {"Minus", "[-]"},
        {"Multipl", "[*]"},
        {"Division", "[/]"},
        {"Neql", "[!=]"},
        {"Not", "[!]"},
        {"Semi", "[;]"},
        {"Coma", "[,]"},
        {"openBrace", "[{]"},
        {"closeBrace", "[}]"},
        {"openParen", "[(]"},
        {"closeParen", "[)]"},
        {"openBr", "[[]"},
        {"closeBr", "[]]"},
        {"linecomment", "<!--(.)?"},
        {"endlinecomment", "(.)*-->"},        
        {"beginmulticomment", "/[*](.)?"},
        {"endmulticomment", "(.)*[*]/"},
        


    };
    string input;
    int currentchar = 0;
    int tokenlen = 1;
    int currentline = 1;
    string currentstate="-99";
    string nextstate="-99";
    bool multicomment=false;
    bool onecomment=false;
    
 
  //  void getcurrenttoken(string &s);
  //  int getnextchar();
    void checktoken(string s);
    bool checkreg(string tok,string &current);
    void freetokenstruct();
public:
    Scanner();
    Scanner(const Scanner& orig);
    virtual ~Scanner();
    void setString(string s,int lineno);
    void scanInput();
    void printTokens();
    
    struct tokenstruct {
        string data;
        string type;
        int line;
    };
    list<tokenstruct> tokens;
    tokenstruct currenttoken;
};

#endif /* SCANNER_H */

