#ifndef HASHTABLE_H
#define HASHTABLE_H
#include <iostream>
#include <string>

using namespace std;
struct item
	{
		string key,gender;
		int height,weight;
	
		item *next;

		string getGender(){
			return gender;
		}
		
		int getHeight(){
			return height;
		}
		int getWeight(){
			return weight;
		}	
	};

	
class HashTable{
	
	
	private:
		static const int size=10000;
		item *Hash[size];
	
	public:
	
	HashTable();
	~HashTable();
	
	void addItem(string key,string gender,int height ,int weight);
	item  operator [] (string key);
	//string getGender();
	//int getHeight();
	//int getWeight();
	int aaa(string key);
	unsigned int Hashfunction(string key);
};
#endif
 
