#include <iostream>
#include <set>
#include "Hash.h"

using namespace std;

//Constructor.
//Initialize our Hash, size, and int values for collisions, and sets of collisions. All to 0.
Hash::Hash(int n) {
 Size=0;
 totalSize = n;
 a = new set<string>[n];
 Collisions=0;
 One_sets = 0;
 Two_sets = 0;
 Three_sets = 0;
 Four_sets = 0;
 Five_sets = 0;
 Six_sets = 0;
 Big_index = 0;
}

//Destructor.
//Deletes the array.
Hash::~Hash() {
 delete [] a;
}

//Inserts the string into the hash using the hash function, by using the ord() of the string indices.
void Hash::insert(string e) {
 Size+=1;
 int b = 47;	//Prime number used as part of our Hash function
 unsigned int l = e[0];
 for(int i=1;i<e.length();i++) {
  l = b*l+e[i];	//Hash function 
 }
 l=l%totalSize;
 if (!a[l].empty()) { 	//If the container is not empty, then there is a collision
  Collisions+=1;
 }
 a[l].insert(e);	//Otherwise, simply insert into the container
}

//Returns the size of the Hash.
int Hash::size() const{
 return Size;
}

//Returns number of collisions.
int Hash::collisions() const {
 return Collisions;
}

//Finds the values in our Hash.
bool Hash::find(string e) {
 int b = 47;
 unsigned int l = e[0];
 for(int i=1;i<e.length();i++) {
  l = b*l+e[i];
 }
 l=l%totalSize;
 if (a[l].empty() == true) {return false;}
 else {
  if (a[l].find(e) != a[l].end()) {return true;}
  else {return false;}
 }
}

//Returns the number of empty containers.
int Hash::emptys() {
 int empty = 0;
 for(int i=0;i<totalSize;i++) {
  if (a[i].empty() == true) {empty+=1;}
 } 
 return empty;
}

//Tracks number of various chain lengths.
void Hash::chain_stats() {
 for(int i=0;i<totalSize;i++) {
  if(a[i].size() == 1){
  	One_sets +=1;
  }
  if(a[i].size() == 2){
   Two_sets += 1;
  } 
  else if(a[i].size() == 3) {
   Three_sets += 1;
  }
  else if(a[i].size() == 4) {
   Four_sets += 1;
  }
  else if(a[i].size() == 5) {
   Five_sets += 1;
  }
  else if(a[i].size() ==6) {
   Six_sets += 1;
  }
 }
}

//Returns the integer length of the largest chain collision.
int Hash::big_chain() {
 biggest_set = 0;
 for(int i=0;i<totalSize;i++) {
  if(biggest_set<a[i].size()) {
   biggest_set = a[i].size();
   Big_index = i;
  }
}
return biggest_set;
}

//Returns the index of the largest chain collision.
int Hash::big_index() const {
	return Big_index;
}

//Returns the number of containers with one item.
int Hash::one_sets() const{
 return One_sets;
 }

//Returns the number of containers with two items.
int Hash::two_sets() const{
 return Two_sets;
}

//Returns the number of containers with three items.
int Hash::three_sets() const{
 return Three_sets;
}

//Returns the number of containers with four items.
int Hash::four_sets() const{
 return Four_sets;
}

//Returns the number of containers with five items.
int Hash::five_sets() const{
 return Five_sets;
}

//Returns the number of containers with six items.
int Hash::six_sets() const{
 return Six_sets;
}
