#include "Post.h"
//#include "Usuario.h"

Post::Post(string usuario, string content){
	creador = usuario;
	contenido = content;
	likes = 0;
	hates = 0;
	//incializar el vector???
}


string Post::getCreador(){
	return creador;
}
void Post::sumLike(){
	likes++;
}
void Post::sumHate(){
	hates++;
}
void Post::addComment(Comment* comment){
	comentarios.push_back(comment);
}
string Post::getContenido(){
	return contenido;
}


Post::~Post(){
	
}
