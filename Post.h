#ifndef POST_H
#define POST_H
#include <vector>
#include <string>
#include <bits/stdc++.h>
using namespace std;

class Post
{
	public:
		Post();
		
		
		
		~Post();
	protected:
		int likes;
		int hates;
		vector<string> comentarios;
};

#endif
