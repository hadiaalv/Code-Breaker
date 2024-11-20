#include<iostream>
#include<fstream>
#include<cstdlib>
#include<cstring>
#include<conio.h>
#include<iomanip>
#include<ctime>
using namespace std;
void stars(){
	cout<<"*********";
}

//Class
class game{
	private:
		char fname[30];
		char lname[30];
		int age;
		char gender;
		char before;
		
	public:
		void players(){
			while(1){
			system("cls");
			string a;
			cout<<"\n\t\t\t\t\t\t\tWelcome to Code Breaker!\n\n\t\t\t------------> Let\'s see if you have what it takes to break the code! <------------\n\n\t\t\t\t\t\t   ******** We hope you enjoy! ********\n\n\n\t\t\t\t\t\t\t";
			system("pause");
			system("cls");

			cout<<"\t\t\t\t\t\t      Players:\n\t\t\t\t\t\t      ++++++++\n\n\t\t\t\t\t\t\tA) 1\n\t\t\t\t\t\t\tB) 2\n\n\n\t\t\t\t\t\t\t|\n\t\t\t\t\t\t\t|\n\t\t\t\t\t\t\tV\n\t\t\t\t\t\t\t";
			cin>>a;
			cout<<"\n\n\n\t\t\t\t          ";
			system("pause");
			
			ofstream hFile("players.txt",ios::out);
			hFile<<a;
			if(a!="a" && a!="A" && a!="b" && a!="B" && a!="1" && a!="2"){
			cout<<"\n\nLooks like you tried to cheat the code!\nTry again :)\n\n";
			system("pause");}
			else break;
			}
		}
		
		void one_info(){
			cin.ignore();
			cout<<"\t\t\t\t\t\t\t* Before we begin *\n\t\t\t\t\t\t\t*";
			stars();
			stars();
			cout<<"\n\n->Your First Name: ";
			cin.getline(fname,30);
			cout<<"->Your Last Name: ";
			cin.getline(lname,30);
			cout<<"->Your Age: ";
			cin>>age;
			cout<<"->Your Gender (M/F): ";
			cin>>gender;
			cout<<"->First time player? (Y/N): ";
			cin>>before;
			cout<<"\n";
			ofstream hFile_data("Data.txt",ios::out);
			hFile_data<<fname<<"\t"<<lname<<"\t"<<age<<"\t"<<gender<<"\t"<<before<<"\n";
		}
		
		void two_info(){
			cin.ignore();
			cout<<"\t\t\t\t\t\t\t* Before we begin *\n\t\t\t\t\t\t\t*";
			stars();
			stars();
			cout<<"\n\n\n\t\t\t\t\t\t\t--->First Player:\n\n->Your First Name: ";
			cin.getline(fname,30);
			cout<<"->Your Last Name: ";
			cin.getline(lname,30);
			cout<<"->Your Age: ";
			cin>>age;
			cout<<"->Your Gender (M/F): ";
			cin>>gender;
			cout<<"->First time player? (Y/N): ";
			cin>>before;
			cout<<"\n";
			ofstream hFile_data1("Data.txt",ios::out);
			hFile_data1<<fname<<"\t"<<lname<<"\t"<<age<<"\t"<<gender<<"\t"<<before<<"\n";
			cin.ignore();
			cout<<"\n\n\t\t\t\t\t\t\t--->Second Player:\n\n->Your First Name: ";
			cin.getline(fname,30);
			cout<<"->Your Last Name: ";
			cin.getline(lname,30);
			cout<<"->Your Age: ";
			cin>>age;
			cout<<"->Your Gender (M/F): ";
			cin>>gender;
			cout<<"->First time player? (Y/N) ";
			cin>>before;
			cout<<"\n";
			ofstream hFile_data2("Data2.txt",ios::out);
			hFile_data2<<fname<<"\t"<<lname<<"\t"<<age<<"\t"<<gender<<"\t"<<before<<"\n";
		}
		
