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
#include "Comment.h"
#include "Archivo.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int menu1();
int menu2(string nom){
	int retValue=0;
	while(retValue < 1 || retValue > 7){
		cout<<"		Bienvenido		"<<nom<<endl
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
	cout<<"******NOTA IMPORTANTE, SOLO SE GUARDA EN LOS ARCHIVOS CUANDO DA ALGUNA OPCION DE SALIR***********"<<endl<<endl;
	Archivo* Ausuarios = new Archivo("Usuarios.txt");
//	Ausuarios->abrirEscritura();
//	Ausuarios->cerrarEscritura();
	vector<Usuario*> usuarios = Ausuarios->extraerArchivo();
	
	int  opcion = menu1();
	int seguir = 1;
	
	while(seguir == 1){
		switch(opcion){
			case 1:{//el mero log in
				bool Ingresado = false;
				int numIngresado;
				string LIuser, LIpass;
				cout<<"Ingrese su usuario: ";
				cin>>LIuser;
				cout<<"Ingrese su contraseña: ";
				cin>>LIpass;
				for(int i = 0; i < usuarios.size(); i++){
					
					if( LIuser == usuarios[i]->getUser() ){
						
						if( LIpass == usuarios[i]->getPassword() ){
							Ingresado = true;
							numIngresado= i;
							break;
						}else if( LIpass != usuarios[i]->getPassword() && i == (usuarios.size()-1) ){
							cout<<"Contraseña o usuario incorrecto.";
							break;
						}
						
					}else if( LIuser != usuarios[i]->getUser() && i == (usuarios.size()-1) ){
						cout<<"Contraseña o usuario incorrecto.";
					}
				}//fin del for para chequear el log in
				
				cout<<endl<<"****FEED*****"<<endl;
				for(int i = 0; i < usuarios[numIngresado]->getPosts().size() ; i++){//for para imprimir los post del usuario en log in
					
					string name;
					for(int j = 0; j < usuarios.size() ; j++){//for para agarrar el nombre del creador
						if(usuarios[j]->getUser() == 
							usuarios[numIngresado]->getPosts()[i]->getCreador()){
							cout<<endl<<"______________________________________________________________________________"<<endl;
							name = usuarios[i]->getNombre();
							cout<<i<<") "<<name<<endl<<usuarios[numIngresado]->getPosts()[i]->getContenido()<<endl;
							cout<<"______________________________________________________________________________"<<endl<<endl;
							break;
						}
					}//fin for para agarrar el nombre del creador
				}//fin for para imprimir los post del usuario en log in
				
				while(Ingresado){//while log in
					int  opcion2 = menu2(usuarios[numIngresado]->getNombre());
					switch(opcion2){
						case 1:{//crear post
							string contenido;
							cout<<"Cual va ser el contenido de su post: ";
							getline(cin, contenido);
							
							usuarios[numIngresado]->addPost(new Post(usuarios[numIngresado]->getUser(), contenido) );
							break;//break case1
						}//fin case1
						
						case 2:{//comentar post
							for(int i = 0; i < usuarios[numIngresado]->getPosts().size() ; i++){//for para imprimir los post del usuario en log in
								
								string name;
								for(int j = 0; j < usuarios.size() ; j++){//for para agarrar el nombre del creador
									if(usuarios[j]->getUser() == 
											usuarios[numIngresado]->getPosts()[i]->getCreador()){
										cout<<endl<<"______________________________________________________________________________"<<endl;
										name = usuarios[i]->getNombre();
										cout<<i<<") "<<name<<endl<<usuarios[numIngresado]->getPosts()[i]->getContenido()<<endl;
										cout<<"______________________________________________________________________________"<<endl;
										break;
									}
								}//fin for para agarrar el nombre del creador
							}//fin for para imprimir los post del usuario en log in
							
							int postSelect;
							cout<<endl<<"Ingrese el numero del post que desea comentar: ";
							cin>>postSelect;
							
							while( postSelect<0 || postSelect>usuarios[numIngresado]->getPosts().size() ){
								cout<<endl<<"Numero ingresado fuera de rango, Ingreselo de nuevo: ";
								cin>>postSelect;
							}
							
							string comentario;
							cout<<"Que quiere comentar en este post: "<<endl;
							getline(cin, comentario);
							
							usuarios[numIngresado]->getPosts()[postSelect]->addComment(new Comment
								(usuarios[numIngresado]->getUser(), comentario) );
							break;//break case2
						}//fin case2
						
						case 3:{//dar like
							for(int i = 0; i < usuarios[numIngresado]->getPosts().size() ; i++){//for para imprimir los post del usuario en log in
								
								string name;
								for(int j = 0; j < usuarios.size() ; j++){//for para agarrar el nombre del creador
									if(usuarios[j]->getUser() == 
											usuarios[numIngresado]->getPosts()[i]->getCreador()){
										cout<<endl<<"______________________________________________________________________________"<<endl;
										name = usuarios[i]->getNombre();
										cout<<i<<") "<<name<<endl<<usuarios[numIngresado]->getPosts()[i]->getContenido()<<endl;
										cout<<"______________________________________________________________________________"<<endl;
										break;
									}
								}//fin for para agarrar el nombre del creador
							}//fin for para imprimir los post del usuario en log in
							
							int postSelect;
							cout<<endl<<"Ingrese el numero del post que desea darle like: ";
							cin>>postSelect;
							
							while( postSelect<0 || postSelect>(usuarios[numIngresado]->getPosts().size()-1) ){
								cout<<endl<<"Numero ingresado fuera de rango, Ingreselo de nuevo: ";
								cin>>postSelect;
							}
							
							usuarios[numIngresado]->getPosts()[postSelect]->sumLike();
							break;//break case3
						}//fin case3
						
						case 4:{//dar hate
							for(int i = 0; i < usuarios[numIngresado]->getPosts().size() ; i++){//for para imprimir los post del usuario en log in
								
								string name;
								for(int j = 0; j < usuarios.size() ; j++){//for para agarrar el nombre del creador
									if(usuarios[j]->getUser() == 
											usuarios[numIngresado]->getPosts()[i]->getCreador()){
										cout<<endl<<"______________________________________________________________________________"<<endl;
										name = usuarios[i]->getNombre();
										cout<<i<<") "<<name<<endl<<usuarios[numIngresado]->getPosts()[i]->getContenido()<<endl;
										cout<<"______________________________________________________________________________"<<endl;
										break;
									}
								}//fin for para agarrar el nombre del creador
							}//fin for para imprimir los post del usuario en log in
							
							int postSelect;
							cout<<endl<<"Ingrese el numero del post que desea darle Hate: ";
							cin>>postSelect;
							
							while( postSelect<0 || postSelect>(usuarios[numIngresado]->getPosts().size()-1) && postSelect != numIngresado){
								cout<<endl<<"Numero ingresado fuera de rango, Ingreselo de nuevo: ";
								cin>>postSelect;
							}
							
							usuarios[numIngresado]->getPosts()[postSelect]->sumHate();
							break;//break case4
						}//fin case4
						
						case 5:{//follow
							cout<<endl<<"______________________________________________________________________________"<<endl;
							for(int i = 0; i < usuarios.size() ; i++){//for para imprimir los usuarios en el sistema
								
								if(usuarios[i]->getUser() != usuarios[numIngresado]->getUser()){
									
									cout<<i<<") "<<usuarios[i]->getNombre()<<endl;
									
									break;
								}
							}//fin for para imprimir los usuarios en el sistema
							cout<<"______________________________________________________________________________"<<endl;
							
							int UserSelect;
							cout<<endl<<"Ingrese el numero del usuario que desea darle unfollow: ";
							cin>>UserSelect;
							
							while( UserSelect<0 || UserSelect>(usuarios.size()-1) ){
								cout<<endl<<"Numero ingresado fuera de rango, Ingreselo de nuevo: ";
								cin>>UserSelect;
							}
							
							usuarios[numIngresado]->addFollowing( usuarios[UserSelect] );
							break;//break case5
						}//fin case5
						
						case 6:{//unfollow
							cout<<endl<<"______________________________________________________________________________"<<endl;
							for(int i = 0; i < usuarios[numIngresado]->getFollowing().size() ; i++){//for para imprimir following
								
								cout<<i<<") "<<usuarios[numIngresado]->getFollowing()[i]->getNombre()<<endl;
									
							}//fin for para imprimir following
							cout<<"______________________________________________________________________________"<<endl;
							
							int UserSelect;
							cout<<endl<<"Ingrese el numero del usuario que desea darle follow: ";
							cin>>UserSelect;
							
							while( UserSelect<0 || UserSelect>(usuarios[numIngresado]->getFollowing().size()-1) ){
								cout<<endl<<"Numero ingresado fuera de rango, Ingreselo de nuevo: ";
								cin>>UserSelect;
							}
							
							usuarios[numIngresado]->deleteFollowing( UserSelect );
							break;//break case6
						}//fin case6
						
						case 7:{//log out
							cout<<"Gracias por usar nuestra aplicacion, que tenga un buen dia.";
							Ingresado = false;
							//aqui se debe cargar archivo
							Ausuarios->abrirEscritura(0);
							for(int i = 0; i < usuarios.size() ; i++){
								Ausuarios->guardarUsuario(usuarios[i]);
							}
							Ausuarios->cerrarEscritura();
							break;//break case7
						}//fin case7
						
					}//fin del switch log in
				}//fin de while log in
				
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
					if( usuario == usuarios[i]->getUser() ){
						cambiaruser = 1;
					}
				}
				while(cambiaruser== 1){
					cout<<"Ese usuario ya existe, ingre otro usuario que lo distingara en la red social: ";
					cin>>usuario;
					for(int i = 0; i < usuarios.size(); i++){
						if( usuario == usuarios[i]->getUser() ){
							cambiaruser = 1;
						}else if( usuario != usuarios[i]->getUser() && i == (usuarios.size()-1) ){
							cambiaruser = 0;
						}
					}
				}
				
				cout<<"Ingrese la contraseña: ";
				cin>>contrasena;
				
				usuarios.push_back( new Usuario(nombre, usuario, contrasena) );
				break;//break de case2
			}//fin case 2
			case 3:{//salir
				seguir=0;
				cout<<"Gracias por usar nuestra aplicacion, que tenga un buen dia.";
				
				//aqui se debe cargar archivo
				Ausuarios->abrirEscritura(0);
				for(int i = 0; i < usuarios.size() ; i++){
					Ausuarios->guardarUsuario(usuarios[i]);
				}
				Ausuarios->cerrarEscritura();
				break;//break case3
			}//fin case3
		}//fin del switch
		
		if(seguir==1){
			int  opcion = menu1();
		}
	}//fin del while
	
	delete Ausuarios;
	for(int i = 0; i < usuarios.size() ; i++){
		delete usuarios[i];
	}
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


