#include <iostream>
#include <string>
#include <set>

using namespace std;

class Hash {

 public:
  
  Hash(int n);
  ~Hash();
  int size() const;
  void insert(string e);
  int collisions() const;
  bool find(string e);
  int emptys();
  void chain_stats();
  int big_chain();
  int one_sets() const;
  int two_sets() const;
  int three_sets() const;
  int four_sets() const;
  int five_sets() const;
  int six_sets() const;  
  int big_index() const;
 
 private:
 
  int Size;
  set<string>* a;
  int totalSize;
  int Collisions;
  int One_sets;
  int Two_sets;
  int Three_sets;
  int Four_sets;
  int Five_sets;
  int Six_sets;
  int biggest_set;
  int Big_index;
};
