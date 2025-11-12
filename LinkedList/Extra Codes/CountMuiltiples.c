//Given any number(num) this function gives count of multiple of that num.
int countMultiples(NODE first, int num) {
    if (first == NULL) {
        printf("List is empty\n");
        return 0;
    }
    int count = 0;
    NODE curr = first;
    while (curr != NULL) {
        if (curr->info % num == 0){
            count++;
        }
        curr = curr->next;
    }
    return count;
}