		void rules(){
			string check;
			ifstream hFile("players.txt",ios::in);
			if(!hFile) cout<<"File could not be opened\n";
			else{
				hFile>>check;
			}
			cout<<"\t\t\t\t\t\t~~~~~~~Rules~~~~~~~\n\n";
			if(check=="a" || check=="A" || check=="1") {
				ifstream hFile1("rules.txt",ios::in);
				char a;
				while(hFile1.get(a)){
					cout<<a;
				}
			}
			else if(check=="b" || check=="B" || check=="2") {
				ifstream hFile2("rules2.txt",ios::in);
				char b;
				while(hFile2.get(b)){
					cout<<b;
				}
			}
			cout<<"\t\t\t\t\t\t~~~~~~~Enjoy~~~~~~~\n\n\n\n\t\t\t\t\t   ";
		}
		
		void game_one(){
			srand(time(0));
			int a=5;
			for(int i=1; i<=5;i++){
				char guess;
				int r1=rand()%61+20;
				int r2=rand()%81+10;
				system("cls");
				cout<<"\n\t\t\t\t\t\t\t**************\n\t\t\t\t\t\t\t Number "<<i<<": "<<r1<<"\n\t\t\t\t\t\t\t**************\n\n\t\t\t\t\t\t    -> Your guess (H/L): ";
				cin>>guess;
				if(guess!='H' && guess!='h' && guess!='L' && guess!='l'){
					cout<<"\n\t\t\t\t\t\t\tWrong guess! Try again!\n\n\n\t\t\t\t\t   ";
					cin>>guess;
				}
				cout<<"\n\t\t\t\t\t\t     *********************\n\t\t\t\t\t\t      The next number: "<<r2<<" \n\t\t\t\t\t\t     *********************\n";
				if(r2==r1){
					cout<<"\n\n\t\t\t\t\t\t~~~~~~You're saved!~~~~~~\n\n\n\t\t\t\t\t\t";
					system("pause");
				}
				
				else if((guess=='H' || guess=='h') && r2>r1){
					cout<<"\n\n\t\t\t\t~~~~~~Correct Guess! You're now one step closer to breaking the code!~~~~~~\n\n\n\t\t\t\t\t\t";
					a=a+1;
					system("pause");
				}
				else if((guess=='L' || guess=='l') && r2<r1){
					cout<<"\n\n\t\t\t\t~~~~~~Correct Guess! You're now one step closer to breaking the code!~~~~~~\n\n\n\t\t\t\t\t\t";
					a=a+1;
					system("pause");
				}
				else{
					cout<<"\n\n\t\t\t\t\t    ~~~~~~Oops! You just lost a point!~~~~~~\n\n\n\t\t\t\t\t\t";
					a=a-1;
					system("pause");
				}
			}
			system("cls");
			cout<<"\n\t\t\t\t\t\t\t//////////\\\\\\\\\\\\\\\\\\\\\n\t\t\t\t\t\t\tYour final score: "<<a<<"\n\t\t\t\t\t\t\t\\\\\\\\\\\\\\\\\\\\//////////\n\n\n\n\t\t\t\t\t\t";
			system("pause");
			
			if(a==0){
				system("cls");
				cout<<"\n\t\t\t\t\tOops! Looks like the code just broke you. Better luck next time!\n\n\n\t\t\t\t\t\t";
				system("pause");
			}
			else if(a==5){
				system("cls");
				cout<<"\n\t\t\t\t\tYou played nice but could've played better. Better luck next time!\n\n\n\t\t\t\t\t\t";
				system("pause");
			}
			else if(a>5){
				system("cls");
				cout<<"\n\t\t\t\t\t\tCongratulations! You just broke the code!\n\n\n\t\t\t\t\t\t";
				system("pause");
			}
			else if(a<5){
				system("cls");
				cout<<"\n\t\t\t\t\tSorry but you couldn't break the code. Better luck next time!\n\n\n\t\t\t\t\t\t";
				system("pause");
			}
		}
		
