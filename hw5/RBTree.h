#ifndef RBTREE_H
#define RBTREE_H
#include <iostream>
#include <string>
#include <set>
#include <utility>
#include <fstream>
using namespace std;

class RBTree;
class node{
	private:
		string gender;
		int key, height, weight;
		string color;
		node *right;
		node *left;
		node *parent;
		node *next;
		
	public:
		node():left(0),right(0),parent(0),key(0),gender(""),height(0),weight(0){};
		node(int a, string b, int c, int d):left(0),right(0),parent(0),key(a),gender(b),height(c),
		weight(d){};
		int getKey(){
			return key;
		}
		string getGender(){
			return gender;
		}
		int getHeight(){
			return height;
		}
		int getWeight(){
			return weight;
		}
	friend class RBTree;
};
	
class RBTree{
	
	private:
		node *root;
		node *nil;
	
	
	public:
			
		RBTree();
		~RBTree(); 
		bool insert(int key, string gender, int height, int weight);
		node operator[](int key);
		
		void fix(node *cur);
		void leftrotation(node *x);	
		void rightrotation(node *y);
		bool search(int key, string gender, int height, int weight);
		bool search2(int key);
};
#endif
