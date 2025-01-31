#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

class Trie {
  private:
  class Node {
    public:
    unordered_map <char, Node*> child;
    bool isEnd;
    Node() {
      isEnd = false;
    }
  };

  Node *root;

  public:
  Trie() {
    root = new Node();
  }

  void insert(string s) {
    Node *curr = root;
    for(const auto &x: s) {
      if(!curr->child[x]) {
        curr->child[x] = new Node();
      }
      curr = curr->child[x];
    }
    curr->isEnd = true;
  }

  bool search(string s) {
    Node *curr = root;
    for(const auto &x: s) {
      if(!curr->child[x]) return false;
      curr = curr->child[x];
    }
    return curr->isEnd;
  }

  bool prefix(string s) {
    Node *curr = root;
    for(const auto &x: s) {
      if(!curr->child[x]) return false;
      curr = curr->child[x];
    }
    return true;
  }

  vector <string> suggestion(string s) {
    Node *curr = root;
    for(const auto &x: s) {
      if(!curr->child[x]) return vector <string> ();
      curr = curr->child[x];
    }

    vector <string> res;
    dfs(res, curr, s);

    return res;
  }

  private:
  void dfs(vector<string> &res, Node *node, string pre) {
    if(node->isEnd) res.push_back(pre);
    for(auto c: node->child) {
      if(c.second)
        dfs(res, c.second, pre + c.first);
    }
  }
};

int main() {
  cout << "Hello world" << endl;

  Trie trie;
  trie.insert("apple");
  trie.insert("book");
  cout << trie.search("book") << endl;
  trie.insert("app");
  cout << trie.search("app") << endl;
  cout << trie.search("appl") << endl;
  cout << trie.prefix("appl") << endl;
  cout << trie.prefix("app") << endl;
  cout << trie.prefix("apps") << endl;


  for(auto x: trie.suggestion("app")) cout << x << " ";
  cout << endl;
  for(auto x: trie.suggestion("appl")) cout << x << " ";
  cout << endl;
  for(auto x: trie.suggestion("b")) cout << x << " ";
  cout << endl;

  cout << "Bye world" << endl;
}