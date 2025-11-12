void displayOddPositions(NODE first) {
    if (first == NULL) {
        printf("List is empty\n");
        return;
    }
    NODE temp = first;
    int pos = 1;
    printf("Elements at odd positions: ");
    while (temp != NULL) {
        if (pos % 2 != 0)
            printf("%c ", temp->info);
        temp = temp->next;
        pos++;
    }
    printf("\n");
}

void displayEvenPositions(NODE first) {
    if (first == NULL) {
        printf("List is empty\n");
        return;
    }
    NODE temp = first;
    int pos = 1;
    printf("Elements at even positions: ");
    while (temp != NULL) {
        if (pos % 2 == 0)
            printf("%c ", temp->info);
        temp = temp->next;
        pos++;
    }
    printf("\n");
}
