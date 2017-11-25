#include <iostream>
#include <string>
#include <set>

using namespace std;

class Hash {

 public:
  
  //Constructor, take int arg.
  Hash(int n);
  
  //Destructor.
  ~Hash();
 
  //Returns the size of our Hash.
  int size() const;
 
  //Inserts given string into Hash.
  void insert(string e);
 
  //Returns the number of collisions resulted from our Hash function.
  int collisions() const;
 
  //Returns true if the given string is in the Hash, false otherwise.
  bool find(string e);
 
  //Returns the number of empty containers in our Hash.
  int emptys();
 
  //Tracks our collision chain lengths of various sizes.
  void chain_stats();
 
  //Returns the length of our largest collision chain.
  int big_chain();
  
  //Returns number of containers with no collisions.
  int one_sets() const;
 
  //Returns number of containers with one collision. 
  int two_sets() const;
  
  //Returns number of containers with two collisions.
  int three_sets() const;
 
  //Returns number of containers with three collisions.
  int four_sets() const;
 
  //Returns number of containers with four collisions.
  int five_sets() const;
 
  //Returns number of containers with five collisions.
  int six_sets() const;  
 
  //Returns the index of the container with the highest amount of collisions.
  int big_index() const;
 
 private:
  
  //Size. 
  int Size;
  
  //Our hash, implemented with an array of sets, with datatype <string>
  set<string>* a;
 
  //The total size of our Hash
  int totalSize;
 
  //Total number of collisions.
  int Collisions;
 
  //Number of containers with one item.
  int One_sets;
 
  //Number of containers with two items.
  int Two_sets;
 
  //Number of containers with three items.
  int Three_sets;
 
  //Number of containers with four items.
  int Four_sets;
 
  //Number of containers with five items.
  int Five_sets;
 
  //Number of containers with six items.
  int Six_sets;
 
  //The length of the largest collision.
  int biggest_set;
 
  //The index of the largest collision.
  int Big_index;
};
