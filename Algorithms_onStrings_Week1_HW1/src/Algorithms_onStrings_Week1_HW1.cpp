//============================================================================
// Name        : Algorithms_onStrings_Week1_HW1.cpp
// Author      : Daniel Ramirez
// Version     :
// Copyright   : HW1_Week1
// Description : Construct a Trie from a Collection of Patterns
//============================================================================

#include <iostream>
#include <string>
#include <vector>

using namespace std;
using std::vector;
using std::string;

class trieNode{
private:
    char x;
    int index;
    vector<trieNode*> children;
public:
      trieNode();
      trieNode* findNode(char symbol);
      void assignsymbol(char symbol);
      void assignindex(int value);
      void appendChild(trieNode *child);
      char retX();
      int retIndex();
};

trieNode::trieNode(){
  index=0;
}

char trieNode::retX(){
   return x;
}

int trieNode::retIndex(){
   return index;
}

trieNode* trieNode::findNode(char symbol){
    vector<trieNode*>::iterator it;
    for(it=children.begin();it!=children.end();++it){
       if((*it)->x == symbol){
          return *it;
       }
    }
   return NULL;
}

void trieNode::assignsymbol(char symbol){
   x=symbol;
}

void trieNode::assignindex(int value){
	index=value;
}

void trieNode::appendChild(trieNode *child){
	children.push_back(child);
}

class trieTree{
   public:
     trieTree();
     void addTrieNode(vector<string> &patterns);
     int sizeTrie();
     bool findNode(char x);
   private:
     trieNode *root;
     int size;
};

trieTree::trieTree(){
    root=new trieNode();
    size=0;
}

/*
 it_a: iterator for patterns strings
 it_b: iterator for characters in patterns element;
*/
void trieTree::addTrieNode(vector<string> &patterns){
   char currentsymbol;
   vector<string>::iterator it_a;
   string::iterator it_b;
   int indexTrie;
   int numNodes=0;
   trieNode *current=root;

   for(it_a=patterns.begin();it_a!=patterns.end();++it_a){
     indexTrie=0;
     current=root;
     for(it_b=(*it_a).begin();it_b<(*it_a).end();++it_b){
    	if(*it_b == 'A' || *it_b == 'C' || *it_b == 'T' || *it_b == 'G'){
           currentsymbol=*it_b;
           trieNode *child=current->findNode(currentsymbol);
           if(child != NULL){
			   current = child;
			   indexTrie++;
           }
           else{
        	   cout<<current->retIndex()<<"->"<<++numNodes<<":"<<currentsymbol<<endl;
        	   trieNode *n=new trieNode();
        	   n->assignsymbol(currentsymbol);
        	   n->assignindex(numNodes);
        	   current->appendChild(n);
        	   current=n;
        	   indexTrie++;
           }
    	}
       }
     }
}

int trieTree::sizeTrie(){
   return size;
}

int main(){
   int n;
   cin>>n;
   if(n>=1 && n<=100){
      trieTree *tree=new trieTree();
      vector<string> patterns;
      for(int i=0;i<n;i++){
         string s;
         cin>>s;
         if(s.size()>=1 && s.size()<=100)
            patterns.push_back(s);
      }
      tree->addTrieNode(patterns);
   }
   return 0;
}
