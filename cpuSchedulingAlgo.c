#include <stdio.h>
#include <stdlib.h>

struct node {
    int pid;
    int at, bt, rt;
    int ct, tat, wt;
    int completed;
    struct node *next;
};
typedef struct node* NODE;
/* ---------- create process Functions ---------- */

NODE create_process(int pid, int at, int bt) {
    NODE p = malloc(sizeof(*p));

    p->pid = pid;
    p->at = at;
    p->bt = bt;
    p->rt = bt;
    p->ct = p->tat = p->wt = 0;
    p->completed = 0;
    p->next = NULL;

    return p;
}

NODE insert_end(NODE head, NODE p) {
    if (!head) return p;

    NODE t = head;
    while (t->next)
        t = t->next;

    t->next = p;
    return head;
}

void print_results(NODE head) {
    float avg_tat = 0, avg_wt = 0;
    int n = 0;
    NODE t = head;

    printf("\nPID\tAT\tBT\tCT\tTAT\tWT\n");
    while (t) {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n",
               t->pid, t->at, t->bt, t->ct, t->tat, t->wt);
        avg_tat += t->tat;
        avg_wt += t->wt;
        n++;
        t = t->next;
    }

    printf("\nAverage TAT = %.2f", avg_tat / n);
    printf("\nAverage WT  = %.2f\n", avg_wt / n);
}

/* ---------- FCFS ---------- */

void fcfs(NODE head) {
    int time = 0;
    NODE t = head;

    printf("\nGantt Chart:\n|");
    while (t) {
        if (time < t->at)
            time = t->at;

        printf(" P%d |", t->pid);
        time += t->bt;

        t->ct = time;
        t->tat = t->ct - t->at;
        t->wt = t->tat - t->bt;

        t = t->next;
    }
    printf("\n");
    print_results(head);
}

/* ---------- SJF Non-Preemptive ---------- */

void sjf_non_preemptive(NODE head) {
    int time = 0;
    NODE t;

    printf("\nGantt Chart:\n|");

    while (1) {
        NODE shortest = NULL;
        int min_bt = 99999;

        t = head;
        while (t) {
            if (!t->completed && t->at <= time && t->bt < min_bt) {
                min_bt = t->bt;
                shortest = t;
            }
            t = t->next;
        }

        if (!shortest) {
            int done = 1;
            t = head;
            while (t) {
                if (!t->completed)
                    done = 0;
                t = t->next;
            }
            if (done)
                break;
            time++;
            continue;
        }

        printf(" P%d |", shortest->pid);

        time += shortest->bt;
        shortest->ct = time;
        shortest->tat = shortest->ct - shortest->at;
        shortest->wt = shortest->tat - shortest->bt;
        shortest->completed = 1;
    }

    printf("\n");
    print_results(head);
}

/* ---------- SJF Preemptive (SRTF) ---------- */

void sjf_preemptive(NODE head) {
    int time = 0;
    NODE t;

    printf("\nGantt Chart:\n|");

    while (1) {
        NODE shortest = NULL;
        int min_rt = 99999;

        t = head;
        while (t) {
            if (t->at <= time && t->rt > 0 && t->rt < min_rt) {
                min_rt = t->rt;
                shortest = t;
            }
            t = t->next;
        }

        if (!shortest) {
            int done = 1;
            t = head;
            while (t) {
                if (t->rt > 0)
                    done = 0;
                t = t->next;
            }
            if (done)
                break;
            time++;
            continue;
        }

        printf(" P%d |", shortest->pid);

        shortest->rt--;
        time++;

        if (shortest->rt == 0) {
            shortest->ct = time;
            shortest->tat = shortest->ct - shortest->at;
            shortest->wt = shortest->tat - shortest->bt;
        }
    }

    printf("\n");
    print_results(head);
}

/* ---------- Round Robin ---------- */

void round_robin(NODE head, int tq) {
    int time = 0, done;
    NODE t;

    printf("\nGantt Chart:\n|");

    do {
        done = 1;
        t = head;

        while (t) {
            if (t->rt > 0 && t->at <= time) {
                done = 0;
                printf(" P%d |", t->pid);

                int exec = (t->rt > tq) ? tq : t->rt;
                time += exec;
                t->rt -= exec;

                if (t->rt == 0) {
                    t->ct = time;
                    t->tat = t->ct - t->at;
                    t->wt = t->tat - t->bt;
                }
            }
            t = t->next;
        }
    } while (!done);

    printf("\n");
    print_results(head);
}

/* ---------- MAIN ---------- */

int main() {
    int n, i, ch, tq;
    NODE head = NULL;
    
label:
    printf("Enter number of processes: ");
    scanf("%d", &n);
 
    if(n<=0){
        printf("Number of process cannot be less than 1\n");
        goto label;
    }

//enter arrival time and burst time
    for (i = 1; i <= n; i++) {
        int at, bt;
        printf("Enter AT and BT for P%d: ", i);
        scanf("%d %d", &at, &bt);
        head = insert_end(head, create_process(i, at, bt));
    }

    while(1) {
        printf("\n1.FCFS  2.SJF(NP)  3.SJF(P)  4.RoundRobin  5.Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);
        
        switch(ch){
            case 1:
            fcfs(head);
            break;
            
            case 2:
            sjf_non_preemptive(head);
            break;
            
            case 3:
            sjf_preemptive(head);
            break;
            
            case 4:
            printf("Enter Time Quantum: ");
            scanf("%d", &tq);
            round_robin(head, tq);
            break;
            
            case 5:
            printf("Exiting program . . . . \n");
            exit(0);
            
            default :
            printf("Invalid choice\n");
        }
    }

    return 0;
}
