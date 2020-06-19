#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <conio.h>
#include <vector>
#include <string>
#include <bits/stdc++.h>
using namespace std;

#include "Usuario.h"
#include "Post.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int menu1();
int menu2(string){
	int retValue=0;
	while(retValue < 1 || retValue > 7){
		cout<<"		Age of Empires		"<<endl
			<<"  1.- Crear post"<<endl
			<<"  2.- Comentar post"<<endl
			<<"  3.- Dar like"<<endl
			<<"  4.- Dar hate"<<endl
			<<"  5.- Seguir usuario"<<endl
			<<"  6.- Dejar de seguir a un usuario"<<endl
			<<"  7.- Log out"<<endl
			<<"Que opcion desea ver: ";
			
			cin>>retValue;
			
			if(retValue >= 1 && retValue <= 7){
				break;
			}else{
				cout<<endl<<"Opcion ingresada incorrecta, elija nuevamente"<<endl;
			}
			
			
	}//end while
	
	return retValue;
}//fin metodo de menu

int main(int argc, char** argv) {
	vector<Usuario*> usuarios;
	int  opcion = menu1();
	int seguir = 1;
	
	while(seguir == 1){
		switch(opcion){
			case 1:{//el mero log in
				
				break;
			}
			case 2:{//crear usuario
				
				break;
			}
			case 3:{//salir
				seguir=0;
				cout<<"Gracias por usar nuestra aplicacion, que tenga un buen dia.";
				break;
			}
		}//fin del switch
		
		if(seguir==1){
			int  opcion = menu1();
		}
	}//fin del while
	
	return 0;
}//fin main


int menu1(){
	int retValue=0;
	while(retValue < 1 || retValue > 3){
		cout<<"		Age of Empires		"<<endl
			<<"  1.- Log in"<<endl
			<<"  2.- Crear cuenta"<<endl
			<<"  3.- salir"<<endl
			<<"Que opcion desea ver: ";
			
			cin>>retValue;
			
			if(retValue >= 1 && retValue <= 3){
				break;
			}else{
				cout<<endl<<"Opcion ingresada incorrecta, elija nuevamente"<<endl;
			}
			
			
	}//end while
	
	return retValue;
}//fin metodo de menu


