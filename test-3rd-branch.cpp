#include <iostream>
#include <cstdlib> // for rand() and srand()
#include <ctime>  // for time()


using namespace std;


// Structure for a node in the linked list
struct Node {
  int data;
  Node* next;
};


// Function to create a new node with a given value
Node* createNode(int value) {
  Node* newNode = new Node;
  newNode->data = value;
  newNode->next = nullptr; // New node's next pointer points to nothing
  return newNode;
}


// Function to insert a node in a sorted linked list
void insertSorted(Node** head, Node* newNode) {
  Node* current = *head;


  // If list is empty or new node's value is less than head's value, insert at the beginning
  if (*head == nullptr || newNode->data < (*head)->data) {
    newNode->next = *head;
    *head = newNode;
  } else {
    // Traverse the list to find the appropriate position for insertion
    while (current->next != nullptr && current->next->data <= newNode->data) {
      current = current->next;
    }
    newNode->next = current->next;
    current->next = newNode;
  }
}


// Function to print the linked list
void printList(Node* head) {
  while (head != nullptr) {
    cout << head->data << " ";
    head = head->next;
  }
  cout << endl;
}


int main() {
  srand(time(0)); // Seed random number generator


  Node* head = nullptr; // Initialize head pointer to empty list


  // Generate 10 random values and insert them in sorted order
  for (int i = 0; i < 10; i++) {
    int value = rand() % 100 + 1; // Generate a random value between 1 and 100
    Node* newNode = createNode(value);
    insertSorted(&head, newNode);
  }


  cout << "Linked list in ascending order: ";
  printList(head);


  // Free the allocated memory for nodes (important to avoid memory leaks)
  Node* current = head;
  while (current != nullptr) {
    Node* temp = current;
    current = current->next;
    delete temp;
  }


  return 0;
}





