#ifndef COMMENT_H
#define COMMENT_H
#include <vector>
#include <string>
#include <bits/stdc++.h>
using namespace std;

class Comment
{
	public:
		Comment(string, string);
		
		string getComUser();
		string getComment();
		
		~Comment();
	protected:
		string user;
		string contenido;
};

#endif
