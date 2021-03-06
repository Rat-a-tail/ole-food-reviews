#include <iostream>
using namespace std;
#include "User.h"


//Default Constructor
User::User(){
    username = new char[10];
    password = new char[10];
    const char *us = "stolaf";
    const char *pa = "north";
    int lenu = getlen(us);
    int lenp = getlen(pa);
    for (int i = 0; i < lenp; i++){
        password[i] = pa[i];
        }

    for (int i = 0; i < lenu; i++){
        username[i] = us[i];
        }
}

//Constructor
User::User(const char *user, const char *pass){
        //userreviews = new Review*[0];
        int lenu = getlen(user);
        int lenp = getlen(pass);
        
        username = new char[lenu];
        password = new char[lenp];

        for (int i = 0; i < lenp; i++){
            password[i] = pass[i];
        }

        for (int i = 0; i < lenu; i++){
            username[i] = user[i];
        }
    }
//Copy Constructor
User::User(const User &cp){
        int lenu = getlen(cp.username);
        int lenp = getlen(cp.password);
        username = new char[lenu];
        password = new char[lenp];

        for (int i = 0; i < lenp; i++){
            password[i] = cp.password[i];
        }

        for (int i = 0; i < lenu; i++){
            username[i] = cp.username[i];
        }
}

User::~User(){
        delete [] username;
        delete [] password;
    }

//Methods

User &User::operator=(const User &cp){
        delete [] username;
        delete [] password;
        int lenu = getlen(cp.username);
        int lenp = getlen(cp.password);
        username = new char[lenu];
        password = new char[lenp];

        for (int i = 0; i < lenp; i++){
            password[i] = cp.password[i];
        }

        for (int i = 0; i < lenu; i++){
            username[i] = cp.username[i];
        }
    return *this;
}


int User::getlen(const char *word){
        int len = 0;
        while (word[++len] != 0){}
        return len+1;
    }


void User::changepass(char *npass){
        delete [] password;
        int len = getlen(npass);
        password = new char[len];
        for(int i = 0; i < len; i++){
            password[i] = npass[i];
        }

    }

void User::changeuser(char *nuser){
        delete [] username;
        int len = getlen(nuser);
        username = new char[len];
        for(int i = 0; i < len; i++){
            username[i] = nuser[i];
        }

    }

char *User::getuser(){
    return username;
}

char *User::getpass(){
    return password;
}

void User::display(){
        cerr << "Username: " << username <<endl;
        cerr << "Password: " << password <<endl;
    }

