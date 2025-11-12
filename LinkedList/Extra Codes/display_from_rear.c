void display_reverse(struct node *head)
{
    if (head == NULL)
        return;   // ← Base condition
    display_reverse(head->next);
    printf("%d ", head->info);
}