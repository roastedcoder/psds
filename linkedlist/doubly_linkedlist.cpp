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
    Node *newNode = new Node();
    newNode->data = data;
    if (tail == NULL) {
      head = tail = newNode;
    } else {
      tail->next = newNode;
      newNode->prev = tail;
      tail = newNode;
    }
  }

  void push_front(int data) {
    Node *newNode = new Node();
    newNode->data = data;
    if(head == NULL) {
      head = tail = newNode;
    } else {
      newNode->next = head;
      head->prev = newNode;
      head = newNode;
    }
  }

  void pop_back() {
    if(tail == NULL) return;
    Node *tmp = tail;
    tail = tail->prev;
    tail->next = NULL;
    delete tmp;
  }

  void pop_front() {
    if(head == NULL) return;
    Node *tmp = head;
    head = head->next;
    head->prev = NULL;
    delete tmp;
  }

  void print() {
    Node *itr = head;
    while(itr != NULL) {
      cout << itr->data << " ";
      itr = itr->next;
    }
    cout << endl;
  }
};

int main() {
  LinkedList ll;
  ll.push_back(1);
  ll.push_back(2);
  ll.push_back(3);
  ll.push_front(0);
  ll.push_front(-1);
  ll.print();
  ll.pop_back();
  ll.print();
  ll.pop_front();
  ll.print();
}
