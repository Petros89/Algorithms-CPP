#include <stdexcept>
#include <iostream>
#include <string>
#include <sys/time.h>
#include <unordered_set>
#include <list>
#include <iterator>
#include <cctype>



using namespace std;

double get_time()
{
  struct timeval timeval_time;
  gettimeofday(&timeval_time,NULL);
  return (double)timeval_time.tv_sec + (double)timeval_time.tv_usec*1e-6;
}

class Node {
public:
	int data;
    string name;
	Node* next;
    
    
private: 
};


// This function prints contents of linked list
// starting from the given node
void printList(Node* n)
{
    while (n != NULL) {
        cout << "\n Node::[" << n->name << "] ===> " << n->data << " " << "\n";
        n = n->next;
    }
}

void sortList(Node* n)
{

   Node* curr = n;
  
   for(bool swapped = true; swapped;) {

      swapped = false;

      for (curr = n; curr->next != NULL; curr=curr->next){

          if (curr->data > curr->next->data){

              swap(curr->data,curr->next->data);

              swapped = true;
          }
      }
   } 
}

auto reverseList(Node* n) {

    Node* curr = n;
    Node* next = NULL;
    Node* prev = NULL;

    while (curr != NULL){

        next = curr->next;
        curr->next = prev;

        prev = curr;
        curr = next;
    }
}
        
auto reverseListRecursive(Node* n)
	{
        if (n == NULL || n->next == NULL)
		     return n;

        Node* prev = reverseListRecursive(n->next);
        n->next->next = n;
        n->next = NULL;
	    return prev;
    }


void RmDupls(Node* n)
{

	unordered_set<int> seen; 

    //define temporal current and previous nodes
    Node *curr = n;
    Node *prev = NULL;

    while (curr != NULL) {
        // If current value is seen before
        if (seen.find(curr->data) != seen.end())
        {
           cout << "\n Node: [" << curr->name << "] is seen before with value = " << curr->data << ". Node is deleted! \n";
           prev->next = curr->next;
           delete(curr);
        }
        else
        {
           cout << "\n Node: [" << curr->name << "] is Unique with value = " << curr->data << "\n";
           seen.insert(curr->data);
           prev = curr;
        }
        curr = prev->next;
    }

}


void LinkedList(Node* head, Node* second, Node* third, Node* fourth, Node* fifth, Node* sixth, Node* seventh, Node* tail){

	head->data = 110; // assign data in head node 
    head->name = "Head";
	head->next = second; // Link first node with the second node 

	second->data = 22; // assign data to second node
    second->name = "Second";
	second->next = third; // Link second node with the third node

	third->data = 11; // assign data to third node 
    third->name = "Third";
	third->next = fourth; 

	fourth->data = 100; // assign data to fourth node 
    fourth->name = "Fourth";
	fourth->next = fifth; 

	fifth->data = 150; // assign data to tail node 
    fifth->name = "Fifth";
	fifth->next = sixth;

    sixth->data = 1;
    sixth->name = "Sixth";
    sixth->next = seventh;

    seventh->data = 1834;
    seventh->name = "Seventh";
    seventh->next = tail;

	tail->data = 34; // assign data to tail node 
    tail->name = "Tail";
	tail->next = NULL; 
}

// Program to create a simple linked 
// list with 5 nodes 
int main() 
{ 
    //Allocate variable names for the 5 Nodes in the List
	Node* head = NULL; 
	Node* second = NULL; 
	Node* third = NULL; 
	Node* fourth = NULL; 
	Node* fifth = NULL; 
	Node* sixth = NULL; 
	Node* seventh = NULL; 
	Node* tail = NULL; 

    double t = get_time();

	// allocate 3 nodes in the heap 
	head = new Node(); 
	second = new Node(); 
	third = new Node(); 
    fourth = new Node();
    fifth = new Node();
    sixth = new Node();
    seventh = new Node();
    tail = new Node();

    //Implement the Linked List with 3 Nodes
    LinkedList(head, second, third, fourth, fifth, sixth, seventh, tail);

    //print Initial LinkedList
    cout << "\n" << "Initial LinkedList: \n";
    printList(head);

    //Remove Duplicate Node Instances
    RmDupls(head);

    //print Modified LinkedList
    cout << "\n" << "Modified LinkedList: \n";
    printList(head);

    //Sort the List 
    sortList(head);
    
    cout << "\n" << "Sorted LinkedList: \n";
    printList(head);

    //Reverse the LinkedList
    //reverseList(head);

    //Reverse the LinkedList Recursively
    reverseListRecursive(head);

    cout << "\n" << "Reversed LinkedList: \n";
    printList(tail);
    
    printf("\nWall Time: [%g s]\n",get_time()-t);
    return 0;
}

