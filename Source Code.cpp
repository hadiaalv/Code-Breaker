//Code Breaker
#include<iostream>
#include"game.h"
using namespace std;

//Main Body
int main(){
	game P1;
	
	P1.players();
	
	system("cls");
	ifstream hFileP("players.txt",ios::in);
	string x;
	hFileP>>x;
	if(x=="a" || x=="A" || x=="1") P1.one_info();
	else if(x=="b" || x=="B" || x=="2") P1.two_info();
	system("cls");
	
	P1.rules();
	system("pause");
	
	if(x=="a" || x=="A" || x=="1") P1.game_one();
	else if(x=="b" || x=="B" || x=="2") P1.game_two();
	system("cls");
	
	cout<<"\t\t\t\t\t~~~~~~~~~~Thank you so much for Playing!~~~~~~~~~~\n\n\n\n\n\t\t\t\t\t\t";
	system("pause");
	
	
	return 0;
}
