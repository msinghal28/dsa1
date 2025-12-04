Node* rotateLeft(Node* head, int k) {
    if(!head) return NULL;

    // Find length
    Node* temp = head;
    int n = 1;
    while(temp->next) {
        temp = temp->next;
        n++;
    }

    k = k % n;
    if(k == 0) return head;

    // Make it circular
    temp->next = head;

    // Move to (k-1)th node
    int steps = k;
    Node* curr = head;
    while(--steps)
        curr = curr->next;

    // New head is next node
    Node* newHead = curr->next;
    curr->next = NULL;

    return newHead;
}
