#include <iostream>
using namespace std;
#include "UserArray.h"


int main(){
    std::ifstream f("Userinfo.txt");
    UserArrayP sto(f);
    sto.store_global(5);
    //sto.display();
    char answer1;
    char user[20];
    char pass[20];
    bool follow = 1;
    while (follow){
       // sto.display();
        cout << "are you a new user? y/n" << endl;
        cin >> answer1;
        if (answer1 == 'y'){
            cout << "enter your st olaf username: " <<endl;
            cin >> user;
            cout << "make your password: " <<endl;
            cin >> pass;
            User *version = new User(user, pass);
            sto.addUser(*version);
            cout << "You are successfully registered" <<endl;
        }
        else if (answer1 == 'n'){
            cout << "enter your username: " <<endl;
            cin >> user;
            cout << "enter your password: " <<endl;
            cin >> pass;
            bool com = sto.checking(user, pass);
            if (com == 1){
                cout << "Login Sucessful!!!!" <<endl;
                follow = 0; 
            }
            else {
                cout << "Incorrect Username or Password" <<endl;
            }
        }
    }
    sto.print_to_file("Userinfo.txt");

}
