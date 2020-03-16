#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <string>
#include <windows.h>
using namespace std;
fstream users;
void clr(){
	system("cls");
}
int main(){
	users.open("Users.txt",ios_base::in | ios_base::out);
	int n;
	bool admin,go_back = true;
	string login = "",password = "",clear;
	for(int i = 0;!users.eof();i++){
		getline(users,clear);
		n = i;
	}
	n++;
	users.clear();
	users.seekg(0);
	string Users_info[n][4];
	for(int i = 0;i < n;i++){
		for(int j = 0;j < 4;j++){
			users >> Users_info[i][j];
		}
	}
	while(go_back == true){
		if(login != ""){
			cout << "There is no your login in our base" << endl;
			Sleep(1300);
			clr();
		}
		go_back = false;
		cout << "Autorization:" << endl;
		cout << "Login: ";
		cin >> login;
		for(int i = 0;i < n;i++){
			if(login == Users_info[i][0]){
				go_back = false;
				break;
			}
			else{
				go_back = true;
			}
		}
	}
	go_back = true;
	while(go_back == true){
		if(password != ""){
			cout << "Not right password";
			Sleep(1300);
			clr();
		}
		clr();
		cout << "Autorization:" << endl;
		cout << "Login:" << login << endl;
		cout << "Password: ";
		cin >> password;
		for(int i = 0;i < n;i++){
			if(password == Users_info[i][1]){
				go_back = false;
				break;
			}
			else{
				go_back = true;
			}
		}
	}
	clr();
	cout << "Autorization:" << endl;
	cout << "Login:" << login << endl;
	cout << "Password:" << password << endl;
	cout << "Logged in" << endl;
	users.close();
	return 0;
}
