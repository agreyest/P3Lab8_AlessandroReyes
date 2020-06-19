#include "Comment.h"

Comment::Comment(string user, string content){
	this->user = user;
	contenido = content;
}


string Comment::getComUser(){
	return user;
}
string Comment::getComment(){
	return contenido;
}

Comment::~Comment(){
	
}
