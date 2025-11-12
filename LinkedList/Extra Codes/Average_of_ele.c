//FIND AVG OF ALL ELEMENTS OF A LINKED LIST 
float average(NODE first) {
    if (first == NULL) {
        printf("List is empty\n");
        return 0;
    }
    int sum = 0, count = 0;
    NODE curr = first;
    while (curr != NULL) {
        sum += curr->info;
        count++;
        curr = curr->next;
    }
    return (float)sum / count;
}
