//Tamzid Chowdhury
//Question10
//Group_1

#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

struct Node
{
  int data;
  struct Node *next;
};
    // to get the values of each node.
    
    Node * getNode (int d) {
    Node *temp = new Node;
    temp->data = d;
    temp->next = NULL;
    return temp;
    }

// Function to sepatate even and odd nodes. 
    void oddNeven (struct Node **h_reference)
{
  // Starting node of even values lsit. 
  Node *evenStart = NULL;

  // Ending node of even values list. 
  Node *evenEnd = NULL;

  // Starting node of odd values list. 
  Node *oddStart = NULL;

  // Ending node of odd values lsit. 
  Node *oddEnd = NULL;

  // Node to traverse through the list. 
  Node *currentNode = *h_reference;

  while (currentNode != NULL)
    {
      int number = currentNode->data;

      // If current value is even, add it to even values list. 
      if (number % 2 == 0)
	{
	  if (evenStart == NULL)
	    {
	      evenStart = currentNode;
	      evenEnd = evenStart;
	    }

	  else
	    {
	      evenEnd->next = currentNode;
	      evenEnd = evenEnd->next;
	    }
	}

      // If current value is odd, add it to odd values list. 
      else
	{
	  if (oddStart == NULL)
	    {
	      oddStart = currentNode;
	      oddEnd = oddStart;
	    }
	  else
	    {
	      oddEnd->next = currentNode;
	      oddEnd = oddEnd->next;
	    }
	}

      // Move head pointer one step forward.
      currentNode = currentNode->next;
    }

  // If either odd list or even list is empty, no sorting is required, return.

  if (oddStart == NULL || evenStart == NULL)
    {
      return;
    }

   // Add even list first and then odd list.    
    evenEnd->next = oddStart;
    oddEnd->next = NULL;
  
  // Modify head pointer to starting of even list. 
  
  *h_reference = evenStart;
}


// Function to insert a node at the beginning of the lsit. 
    void push (struct Node **head_ref, int new_data)
{
  // to save/allocate node
  struct Node *new_node = (struct Node *) malloc (sizeof (struct Node));

  // to put in the data 
  new_node->data = new_data;

  // to ink the old list off the new node 
  new_node->next = (*head_ref);

  // to move the head to point to the new node 
  (*head_ref) = new_node;
}

// Function to print all the nodes in the linked list 
    void printList (struct Node *node)
    {
        while (node != NULL)
    {
      cout << node->data << " ";
      node = node->next;
    }
}

    // the main function to test all the above functions
    int main ()
    {
    cout << "Enter values to start building the list, enter 0 to stop" << endl;
    int k;
    Node *curr, *temp; // keep asking for a new entry
    cin >> k;
    Node *head = getNode (k);
    cin >> k;
    temp = head;
    while (k)  { // loop to go through every node of the user entry
        curr = getNode (k);
        temp->next = curr;
        temp = temp->next;
        cin >> k;
    }

    cout << "Unsorted Linked List ";
    cout << endl;
    printList (head);
    cout << "\nLinked list after sorting by first even, then odd numbers" <<
    endl;
    oddNeven (&head);
    printList (head);
    return 0;
}

