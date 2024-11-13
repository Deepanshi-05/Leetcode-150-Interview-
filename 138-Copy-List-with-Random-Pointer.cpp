/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
         if (head == NULL) return NULL;

    // Step 1: Create interleaved nodes
    Node* current = head;
    while (current != NULL) {
        Node* clone = new Node(current->val);
        clone->next = current->next;
        current->next = clone;
        current = clone->next;
    }

    // Step 2: Copy random pointers
    current = head;
    while (current != NULL) {
        if (current->random != NULL) {
            current->next->random = current->random->next;
        }
        current = current->next->next;
    }

    // Step 3: Restore the original list and extract the cloned list
    Node* original = head;
    Node* copy = head->next;
    Node* clonedHead = copy;

    while (original != NULL) {
        original->next = original->next->next;
        if (copy->next != NULL) {
            copy->next = copy->next->next;
        }
        original = original->next;
        copy = copy->next;
    }

    return clonedHead;

// Explanation of Steps
// Interleave Clones:

// We create cloned nodes and interleave them with the original nodes.
// Set Random Pointers:

// Since the cloned node is next to the original node, original->random->next points to the clone of the random target.
// Restore Original and Clone List:

// We unlink the interleaved list into two separate lists: the original list and the deep copy.
// Time and Space Complexity
// Time Complexity: O(n)
// We traverse the list three times:
// Once to create interleaved nodes.
// Once to copy the random pointers.
// Once to restore the original and cloned lists.
// Space Complexity: O(1) (excluding the space for the new nodes).
// This is an efficient solution as it avoids using additional data structures.

    }
};