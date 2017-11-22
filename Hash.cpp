#include <iostream>
#include <set>
#include "Hash.h"

using namespace std;


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

Hash::~Hash() {
 delete [] a;
}

void Hash::insert(string e) {
 Size+=1;
 int b = 47;
 unsigned int l = e[0];
 for(int i=1;i<e.length();i++) {
  l = b*l+e[i];
 }
 l=l%totalSize;
 if (!a[l].empty()) {
  Collisions+=1;
 }
 a[l].insert(e);
}

int Hash::size() const{
 return Size;
}

int Hash::collisions() const {
 return Collisions;
}

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

int Hash::emptys() {
 int empty = 0;
 for(int i=0;i<totalSize;i++) {
  if (a[i].empty() == true) {empty+=1;}
 } 
 return empty;
}

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

int Hash::big_index() const {
	return Big_index;
}

int Hash::one_sets() const{
 return One_sets;
 }
 
int Hash::two_sets() const{
 return Two_sets;
}

int Hash::three_sets() const{
 return Three_sets;
}

int Hash::four_sets() const{
 return Four_sets;
}

int Hash::five_sets() const{
 return Five_sets;
}

int Hash::six_sets() const{
 return Six_sets;
}

