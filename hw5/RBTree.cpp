#include <iostream>
#include <string>
#include "RBTree.h"
#include <set>


using namespace std;

RBTree::RBTree(){
	nil = new node;
	nil->color = "black" ;
	nil->parent = nil->right = nil->left = nil;
	nil->key = 0;
	nil->gender = " ";
	nil->height = 0;
	nil->weight = 0;
	nil->next = nil;
	root = nil;
	
}
RBTree::~RBTree(){
	delete root;
	delete nil;
}
bool RBTree::insert(int key, string gender, int height, int weight){
	bool a;
	node *temp = root; 
		while(temp != nil){
		if(temp->key == key && temp->gender == gender && temp->height == height && temp->weight == weight){
			a = false;
			return a;
		}
		else if(temp->key < key){
			temp = temp->right;
		}
		else {
			temp = temp->left;
		}
	}
	temp = root;
	if(search2(key) == true){
		while(temp != nil){
		if(temp->key == key){
			temp = temp->next;
			temp = new node(key, gender, height, weight);
			goto AA;
		}
		else if(temp->key < key){
			temp = temp->right;
		}
		else {
			temp = temp->left;
		}
	}
	AA:
		a = true;
		return a;
	}
	
		
	/*	node *temp2 = new node(key, gender, height, weight);
		while(temp->key != key){
			
			 if(temp->key < key){
				temp = temp->right;
			}
			else {
			temp = temp->left;
			}
		}
	
		while(temp->gender != temp2->gender ||temp->height != temp2->height || temp->weight != temp2->weight){
			temp = temp->next;
		}
			if(temp->gender == temp2->gender && temp->height == temp2->height && temp->weight == temp2->weight){
				*/
		//	}
		/*node *temp = root;
		node *temp2 = new node(key, gender, height, weight);
	while(temp != nil){
		if(temp->key == key && temp->gender == gender && temp->height == height &&temp->weight == weight){
			temp2 = temp->next;
			temp2->num++;
			goto AA;*/
	
		
	
		a = true;
	
	node *y = nil;
	node *x = root;
	node *n = new node(key, gender, height, weight);
	

	while(x != nil){
		y = x;
		if(key < x->key){
			x = x->left;
		}
		else {
			x = x->right;
		}
	}
	
	n->parent = y;
	if(y == nil){
		root = n;
	}
	else if(key < y->key){
		y->left = n;
	}
	else {
		y->right = n;
	}
	
	n->left = nil;
	n->right = nil;
	n->color = "red";
	
	
	fix(n);
	
	return a;
}

void RBTree::fix(node *cur){
	while(cur->parent->color == "red"){
		if (cur->parent == cur->parent->parent->left){
			node *uncle = cur->parent->parent->right;
			if (uncle->color == "red") {
                cur->parent->color = "black";
                uncle->color = "black";
                cur->parent->parent->color = "red";             
                cur = cur->parent->parent;
            }
            else {
            	if (cur == cur->parent->right){     // case2
                    cur = cur->parent;
                    leftrotation(cur);
                }
                
                cur->parent->color = "black";                      
                cur->parent->parent->color = "red";            
                rightrotation(cur->parent->parent);
            }
		}
		
		else {
			node *uncle = cur->parent->parent->left;
			
			if (uncle->color == "red") {
                cur->parent->color = "black";
                uncle->color = "black";
                cur->parent->parent->color = "red";              
                cur = cur->parent->parent;
            }
            else {
            	if (cur == cur->parent->left) {    
                    cur = cur->parent;
                    rightrotation(cur);
                }
                cur->parent->color = "black";
                cur->parent->parent->color = "red";
                leftrotation(cur->parent->parent);
			}
		}
	}
	root->color = "black";
}

void RBTree::leftrotation(node *x){
	node *y = x->right;
	x->right = y->left;
	
	if (y->left != nil){          
        y->left->parent = x;
    }
    
    y->parent = x->parent; 
     
    if (x->parent == nil){              
        root = y;          
    }  
    else if (x == x->parent->left){ 
        x->parent->left = y;        
    }
    else{                                
        x->parent->right = y;       
    }
    y->left = x;                    
    x->parent = y; 
}

void RBTree::rightrotation(node *y){
	node *x = y->left;           

    y->left = x->right;         
    if (x->right != nil){          
        x->right->parent = y;
    }
    x->parent = y->parent;               
    if (y->parent == nil){            
        root = x;          
    }              
    else if (y == y->parent->left){  
        y->parent->left = x;        
    }
    else{                                
        y->parent->right = x;       
    }
    x->right = y;                 
    y->parent = x;  
}

node RBTree::operator[](int key){
	node *temp = root;
	while(temp != nil){
		if(temp->key == key){
			return *temp;
		}
		else if(temp->key < key){
			temp = temp->right;
		}
		else {
			temp = temp->left;
		}
	}
	return *nil;
}

bool RBTree::search(int key,string gender, int height, int weight){
	node *temp = root;
	
	while(temp != nil){
		if(temp->key == key && temp->gender == gender && temp->height == height && temp->weight == weight){
		
			return true;
		}
		
		else if(temp->key < key){
			temp = temp->right;
		}
		else {
			temp = temp->left;
		}
	}
	return false;
}
 
bool RBTree::search2(int key){
	node *temp = root;
	
	while(temp != nil){
		if(temp->key == key ){
		
			return true;
		}
		
		else if(temp->key < key){
			temp = temp->right;
		}
		else {
			temp = temp->left;
		}
	}
	return false;
}
 


