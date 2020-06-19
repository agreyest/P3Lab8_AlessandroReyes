#ifndef POST_H
#define POST_H
#include <vector>
#include <string>
#include <bits/stdc++.h>
using namespace std;

#include "Comment.h"

class Post{
	public:
		Post(string, string);
		
		string getCreador();
		void sumLike();
		void sumHate();
		void addComment(Comment*);//para agregar un comentario al post
		string getContenido();
		
		~Post();
	protected:
		int likes;
		int hates;
		string contenido;
		vector <Comment*> comentarios;
		string creador;//usuario del creador
};

#endif
