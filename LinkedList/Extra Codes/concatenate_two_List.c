NODE concat(NODE first, NODE second)
{
    // Case 1: both lists are empty
    if (first == NULL && second == NULL)
        return NULL;

    // Case 2: first list empty
    if (first == NULL)
        return second;

    // Case 3: second list empty
    if (second == NULL)
        return first;

    // Case 4: both non-empty
    NODE temp = first;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = second;  // link the two lists

    return first;
}
