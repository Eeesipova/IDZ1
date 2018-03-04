// employeesudniki.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

using namespace std;
class employees {
	int salary;
	int age;
	char gender;
	char *name[30];
	public:
		employees(){};
		employees(int i,int j,char k, char *n){
		salary=i;
		age=j;
		gender=k;
		*name=n;
		};
		void employees1();
		int get_age() {return age;};
		int get_salary() {return salary;};
		char get_gender() {return gender;};
		char *get_name(){return *name;};
		void setZ(int i,int j, char k, char * n){
		salary=i;
		age=j;
		gender=k;
		*name = n;
		}
};

void Sort(employees *Workers,int N,int q){
	employees k;

	switch (q)
		{
		case 1:
	cout << "List of employees after sorting by age:\n";
	for (int i=0;i<N-1;i++){
	for (int j=0;j<N-1-i;j++)
		if (Workers[j].get_age()>Workers[j+1].get_age()){
			k=Workers[j];
			Workers[j]=Workers[j+1];
			Workers[j+1]=k;
		}
	}break;
		case 2:
			cout << "List of employees after sorting by salary:\n";
			for (int i=0;i<N-1;i++){
	for (int j=0;j<N-1-i;j++)
		if (Workers[j].get_salary()>Workers[j+1].get_salary()){
			k=Workers[j];
			Workers[j]=Workers[j+1];
			Workers[j+1]=k;
		}
	}	break;
		default: cout<<"Error!"<<endl;	break;
		}

	for (int i=0;i<N;i++){ cout<<i+1<<". "<< Workers[i].get_name()<<" "<< Workers[i].get_gender()<<" "<<Workers[i].get_age()<<" "<<Workers[i].get_salary()<<endl;}
}
void Search(employees *Workers,int N,int q){

	if (q==1){
		for(int i=0;i<N;i++){
			if (Workers[i].get_gender()=='m')
				cout<<Workers[i].get_name()<<endl;
				i=N;
							}
	}

		if (q==2){
		for(int i=0;i<N;i++)
			if (Workers[i].get_gender()=='g'){
				cout<<Workers[i].get_name();
				cout<<endl;
				i=N;
			}
		}
		if (q>2) cout <<"Error!"<<endl;

}

int _tmain(int argc, _TCHAR* argv[])
{	
	const int n=5;
	employees workers[n];

	workers[0].setZ(20000,55,'m', "Pasha");
	workers[1].setZ(15000,13,'m', "Misha");
	workers[2].setZ(75800,35,'g',"Masha");
	workers[3].setZ(7800,49,'m',"Dasha");
	workers[4].setZ(95800,19,'g',"Sasha");


	cout << "A list of employees:\n";
	for (int i=0;i<n;i++){ cout<<i+1<<". "<< workers[i].get_name()<<" "<< workers[i].get_gender()<<" "<<workers[i].get_age()<<" "<<workers[i].get_salary()<<endl;}
	employees k,po;
	
		cout<<endl;

		cout << "Which sort do you want to select?:\n";
		cout << "1. Sort by age:\n";
		cout << "2. Sort by salary:\n";

		int q;
		cin>>q;
		Sort(workers,n,q);
			

		cout<<"Who do you want to find"<<endl<<"man or woman"<<endl<<"1 or 2"<<endl;
		cin>>q;
		Search(workers,n,q);
	

	system("pause");
	return 0;
}
