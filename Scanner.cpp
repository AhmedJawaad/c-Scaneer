/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Scanner.cpp
 * Author: anas
 * 
 * Created on April 23, 2019, 6:13 PM
 */

#include "Scanner.h"
using namespace std;

Scanner::Scanner() {
}

Scanner::Scanner(const Scanner& orig) {
}

Scanner::~Scanner() {
}

void Scanner::setString(string s,int lineno) {
    input = s;
    currentline=lineno;
}

bool Scanner::checkreg(string tok, string &current) {
    for (int i = 0; i <= 24; i++) {
  
        if (std::regex_match(tok, std::regex(regarray[i][1]))) {
            current = regarray[i][0];
           
           return true; 
        }

    }

     return false;

}


void Scanner::freetokenstruct(){
    currenttoken.data="";
    currenttoken.type="-99";
    currenttoken.line=1;
}




void Scanner::checktoken(string s){
    string str;
 
        for(int i=0;i<=s.length();i++){
            str+=s[i];
                    bool current= checkreg(str, currentstate);
                    bool next= checkreg(str+s[i+1], nextstate);
                    if(!current){
                        currentstate="-99";
                       continue;                    
                    }else{
                        
                        if(next){
                            continue;
                        }else{
                        
                            
                             if(currentstate=="endlinecomment"){
                                    onecomment=false;
                                    continue;
                                }
                             if(currentstate=="linecomment"||onecomment==true){
                               //  cout<< "---->"<<str;
                                    onecomment=true;
                                 continue;
                                 }
                                   if(currentstate=="endmulticomment"){
                                    multicomment=false;
                                    continue;
                                }
                                 if(currentstate=="beginmulticomment"||multicomment==true){
                                   multicomment=true;
                                    continue;
                                                   }
                         
                           

                        currenttoken.data = str;
                        currenttoken.type = currentstate;
                        currenttoken.line = currentline;
                        tokens.push_back(currenttoken);
                        currentstate="-99";
                        nextstate="-99";
                        freetokenstruct();

                        str="";
                        }
                        
                        
                    }//else end
                        
                    
                    
    
    }//end for
    
    

}


void Scanner::scanInput() {
    string s;
    int i=0;
   stringstream ss(input);
    while (getline(ss, s, ' ')) { // split line by spaces
     
        
        
        checktoken(s);
}

}

void Scanner::printTokens() {

    list<tokenstruct>::iterator iter = tokens.begin();
        while (iter != tokens.end()) {

            tokenstruct t = *iter;
            cout << "<" << t.type << "," << t.data << ">" << endl;
            iter++;

        }
    

    
}


