#include "Archivo.h"

Archivo::Archivo(string pFileName){
	fileName = pFileName;
}
bool Archivo::guardarUsuario(Usuario* usuario){
	if(outputFile.is_open()){
		
		outputFile << usuario->nombre << "," << usuario->user << "," << usuario->password<<endl;
		return true;
	}else
		return false;
}



bool Archivo::cerrarEscritura(){
	outputFile.close();
	return !outputFile.is_open();
}

bool Archivo::abrirEscritura(int modo){
	modoEscritura = modo;
	if(modoEscritura == 1){
		outputFile.open(fileName.c_str(), std::ios::app);
		inputFile.open(fileName.c_str(), std::ios::app);
	}
	else{
		outputFile.open(fileName.c_str());
		inputFile.open(fileName.c_str());
	}
			
			
	return outputFile.is_open();
}

vector<Usuario*> Archivo::extraerArchivo(){
	vector<Usuario*> retvalue;
	if(inputFile.is_open()){
		while(!inputFile.eof()){
			stringstream myStream;
			string buffer;
			string nombre;
			string user;
			string password;
			getline(inputFile,buffer);
			myStream << buffer;
			
			getline(myStream,nombre,',');
			getline(myStream,user,',');
			getline(myStream,password,',');
			
			retvalue.push_back(new Usuario(nombre, user, password));
		}
	}
	
	return retvalue;
}
