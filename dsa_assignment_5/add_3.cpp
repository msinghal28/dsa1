void removeLoop(Node* head) {
    if(!head) return;

    Node* slow = head;
    Node* fast = head;

    // Detect loop
    while(fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast) break;
    }

    if(slow != fast) return; // No loop

    // Move slow to head, keep fast at meeting point
    slow = head;

    // If loop starts at head
    if(slow == fast) {
        while(fast->next != slow)
            fast = fast->next;
        fast->next = NULL;
        return;
    }

    // Move both pointers until next pointers match
    while(slow->next != fast->next) {
        slow = slow->next;
        fast = fast->next;
    }

    fast->next = NULL; // break loop
}
