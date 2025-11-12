NODE reverse(NODE first) {
    if (first == NULL) {
        printf("List is empty\n");
        return first;
    }

    NODE curr = first, temp = NULL;

    // Step 1: Swap prev and next for every node
    while (curr != NULL) {
        temp = curr->prev;          // store previous
        curr->prev = curr->next;    // swap pointers
        curr->next = temp;
        curr = curr->prev;          // move "forward" (actually to previous node before swap)
    }

    // Step 2: Adjust head pointer
    if (temp != NULL)
        first = temp->prev;

    printf("List reversed successfully\n");
    return first;
}
