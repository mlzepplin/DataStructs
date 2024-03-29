#include <cstdlib>
#include <iostream>
#include <string>

using namespace std;

#ifndef HASH_H
#define HASH_H

class hash{
private:
	static const int tableSize = 30; //number of buckets

	struct item{
		char pos;
		long id;
		double posScore;
		double negScore;
		string word;
		item* next;
	};

	item* HashTable[tableSize];

public:
	hash();
	int Hash(string key);
	void addItem(char pos,long id,double posScore,double negScore,string word);
	int numberOfItemsInIndex(int index); //to get number of items in a bucket
	void printTable();//just a helper function ,will tell info in each of the first items
						//and will also tell the number of elements in each bucket
	void printItemsInIndex(int index);
	item findWord(string word);
	//void removeItem(string name); CODE IF NEEDED


};

#endif