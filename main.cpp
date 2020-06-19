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
				
				break;//brake case1
			}//fin case1
			case 2:{//crear usuario
				string nombre, contrasena, usuario;
				cout<<"Buen día, ingrese su nombre: ";
				cin>>nombre;
				
				
				cout<<"Ingrese el usuario que lo distingara en la red social: ";
				cin>>usuario;
				int cambiaruser =0;
				for(int i = 0; i < usuarios.size(); i++){
					if( usuario == usuarios[i]->getUser() ){//FALTA AGREGAR GET USUARIO
						cambiaruser = 1;
					}
				}
				while(cambiaruser== 1){
					cout<<"Ese usuario ya existe, ingre otro usuario que lo distingara en la red social: ";
					cin>>usuario;
					for(int i = 0; i < usuarios.size(); i++){
						if( usuario == usuarios[i]->getUser() ){//FALTA AGREGAR GET USUARIO
							cambiaruser = 1;
						}else if( usuario != usuarios[i]->getUser() && i == (usuarios.size()-1) ){
							cambiaruser = 0;
						}
					}
				}
				break;//break de case2
			}//fin case 2
			case 3:{//salir
				seguir=0;
				cout<<"Gracias por usar nuestra aplicacion, que tenga un buen dia.";
				break;//break case3
			}//fin case3
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


