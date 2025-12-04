Node* reverseK(Node* head, int k) {
    if(!head) return NULL;

    Node* curr = head;
    Node* prev = NULL;
    Node* nxt = NULL;

    int cnt = 0;

    while(curr && cnt < k) {
        nxt = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nxt;
        cnt++;
    }

    // head becomes last node of reversed block
    if(nxt != NULL)
        head->next = reverseK(nxt, k);

    return prev;
}