		void game_two(){
			srand(time(0));
			int a=5,b=5;
			for(int i=1; i<=5;i++){
				char guess1,guess2;
				int r1=rand()%61+20;
				int r2=rand()%81+10;
				system("cls");
				cout<<"\n\t\t\t\t\t\t\t**************\n\t\t\t\t\t\t\t Number "<<i<<": "<<r1<<"\n\t\t\t\t\t\t\t**************\n\n\n\t\t\t\t\t\t    ->Player 1\'s guess (H/L): ";
				cin>>guess1;
				if(guess1!='H' && guess1!='h' && guess1!='L' && guess1!='l'){
					cout<<"\n\t\t\t\t\t\t\tWrong guess! Try again!\n\n\n\t\t\t\t\t   ";
					cin>>guess1;
				}
				cout<<"\n\t\t\t\t\t\t    ->Player 2\'s guess (H/L): ";
				cin>>guess2;
				if(guess2!='H' && guess2!='h' && guess2!='L' && guess2!='l'){
					cout<<"\n\t\t\t\t\t\t\tWrong guess! Try again!\n\n\n\t\t\t\t\t   ";
					cin>>guess2;
				}
				cout<<"\n\n\t\t\t\t\t\t     *********************\n\t\t\t\t\t\t      The next number: "<<r2<<" \n\t\t\t\t\t\t     *********************\n";
				if(r2==r1){
					cout<<"\n\n\t\t\t\t\t\t\t~~~~~~You're saved!~~~~~~\n\n\n\t\t\t\t\t   ";
					system("pause");
				}
				else{
					//Player 1
					if((guess1=='H' || guess1=='h') && r2>r1){
						cout<<"\n\n\t\t\t  ~~~~~~Player 1, Correct Guess! You're now one step closer to breaking the code!~~~~~~";
						a=a+1;
					}
					else if((guess1=='L' || guess1=='l') && r2<r1){
						cout<<"\n\n\t\t\t  ~~~~~~Player 1, Correct Guess! You're now one step closer to breaking the code!~~~~~~";
						a=a+1;
					}
					else{
						cout<<"\n\n\t\t\t\t\t  ~~~~~~Player 1, Oops! You just lost a point!~~~~~~";
						a=a-1;
					}
					
					//Player 2
					if((guess2=='H' || guess2=='h') && r2>r1){
						cout<<"\n\n\t\t\t  ~~~~~~Player 2, Correct Guess! You're now one step closer to breaking the code!~~~~~~\n\n\n\t\t\t\t\t\t";
						b=b+1;
						system("pause");
					}
					else if((guess2=='L' || guess2=='l') && r2<r1){
						cout<<"\n\n\t\t\t  ~~~~~~Player 2, Correct Guess! You're now one step closer to breaking the code!~~~~~~\n\n\n\t\t\t\t\t\t";
						b=b+1;
						system("pause");
					}
					else{
						cout<<"\n\n\t\t\t\t\t  ~~~~~~Player 2, Oops! You just lost a point!~~~~~~\n\n\n\t\t\t\t\t\t";
						b=b-1;
						system("pause");
					}
				}
			}
			int x=0, y=0;
			
			system("cls");
			cout<<"\n\t\t\t\t\t\t\t//////////////\\\\\\\\\\\\\\\\\\\\\\\\\n\t\t\t\t\t\t\tPlayer 1\'s final score: "<<a<<"\n\t\t\t\t\t\t\t\\\\\\\\\\\\\\\\\\\\\\\\\\\\////////////\n";
			cout<<"\n\t\t\t\t\t\t\t//////////////\\\\\\\\\\\\\\\\\\\\\\\\\n\t\t\t\t\t\t\tPlayer 2\'s final score: "<<b<<"\n\t\t\t\t\t\t\t\\\\\\\\\\\\\\\\\\\\\\\\\\\\////////////\n\n\n\n\n\t\t\t\t\t\t\t";
			system("pause");
			
			if(a==b){
				system("cls");
				cout<<"\n\t\t\t\t\t**********************************************\n\t\t\t\t\t* What a funny coincidence! Congratulations! *\n\t\t\t\t\t**********************************************\n\n\n\t\t\t\t";
				system("pause");
			}
			else{
				system("cls");
				cout<<"\n\t\t\t\t\t************************************************\n\t\t\t\t\t* Oops! Looks like we have a situation in hand *\n\t\t\t\t\t************************************************\n";
				if(a>b){
					cout<<"\n\n\t\t\t\t~~~~~~~~~~Congratulations Player 1! You just broke the code!~~~~~~~~~~\n\n\t~~~~~~~~~~As for Player 2, looks like you couldn\'t crack the code. Best of luck for the dare though :D~~~~~~~~~~\n\n\n\n\t\t\t\t\t\t";
					system("pause");
					x=x+1;
				}
				if(a<b){
					cout<<"\n\n\t\t\t\t~~~~~~~~~~Congratulations Player 2! You just broke the code!~~~~~~~~~~\n\n\t~~~~~~~~~~As for Player 1, looks like you couldn\'t crack the code. Best of luck for the dare though :D~~~~~~~~~~\n\n\n\n\t\t\t\t\t\t";
					system("pause");
					y=y+1;
				}
			
				system("cls");
				int choice;
				cout<<"\n\t\t\t\t\t\t\t***********\n\t\t\t\t\t\t\t*Dare Time*\n\t\t\t\t\t\t\t***********\n\n\n\t\t\t\tWinner now gets to choose a random number between 1 and 5: \n\n\n\t\t\t\t\t\t\t\t|\n\t\t\t\t\t\t\t\t|\n\t\t\t\t\t\t\t\tV\n\t\t\t\t\t\t\t\t";
				cin>>choice;
	
				if(x==1) cout<<"\n\n\t\t\t\t\t\t->Player 2, your dare is:\n\t\t\t\t\t";	
				if(y==1) cout<<"\n\n\t\t\t\t\t\t->Player 1, your dare is:\n\t\t\t\t\t";
			
				ifstream hFile_dare("dares.txt", ios::in);
				char z;
				if (!hFile_dare) {
  		      		cout << "Failed to open the file.";
      			  	return;
  				}
				
				switch(choice){
					case 1:
						hFile_dare.clear();
   					    hFile_dare.seekg(0);
						while(hFile_dare.get(z)){
							if(z==49){
								string temp;
              					getline(hFile_dare,temp,'.');
                				cout<<temp<<"\n\n\n\t\t\t\t\t\t";
                				system("pause");
            	    			break;
							}
						}
						break;
					
					case 2:
						hFile_dare.clear();
   					    hFile_dare.seekg(0);
						while(hFile_dare.get(z)){
							if(z==50){
								string temp;
              					getline(hFile_dare,temp,'.');
                				cout<<temp<<"\n\n\n\t\t\t\t\t\t";
            	    			system("pause");
        	        			break;
							}
						}
						break;
				
					case 3:
						hFile_dare.clear();
   					    hFile_dare.seekg(0);
						while(hFile_dare.get(z)){
							if(z==51){
								string temp;
              					getline(hFile_dare,temp,'.');
                				cout<<temp<<"\n\n\n\t\t\t\t\t\t";
            	    			system("pause");
        	        			break;
							}
						}
						break;	
			
					case 4:
						hFile_dare.clear();
   					    hFile_dare.seekg(0);
						while(hFile_dare.get(z)){
							if(z==52){
								string temp;
            	  				getline(hFile_dare,temp,'.');
        	        			cout<<temp<<"\n\n\n\t\t\t\t\t\t";
    	            			system("pause");
	                			break;
							}
						}
						break;
						
					case 5:
						hFile_dare.clear();
   				    	hFile_dare.seekg(0);
						while(hFile_dare.get(z)){
							if(z==53){
								string temp;
    	          				getline(hFile_dare,temp,'.');
	                			cout<<temp<<"\n\n\n\t\t\t\t\t\t";
                				system("pause");
                				break;
							}
						}
						break;
						
					default:
						cout<<"\n\n\nWrong number entered! Sorry, but you just lost your chance to select the dare!\n\n\n\t\t\t\t\t\t";
						break;	
				}
				hFile_dare.close();
			}
		}
};