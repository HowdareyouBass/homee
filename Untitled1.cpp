#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <string>
#include <windows.h>
using namespace std;
fstream users;
fstream Dis;
fstream Dev;
fstream Bug;
fstream Dev_Com;
fstream Dis_Com;
fstream Bug_Com;
void clr(){
	system("cls");
}
string place,temp,temp2;
void Admin_menu(){
	setlocale(LC_ALL,"Russian");
	int ans;
	cout << "1.Delete User" << endl;
	cout << "2.Add User" << endl;
	cout << "3.Ban User" << endl;
}
void User_menu(){
	setlocale(LC_ALL,"Russian");
	int ans;
	string comment;
	Dis.open("Dis_file.txt",ios_base::out | ios_base::in);
	Dev.open("Dev_file.txt",ios_base::out | ios_base::in);
	Bug.open("Bug_file.txt",ios_base::out | ios_base::in);
	Dev_Com.open("Dev_Com.txt",ios_base::in | ios_base::out);
	Dis_Com.open("Dis_Com.txt",ios_base::in | ios_base::out);
	Bug_Com.open("Bug_Com.txt",ios_base::in | ios_base::out);
	cout << "1.Show file + comments" << endl;
	cout << "2.Send comment" << endl;
	cin >> ans;
	while(ans != 1 && ans != 2){
		cout << "No,no,no,darling you can't fuck the system of a down" << endl;
		cin >> ans;
	}
	if(ans == 1){
		cout << "File:" << endl;
		if(place == "2"){
			while(!Bug.eof()){
				getline(Bug,temp);
				cout << temp << endl;
			}
			cout << "Comments:" << endl;
			while(!Bug_Com.eof()){
				getline(Bug_Com,temp2);
				cout << temp2 << endl;
			}
			Bug.clear();
			Bug.seekg(0);
		}
		if(place == "3"){
			while(!Dis.eof()){
				getline(Dis,temp);
				cout << temp << endl;
			}
			cout << "Comments:" << endl;
			while(!Dis_Com.eof()){
				getline(Dis_Com,temp2);
				cout << temp2 << endl;
			}
			Dis.clear();
			Dis.seekg(0);
		}
		if(place == "4"){
			while(!Dev.eof()){
				getline(Dev,temp);
				cout << temp << endl;
			}
			cout << "Comments:" << endl;
			while(!Dev_Com.eof()){
				Dev_Com >> temp2;
				cout << temp2 << endl;
			}
			Dev.clear();
			Dev.seekg(0);
		}
	}
	if(ans == 2){
		cout << "Enter the comment" << endl;
		cin >> comment;
		if(place == "2"){
			Bug_Com << endl << comment;
		}
		if(place == "3"){
			Dis_Com << endl << comment;
		}
		if(place == "4"){
			Dev_Com << endl << comment;
		}
	}
	Dis.close();
	Dev.close();
	Bug.close();
	Bug_Com.close();
	Dis_Com.close();
	Dev_Com.close();
}
int main(){
	setlocale(LC_ALL,"Russian");
	users.open("Users.txt",ios_base::in | ios_base::out);
	int n,pl;
	bool admin,go_back = true,blocked = false;
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
			pl = i;
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
	Sleep(900);
	if(Users_info[pl][3] == "1"){
		blocked = true;
	}
	place = Users_info[pl][2];
	users.close();
	if(blocked != true){
		cout << place;
		if(place == "1"){
			Admin_menu();
		}
		if(place == "2"){
			User_menu();
		}
		if(place == "3"){
			User_menu();
		}
		if(place == "4"){
			User_menu();
		}
	}
	else{
		cout << "You was blocked by admin" << endl;
	}
	return 0;
}
