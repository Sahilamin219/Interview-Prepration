#include "bits/stdc++.h"
#define int long long
#define all(x) begin(x), end(x)
using namespace std;
typedef vector<int> vi;
struct TrieNode
{
  vector<TrieNode*> children;
  bool isLeaf;  // Denotes EndOfWord
  int count=0;
  TrieNode() : children(26){}
};
struct TrieNode *getNode(void)
{
  TrieNode* pNode=new TrieNode();
  pNode->isLeaf=false;
  for(int i=0;i<26;i++){
    pNode->children[i]=NULL;
  }
  return pNode;
};
void insert(struct TrieNode* root, string toAdd){
  TrieNode* pCrawl=root;
  for(int i=0;i<toAdd.length();i++){
    int index=toAdd[i]-'a';
    if( !pCrawl->children[index] ){
      pCrawl->children[index]=getNode();
    }
	pCrawl->count+=1;
    pCrawl=pCrawl->children[index];
  }
  pCrawl->count+=1;
  pCrawl->isLeaf=true;
}
string Search(struct TrieNode* root, string Key){
  TrieNode* pCrawl=root;
  for(int i=0;i<Key.length();i++){
      int index=Key[i]-'a';
      if( !pCrawl->children[index] ){
          return "String Not Found";
        //return 0;
      }
      pCrawl=pCrawl->children[index];
  }
  string ans=Key;
  while( 1 ){
      int maxi=0, index=-1;
      for(int i=0;i<26;i++){
          if(pCrawl->children[i] != NULL){
          		if(maxi < pCrawl->children[i]->count){
          			index=i;	
          		}
              maxi=max(maxi, pCrawl->children[i]->count);
          }
      }
      if(maxi==0){
      // 	while( pCrawl->isLeaf == false )ans += char()
      	return ans;
      }
      pCrawl=pCrawl->children[index];
      ans += char( 'a' + index);
  }
  return ans;
  //return pCrawl->count;
}
bool RecSearch(struct TrieNode* root, string Key, int index){
  if(index == Key.length() )return true;
  int gap=Key[index]-'a';
  if(root->children[gap]) return RecSearch(root->children[gap], Key, index+1);
  return false;
}
 
void solve()
{
	int n;cin>>n;
	struct TrieNode* root=getNode();
  	for(int i=0;i<n;i++){
	  	string str;
	  	cin>>str;
	  	insert(root, str);
  }
  string input;cin>>input;
  cout<<Search(root, input);
  return ;
}
int32_t main(){
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	solve();
}
