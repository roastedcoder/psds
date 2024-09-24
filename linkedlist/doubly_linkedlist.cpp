#include <bits/stdc++.h>
using namespace std;

struct Node {
  int data;
  Node *next;
  Node *prev;
};

class LinkedList {
  Node *head;
  Node *tail;

  public:
  LinkedList() {
    head = NULL;
    tail = NULL;
  }

  void push_back(int data) {
    // TODO: Implement this
  }

  void push_front(int data) {
    // TODO: Implement this
  }

  void pop_back() {
    // TODO: Implement this
  }

  void pop_front() {
    // TODO: Implement this
  }

  void print() {
    // TODO: Implement this
  }
}

int main() {
  LinkedList ll;
  ll.push_back(1);
  ll.push_back(2);
  ll.push_back(3);
  ll.push_front(0);
  ll.push_front(-1);
  ll.print();
}
