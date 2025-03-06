#include "llrec.h"

//*********************************************
// Provide your implementation of llpivot below
//*********************************************


void llpivot(Node*& head, Node*& smaller, Node*& larger, int pivot) {
    if (!head) { //if head is null, then set head, smaller, and larger to null
        head = NULL;
        smaller = NULL;
        larger = NULL;
        return;
    }

    Node* current = head; //stores node
    head = head->next;  //head moves to next for the recursive call

    llpivot(head, smaller, larger, pivot); //recusive call

    if (current->val <= pivot) { //if the val is less than or equal to pivot, it is added to smaller
        current->next = smaller;
        smaller = current;
    }
    else {
        current->next = larger; //if the value is greater than pivot, it is added to larger
        larger = current;
    }
}

