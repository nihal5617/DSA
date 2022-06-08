
struct ListNode
{
    int val;
    struct ListNode *next;
};

int hasCycle(struct ListNode *head)
{

    struct ListNode *t1 = head; // slow pointer
    struct ListNode *t2 = head; // fast pointer

    while (t2 && t2->next)
    {
        t1 = t1->next;
        t2 = t2->next->next;
        if (t1 == t2)
            return 1;
    }

    return 0;
}
