struct Poly {
    int coeff;
    int pow;
    Poly* next;
};

Poly* addPoly(Poly* p1, Poly* p2) {
    Poly* head = NULL;
    Poly* tail = NULL;

    while(p1 && p2) {
        Poly* node = new Poly();

        if(p1->pow == p2->pow) {
            node->coeff = p1->coeff + p2->coeff;
            node->pow = p1->pow;
            p1 = p1->next;
            p2 = p2->next;
        }
        else if(p1->pow > p2->pow) {
            node->coeff = p1->coeff;
            node->pow = p1->pow;
            p1 = p1->next;
        }
        else {
            node->coeff = p2->coeff;
            node->pow = p2->pow;
            p2 = p2->next;
        }

        node->next = NULL;

        if(!head) head = tail = node;
        else { tail->next = node; tail = node; }
    }

    // Append remaining terms
    while(p1) {
        Poly* node = new Poly();
        node->coeff = p1->coeff;
        node->pow = p1->pow;
        node->next = NULL;
        tail->next = node;
        tail = node;
        p1 = p1->next;
    }

    while(p2) {
        Poly* node = new Poly();
        node->coeff = p2->coeff;
        node->pow = p2->pow;
        node->next = NULL;
        tail->next = node;
        tail = node;
        p2 = p2->next;
    }

    return head;
}
