#include "Usuario.h"

Usuario::Usuario(string name, string user, string pass){
	this->user = user;
	nombre = name;
	password = pass;
}


string Usuario::getUser(){
	return this->user;
}

string Usuario::getPassword(){
	return this->password;
}

string Usuario::getNombre(){
	return this->nombre;
}
void Usuario::addPost(Post* post){
	posts.push_back(post);
	
}
void Usuario::addFollowing(Usuario* usuario){
	following.push_back(usuario);
}
vector<Post*> Usuario::getPosts(){
	return posts;
}
vector<Usuario*> Usuario::getFollowing(){
	return following;
}
void Usuario::deleteFollowing(int num){
	following.erase(following.begin() + num);
}


Usuario::~Usuario(){
	
}
