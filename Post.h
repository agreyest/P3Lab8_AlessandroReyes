#ifndef POST_H
#define POST_H
#include <vector>
#include <string>
#include <bits/stdc++.h>
using namespace std;

class Usuario;
//#include "Usuario.h"

class Post
{
	public:
		Post(Usuario);
		
		
		
		~Post();
	protected:
		int likes;
		int hates;
		vector<string> comentarios;
		Usuario creador;
};

#endif
