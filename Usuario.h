#ifndef USUARIO_H
#define USUARIO_H
#include <vector>
#include <string>
#include <bits/stdc++.h>
using namespace std;

#include "Post.h"

class Usuario{
	public:
		Usuario(string, string, string);
		
		string getUser();
		string getPassword();
		string getNombre();
		void addPost(Post*);
		void addFollowing(Usuario*);
		vector<Post*> getPosts();
		vector<Usuario*> getFollowing();
		void deleteFollowing(int);
		
		~Usuario();
	protected:
		string nombre;
		string password;
		string user;
		vector<Post*> posts;
		vector<Usuario*> following;
};

#endif
