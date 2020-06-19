#ifndef ARCHIVO_H
#define ARCHIVO_H
#include <vector>
#include <string>
#include <bits/stdc++.h>
#include <string>
using std::string;
#include <fstream>
using std::ofstream;
using std::ifstream;
using namespace std;

#include "Usuario.h"
#include "Post.h"
#include "Comment.h"

class Archivo
{
	public:
		Archivo(string);
		
		bool guardarUsuario(Usuario*);
		bool abrirEscritura(int);
		bool cerrarEscritura();
		
		vector<Usuario*> extraerArchivo();
		
		
	protected:
		string fileName;
		ofstream outputFile;
		int modoEscritura;
		ifstream inputFile;
};

#endif
