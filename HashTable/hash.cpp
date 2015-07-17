#include "hash.h"

using namespace std;

hash::hash(){

	for(int i=0;i<tableSize;i++){

		HashTable[i] = new item;
		HashTable[i]->pos = '';
		HashTable[i]->id  = 0;
		HashTable[i]->posScore = 0.0;
		HashTable[i]->negScore = 0.0;
		HashTable[i]->word = "empty";
		HashTable[i]->next=NULL;
	}
}

void hash::addItem(char pos,long id,double posScore,double negScore,string word){

	int index = Hash(word);

	if(HashTable[index]->word == "empty"){
		
		HashTable[index]->pos = pos;
		HashTable[index]->id  = id;
		HashTable[index]->posScore = posScore;
		HashTable[index]->negScore = negScore;
		HashTable[index]->word = word;
	
	}
	else{

		item* Ptr = HashTable[index];
		item* newPtr = new item;
		newPtr->pos = pos;
		newPtr->id = id;
		newPtr->posScore = posScore;
		newPtr->negScore = negScore;
		newPtr->word = word;
		newPtr->next = NULL;

		while(Ptr->next != NULL){
			Ptr=Ptr->next;
		}
		Ptr->next=newPtr;

	}
}

int hash::numberOfItemsInIndex(int index){

	int count=0;
	
	if(HashTable[index]->word == "empty"){

		return count;
	}
	else{

		count++;
		item* Ptr = HashTable[index];

		while(Ptr->next != NULL){

			count++;
			Ptr = Ptr->next;
		}
		return count;
	}

}

void hash::printTable(){

	int number;
	for(int i=0;i<tableSize;i++){

		number = numberOfItemsInIndex(i);
		cout<<"-------------------\n";
		cout<< "index = "<< i <<endl;
		cout<< HashTable[i]->pos<<"  ";
		cout<< HashTable[i]->id<<"  ";
		cout<< HashTable[i]->posScore<<"  ";
		cout<< HashTable[i]->negScore<<"  ";
		cout<< HashTable[i]->word<<endl;
		cout<< "# of items = "<<number<<endl;
	}
}

void hash::printItemsInIndex(int index){

	item* Ptr = HashTable[index];

	if(Ptr->word == "empty"){

		cout<<" index = "<< index << "is empty"<<endl;
	}
	else{

		cout<<"index "<<index<<" contains the following items"<<endl;

		while(Ptr != NULL){

			cout<<"--------------------\n";
			cout<<Ptr->pos<<endl;
			cout<<Ptr->id<<endl;
			cout<<Ptr->posScore<<endl;
			cout<<Ptr->negScore<<endl;
			cout<<Ptr->word<<endl;
			cout<<"--------------------\n";
			Ptr=Ptr->next;

		}
	}
}

item hash::findWord(string word){

	int index = Hash(word); //discovering the bucket
	bool foundWord = false;
	item temp;

	item* Ptr = HashTable[index];
	while(Ptr != NULL){

		if(Ptr->word == word){

			foundWord = true;
			temp = *Ptr;
		}
		Ptr=Ptr->next;
	}
	if(foundWord == true){

		cout<<"found = "<<word<<endl;
	}
	else{

		cout<<word<<"'s info was not found in the hashtable \n";
	}

}
int hash::Hash(string key){

	int hash = 0;
	int index;

	for(int i=0;i<key.length();i++){

		hash=hash+(int)key[i];		//adding up the ascii values of all characters in the string
	}

	index = hash % tableSize;




	return index;
}