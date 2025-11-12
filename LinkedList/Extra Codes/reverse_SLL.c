NODE reverse(NODE first)
{
    NODE prev = NULL, curr = first, next = NULL;
    while (curr != NULL)
    {
        next = curr->next;   // store next node
        curr->next = prev;   // reverse the link
        prev = curr;         // move prev forward
        curr = next;         // move curr forward
    }
    first = prev;   // update head
    return first;
}

