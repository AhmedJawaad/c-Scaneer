/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: anas
 *
 * Created on April 23, 2019, 6:11 PM
 */

#include <cstdlib>
#include <iostream>
#include <string>
#include <fstream>
#include "Scanner.h"
#include "Parser.cpp"
using namespace std;

Scanner s;
int lineno=0;
void readfile(string &userstring) {

    string line;
    ifstream file;
    file.open("read.txt");
    while (!file.eof()) {
        getline(file, line);
        //file >> line;
        lineno++;
s.setString(line,lineno);
s.scanInput();
    }

    file.close(); // you must close the file you openned.
    // return userstring;
}
void readconsole(string &userstring){
	cout<<"to get out of the consol entering please enter ~? \n";
	string x;
        
do{
    lineno++;
	getline(cin,x);
	s.setString(x,lineno);
        s.scanInput();
}while(x!="~?");

}

/*
 * 
 */
int main(int argc, char** argv) {
cout<<"please choose how to inter your text"<<endl<<"1- consol\n2- file"<<endl;
int choosed;
cin>>choosed;

    string userstring; // the string  that will have all the file content

if(choosed==2){
	    readfile(userstring); //function to read the file content
	
}else if(choosed==1){
	readconsole(userstring);
}


cout<<endl;

s.printTokens();

//Parser p(s.tokens);
//p.Parserx(s.tokens);
//p.parseString();
    return 0;
}

