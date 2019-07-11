#include <cstdlib>
#include <iostream>
#include <string>
#include<sstream>
#include <math.h>
#include "0616027_HashTable.h"

using namespace std;

HashTable::HashTable(){

	for(int i=0 ; i<size ; i++){
		Hash[i] = new item;
		Hash[i]-> key ="empty";
		Hash[i]-> gender ="empty";
		Hash[i]-> height =0;
		Hash[i]-> weight =0;
		Hash[i]-> next =NULL;
	}
	
}

HashTable::~HashTable(){
	
}
int HashTable::aaa(string key){
	int index;
	int add;
	istringstream is(key);
	is>>add;
	
	index = add % 10000;
	return index;
}
unsigned int HashTable::Hashfunction(string k){
	/*float A = (sqrt(5)-1)/2;
	int m=pow(2,13);
	int index;
	int add;
	istringstream is(k);
	is>>add;
	int C=add*A;
	float B=add*A;
	float f=B-C;
	int mf=m*f;
	
	index = mf;*/
	
	int index;
	int add;
	istringstream is(k);
	is>>add;
	
	index = add % 10000;
	return index;
}

void  HashTable::addItem(string key,string gender,int height ,int weight){
	int index=Hashfunction(key);
	if(Hash[index]->key=="empty"){
		Hash[index]->key=key;
		Hash[index]->gender=gender;
		Hash[index]->height=height;
		Hash[index]->weight=weight;
	}
	else{
		item* P = Hash[index];
		item* N = new item;
		N->key=key;
		N->gender=gender;
		N->height=height;
		N->weight=weight;
		N->next=NULL;
		while(P->next != NULL){
			P=P->next;
		}
		P->next = N;
	}
	
}

item   HashTable :: operator [] (string key){
	int index = Hashfunction(key);
	item *Pt = Hash[index];
	while(Pt->key != key){
		Pt = Pt->next;
	}
	
	

	return 	*Pt;

}

