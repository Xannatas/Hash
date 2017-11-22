#include <iostream>
#include <fstream>
#include "Hash.h"
#include <cstring>
#include <vector>
#include <algorithm>

/* Allison Collier && Isaiah Banta */

/*
Our above and beyond is our grid for the stats of our Hash, which are displayed with formatting 
within main upon each start of the program.

We also include a feature which strips spaces from the user input, since it is assumed that this is
a word-check, and we do not have to account for sentences, etc.
*/

using namespace std;

void altSpellings(const string &s, vector<string>& a);
 
void altSpellings(const string &s, vector<string>& a) {
 string alphabet("abcdefghijklmnopqrstuvwxyz");
 string s2=s;
 string c;

 //convert to lower case
 transform(s2.begin(),s2.end(),s2.begin(),::tolower);
 //insert char between s[0] and s[1]
 for(int i=0;i<=s2.size();i++) {
  for(int j=0;j<alphabet.size();j++) {
   c=s2;
   c.insert(i,1,alphabet[j]);
   a.push_back(c);
  }
 }
 //Deleting a character that is added in uneccesarily
 for(int k=0;k<s2.size();k++) {
  c=s2;
  c.erase(k,1);
  a.push_back(c);
 }
 //for two characters that have bee swapped
 for(int l=0;l<s2.size()-1;l++) {
  c=s2;
  swap(c[l],c[l+1]);
  a.push_back(c);
 }
 //changing an inocrrect character to a correct one
 for(int m=0;m<s2.size();m++) {
  for(int n=0;n<alphabet.size();n++) {
   c=s2;
   c[m]=alphabet[n];
   a.push_back(c); 
  }
 }
}

int main() {
 string s;
 float av_len = 0;
 int occ_chains = 0;
 float frac_occ_chains = 0;
 Hash h(198347);
 // Open dictionary file and put all lines into a vector
 ifstream dictionary("C:/Users/banta/coding/cs_270/H08/american-english");
 vector<string> word;
 string line;
 for(int k=0;k<99171;k++) {
  getline(dictionary,line);
  word.push_back(line);
 }
 //get rid of empty last entry
 word.pop_back(); 
 //close dictionary
 dictionary.close();
  
 for(int i=0;i<word.size();i++) {
  h.insert(word[i]);
 }
 h.chain_stats();
 occ_chains = h.one_sets() + h.two_sets() + h.three_sets() + h.four_sets() + h.five_sets() + h.six_sets();
 cout << occ_chains << endl;
 av_len = 99171/((h.one_sets()) + 2*(h.two_sets()) + 3*(h.three_sets()) + 4*(h.four_sets()) + 5*(h.five_sets()) + 6*(h.six_sets()));
 frac_occ_chains = occ_chains/198347;
 cout << frac_occ_chains << endl;
 cout << "  ____________________________  " <<endl;
 cout << "|| For a hash of size 198,347 ||" << endl;
 cout << "||____________________________||" << endl;
 cout << "||                            ||" << endl;
 cout << "|| Elements____||___Collisions||" << endl;
 cout << "|| 99,171  ____||____  " << h.collisions() << "  ||" << endl;
 cout << "||____________________________||" << endl;
 cout << "|| Emptys  ____||Largest chain||" << endl;
 cout << "|| "<<h.emptys() <<"  ____"<<"||"<< h.big_chain() << " @ index ["<< h.big_index()<<"]" << "||"<<endl;
 cout << "||____________________________||"<<endl;
 cout << "|| Sets with chain length...  ||" << endl;
 cout << "|| 1:  " << h.one_sets() << "                  ||"<< endl;
 cout << "|| 2:  " << h.two_sets() << "                  ||"<<endl;
 cout << "|| 3:  " << h.three_sets() << "                   ||"<<endl;
 cout << "|| 4:  " << h.four_sets() << "                    ||"<<endl;
 cout << "|| 5:  " << h.five_sets() << "                     ||"<<endl;
 cout << "|| 6:  " << h.six_sets() << "                      ||"<<endl;
 cout << "|| Average chain length: " << av_len << "    ||"<< endl;
 cout << "|| Fraction of occupied chians: " << frac_occ_chains << "    ||" << endl; 
 cout << "||____________________________||"<<endl;
 

 while(true) {
  int count =0;
  vector<string> a;
  vector<string> b;
  cout << "\nWord: ";
  if (cin.peek() == '\n') {break;}
  getline(cin,s);
  transform(s.begin(),s.end(),s.begin(),::tolower);
  for(int x=0;x<s.size();x++){
  	if(s[x]==32){
  		s.erase(s.begin()+x);
	  }
  }
  if(h.find(s)==false) {
   altSpellings(s,a);
   for(std::vector<string>::iterator it = a.begin(); it !=a.end();++it) {
    if(h.find(a.at(count))){
     if(find(b.begin(),b.end(),a.at(count))==b.end()) {
      b.push_back(a.at(count));
     }
    }
    count+=1;
   }
   if (b.size()>0) {
    cout << "(incorrect, alts): ";
    for(int i=0; i<b.size();i++) {
      cout <<b.at(i);
       if(i<b.size()-1) {cout<<", ";}
       else {cout <<endl;}
    }
   } 
  else {cout << "(not in dict, no alts)"<<endl;}
  }
  else {cout <<"(Correct)"<<endl;}
 }
 return 0;
}

