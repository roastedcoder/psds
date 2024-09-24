#include <bits/stdc++.h>
using namespace std;
struct Node {
    int data;
    Node *next;
};

class LinkedList {
  Node *head;

  public:
  LinkedList() {
    head = NULL;
  }

  void push_back(int data) {
    Node *new_node = new Node();
    new_node->data = data;
    new_node->next = NULL;
    if (head == NULL) {
      head = new_node;
    } else {
      Node *temp = head;
      while(temp->next != NULL) {
        temp = temp->next;
      }
      temp->next = new_node;
    }
  }

  void push_front(int data) {
    Node *new_node = new Node();
    new_node->data = data;
    new_node->next = head;
    head = new_node;
  }

  void pop_back() {
    if (head == NULL) return;
    if (head->next == NULL) {
      delete head;
      head = NULL;
    } else {
      Node *curr = head;
      while(curr->next->next != NULL) {
        curr = curr->next;
      }
      delete curr->next;
      curr->next = NULL;
    }
  }

  void pop_front() {
    if (head == NULL) return;
    Node *temp = head;
    head = head->next;
    delete temp;
  }

  void print() {
    Node *temp = head;
    while (temp != NULL) {
      cout << temp->data << " ";
      temp = temp->next;
    }
    cout << endl;
  }

  void reverse() {
    head = reverse_recursively(head);
  }
  
  Node *reverse_recursively(Node *head) {
    // Let's explain this with an example of three nodes: 1 -> 2 -> 3 -> NULL
    // We'll go through each recursive call stack
    
    if (!head || !head->next) return head;
    // Base case: If list is empty or has only one node, return head
    
    // First stack (head = 1):
    //   1. Calls reverse_recursively(2)
    Node *new_head = reverse_recursively(head->next);
    //   5. Returns with new_head = 3
    //   6. Current state: 1 -> 2 -> 3 -> NULL
    head->next->next = head;
    //   7. 2->next = 1, State: 1 <- 2 <- 3, 1 -> 2
    head->next = NULL;
    //   8. 1->next = NULL, Final state: 1 <- 2 <- 3
    
    // Second stack (head = 2):
    //   2. Calls reverse_recursively(3)
    //   4. Returns with new_head = 3
    //      Current state: 2 -> 3 -> NULL
    //      3->next = 2, State: 2 <- 3, 2 -> 3
    //      2->next = NULL, State: 2 <- 3
    
    // Third stack (head = 3):
    //   3. Base case triggered, returns 3
    
    return new_head;
    // Returns 3, which is now the start of our reversed list
    
    // Final result: 3 -> 2 -> 1 -> NULL
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
//   ll.pop_back();
//   ll.print();
//   ll.pop_front();
//   ll.print();
  ll.reverse();
  ll.print();
}
