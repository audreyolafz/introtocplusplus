// Audrey Wang
// 12/6/2023
// Linked List Program
// This program creates, deletes, and prints linked lists.

#include <iostream>
using namespace std;

// define node structure
struct a_node 
{
    int number_of_visitors;
    a_node *next_node;
};

/**
 * inserts a node at the beginning of the linked list
 * @param linked_list passes reference to the address pointer of linked list values
 * @param number_of_visitors passes value to be inserted at the front
*/
void insert_node(a_node *&linked_list, int number_of_visitors) 
{
    a_node *new_list = new a_node;
    new_list->number_of_visitors = number_of_visitors;
    new_list->next_node = linked_list;
    linked_list = new_list;
};

/**
 * deletes the node at the beginning of the linked list 
 * @param linked_list passes reference to the address pointer of linked list values

*/
int delete_node(a_node *&linked_list) 
{
    if (linked_list == NULL) 
    {
        cout << "The list is empty." << endl;
        return -1;
    }
    int deleted_node = linked_list->number_of_visitors;
    a_node *temp = linked_list;
    linked_list = linked_list->next_node;
    delete temp; 
    return deleted_node;
};

/**
 * prints the linked list in chronological order
 * @param linked_list passes reference to the address pointer of linked list values
*/
void print_list(a_node *linked_list) 
{
    a_node *current = linked_list;
    while (current != NULL) 
    {
        cout << current->number_of_visitors << " ";
        current = current->next_node;
    }
    cout << "\n";
};

int main() 
{
    // inserts 3 values into node
    a_node *new_list = NULL;
    insert_node(new_list, 13);
    print_list(new_list);

    insert_node(new_list, 15);
    print_list(new_list);
    
    insert_node(new_list, 22);
    print_list(new_list);
    
    // deletes node at the beginning
    int deleted_val = delete_node(new_list);
    cout << "Deleted val: " << deleted_val << endl;
    print_list(new_list);
    
}