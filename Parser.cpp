/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "Scanner.h"
#include <list>
#include <stack>
#include <algorithm>
class Parser {
    
    Scanner s;
    list<Scanner::tokenstruct> l;

    list<string> errors;

 Scanner::tokenstruct currenttoken ;
list<Scanner::tokenstruct>::iterator it;
    
public:
Parser(list<Scanner::tokenstruct> l1){
    this->l=l1;
 
it = l.begin();
//cout<<l.size();

 currenttoken=*it;

    
    

}

bool checkstruct( const Scanner::tokenstruct& s1, const Scanner::tokenstruct& s2)
{
   // cout<<"dddddddddddddddddddddddd";
    return (s1.data==s2.data&&s1.line==s2.line&&s1.type==s2.type);
}

    void advance() {
        l.begin();
      
       while(it!=l.end()){
       
           if(checkstruct(currenttoken,*it)){
               
               ++it;
               currenttoken=*it;
               
               break;
           }
           ++it;
       }
     
       
        }
  

    void back() {
         l.end();
      
       while(it!=l.begin()){
       
           if(checkstruct(currenttoken,*it)){
               
               --it;
               currenttoken=*it;
               
               break;
           }
           --it;
       }
    }

    bool Arglis() {
        if (currenttoken.type == "ID") {
            advance();
            if (currenttoken.type == "Coma")
                Arglis();

            return true;
        }

        return false;
    }

    bool fundecl() {
        if (currenttoken.type == "ID") {
            advance();
            if (currenttoken.type == "openParen") {
                advance();


                if (currenttoken.type == "closeParen") {
                    advance();
                    if (currenttoken.type == "Semi") {
                        return true;
                    }
                } else if (Arglis()) {
                    if (currenttoken.type == "closeParen") {
                        advance();
                        if (currenttoken.type == "Semi") {
                            return true;
                        }
                    }


                }


            }

        }
    }

    bool parseBstate() {


    }

    bool checkex(){ //e~
          if(currenttoken.data!="+"||currenttoken.data!="-"){
                
            advance();
            if(checkTerm());
            return true;
        }else if(checkTerm()){
            return true;
        }
        
          return false;
    }
    bool checkExpr() {
        Scanner::tokenstruct data=currenttoken;
        if(checkex())
            checkExpr();
        else
            cout<<"error At Line "<<currenttoken.line<<" At "<<currenttoken.data;
            
            
        
       

    }

    bool checkArgm() {
        if (checkExpr()) {
            advance();
            if (currenttoken.type == "Coma") {
                checkArgm();
            } else {
                back();
                return false;
            }



        } else
            return false;

        return true;
    }

    bool checkTerm() {
        cout<<"@check Term"<<endl;
        if (!checkFactor())
        {
            cout<<"test";
            checkTerm();
            advance();
            if (currenttoken.type == "Multipl" || currenttoken.type == "Division") {
                return true;
            
            advance();
            checkFactor();
            true;
            }
        }
    }

bool    checkFactor() {
    cout<<"@check Factor"<<endl;
        if (currenttoken.type == "const_sys"){
            cout<<currenttoken.data;
            return true;
        
        }
        if (currenttoken.type == "openParen") {
            advance();
            if (checkExpr()) {
                advance();
                if (currenttoken.type == "closeParen") {
                    return true;
                } else {
                    return false;
                }
            } else {
                return false;
            }
        } else if (currenttoken.type == "ID") {
            advance();
            if (currenttoken.type == "openBr") {
                advance();
                if (currenttoken.type == "closeBr") {
                    return true;
                } else {


                    if (!checkExpr() || !checkArgm()) {
                        return false;

                    }
                }
                advance();
                if (currenttoken.type == "closeBr") {
                    return true;
                } else {
                    return false;
                }
            }



            return true;
        } else {

            return false;
        }

    }

    bool checkAssignment() {
        
        if (currenttoken.type == "ID") {
           
            advance();
            if (currenttoken.type == "Assign") {
               
                advance();
                return checkExpr();
                 
            } 
//            else if (currenttoken.type == "openBr") {
//                advance();
//                if (checkExpr()) {
//                    advance();
//                    if (currenttoken.type == "closeBr") {
//                        return true;
//                    }
//                } else {
//                    return false;
//                }
//
//            } else {
//                return false;
//            }

        } else
            return false;


    }
    
    bool addginstate(){
    
    }
    bool Statement(){
        if(checkAssignment()){
            cout<<"Assign True";
            return true;
        }
        
    }
    bool states(){
        if(!Statement()){
            cout<<"error At Line "<<currenttoken.line<<" At "<<currenttoken.data;
                exit(0);
        }
        advance();
        if(currenttoken.data==";"){
            advance();
            states();
        }
        else{
            back();
        }
    
    }
    
    bool Bstatement(){
        if(currenttoken.data!="{")
        { cout<<"error At Line "<<currenttoken.line<<" At "<<currenttoken.data;
                exit(0);
        }
        states();
        advance();
        if(currenttoken.data!="}")
        { 
             cout<<"error At Line "<<currenttoken.line<<" At "<<currenttoken.data;
                exit(0);
        }
    
    
    }
    bool vardec(){
        if(currenttoken.type!="ID")
        { return false;
           cout<<"error At Line "<<currenttoken.line<<" At "<<currenttoken.data;
                exit(0);
        } else{
            advance();
            if(currenttoken.data=="[")
            {
                advance();
                if(currenttoken.type!="const_sys"){
                    
                    return false;
                }else{
                    advance();
                    if(currenttoken.data=="]"){
                        return true;
                    }
                }
            
            }else{
                back();
            }
        
        }
    }
    bool DEfList(){
        vardec();
        advance();
        if(currenttoken.data==","){
            advance();
            vardec();
        }else{
            back();
        }
        
    
    }
    bool vardecl(){
        if(currenttoken.data=="int"){
            advance();
            DEfList();
            advance();
            if(currenttoken.data==";"){
                return true;
            }
            else{
                cout<<"error At Line "<<currenttoken.line<<" At "<<currenttoken.data;
                exit(0);
                return false;
            }
        }
        else
        {
            return false;
        }
    }
  //  bool fundecl(){}
    bool declaration(){
    
        if(vardecl())
            return true;
        else if(fundecl())
            return true;
        else{
               cout<<"error At Line "<<currenttoken.line<<" At "<<currenttoken.data;
                exit(0);
            return false;
        }
    
    }
    
    bool Declarations(){
        if(declaration())
            return true;
        else
            Declarations();
    
    }
    
    
    
    
public:

    bool parseString() {
      
        if (currenttoken.type == "openBrace") {
             Bstatement();
             cout<<"no Errors Found";
             return true;
        } else {
            Declarations();
           Bstatement();
           cout<<"no Errors Found";
            return true;
        }
           cout<<"error At Line "<<currenttoken.line<<" At "<<currenttoken.data;
                exit(0);
        return false;

    }

    

};