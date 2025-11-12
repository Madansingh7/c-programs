//GIVES COUNT OF NO OF VOWELS PRESENT IN THE LINKED LIST {NOTE : ITS ELE IS CHAR NOT STRING}
int countVowels(NODE first) {
    if (first == NULL) {
        printf("List is empty\n");
        return 0;
    }
    int count = 0;
    NODE temp = first;
    while (temp != NULL) {
        char ch = temp->info;
        if (ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U' ||
            ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
            count++;
        temp = temp->next;
    }
    return count;
}
