/*
Queue File

Implements the prototyped functions in Queue.h
*/

#include "Queue.h"
#include <stdio.h>
#include <string.h>

extern Queue* initQueue()
{
    Queue* newQueue = (Queue*)calloc(1, sizeof(Queue));
    if (newQueue == NULL)
    {
        printf("Cannot successfully allocate memory to new Queue\n");
        exit(-1);
    }
    newQueue->Count = 0;
    newQueue->Head = NULL;
    newQueue->Tail = NULL;
    return newQueue;

}

static Customer* peekNext(Customer*c) {
    return c->nextNode;
}

extern int removeNode(Queue* Q, Customer* target)
{
    if (isEmpty(Q))
    {
        return EXIT_SUCCESS;
    }
    if (!target)
    {
        return EXIT_FAILURE;
    }
    if (Q->Head == Q->Tail)
    {
        free(dequeue(Q));
        return EXIT_SUCCESS;
    }
    if (!target->previousNode)
    {
        free(dequeue(Q));
        return EXIT_SUCCESS;
    }
    if (!target->nextNode)
    {
        if (!target->previousNode)
        {
            printf("Error: Queue is not working correctly\n");
            return EXIT_FAILURE;
        }

        Customer* temp = Q->Tail;
        Q->Tail->previousNode->nextNode = NULL;
        Q->Tail = temp->previousNode;
        free(temp);
        Q->Count--;
        return EXIT_SUCCESS;
    }
    if (Q->Count > 2)
    {
        /* Reassigning pointers to nodes after target node is removed */
        target->previousNode->nextNode = target->nextNode;
        target->nextNode->previousNode = target->previousNode;
        free(target);
        Q->Count--;
        return EXIT_SUCCESS;

    }

    return EXIT_FAILURE;

}

extern int impatientPeopleLeave(Queue* q)
{

    int customersLeft = 0;
    Customer* target = q->Head;

    /*      for(i = 0; i < Q->Count; i++) */
    while (target != NULL)
    {
        target->patienceLevel--;
        if (target->patienceLevel <= 0)
        {
            /* Removing target node from queue and reassigning it to head */
            removeNode(q, target);
            /*target = q->Head;*/
            customersLeft++;
        }
        target = target->nextNode;
    }
    return customersLeft;
}

/*
extern int removeQueueNode(Queue* q, Customer* target)
{
    if (isEmpty(q))
    {
        return EXIT_SUCCESS;
    }
    if (!target)
    {
        return EXIT_FAILURE;
    }
    if (q->Head == q->Tail)
    {
        free(dequeue(q));
        return EXIT_SUCCESS;
    }
    if (!target->previousNode)
    {
        free(dequeue(q));
        return EXIT_SUCCESS;
    }
    if (!target->nextNode)
    {
        if (!target->previousNode)
        {
            printf("Error: queue is not working correctly\n");
            return EXIT_FAILURE;
        }

        Customer* temp = q->Tail;
        q->Tail->previousNode->nextNode = NULL;
        q->Tail = temp->previousNode;
        free(temp);
        q->Count--;
        return EXIT_SUCCESS;
    }
    if (q->Count > 2)
    {
         Reassigning pointers to nodes after target node is removed 
        target->previousNode->nextNode = target->nextNode;
        target->nextNode->previousNode = target->previousNode;
        free(target);
        q->Count--;
        return EXIT_SUCCESS;

    }

    return EXIT_FAILURE;

}*/
/*
extern int impatientPeopleLeave(Queue* q) {
    
    int peopleLeaving = 0;
    Customer* target = q->Head;

    int i;
    for (i = 0; i < q->Count; i++)
    {
        target->patienceLevel--;
        if (target->patienceLevel <= 0)
        {
             Removing target node from queue and reassigning it to head 
            removeQueueNode(q, target);
            target = q->Head;
            i = 0;
            peopleLeaving++;
        }
        else {
            target = target->nextNode;
        }
    }
    return peopleLeaving;
}*/

/*
extern int removeFromQueue(Queue* q)
{
    int customersLeft = 0;

    if (!isEmpty(q)) {

        Customer* previous = q->Head;
        Customer* target;
        Customer* next;

        if (q->Count > 2) {

            target = previous->nextNode;
            next = target->nextNode;

            for (int i = 0; i < q->Count; i++) {
                
                target->patienceLevel--;

                if (target->patienceLevel <= 0) {

                    free(target);
                    previous->nextNode = next;
                    target = next;

                    customersLeft++;

                    if (target == q->Tail) {
                        break;
                    }
                    next = target->nextNode;

                }
                else {
                    previous = target;
                    target = next;

                    if (target == q->Tail) {
                        break;
                    }
                    next = target->nextNode;
                }
            }
        }

        q->Tail->patienceLevel--;
        if (q->Tail->patienceLevel <= 0) {
            free(q->Tail);
            previous->nextNode = NULL;
            q->Tail = previous;

            customersLeft++;
        }


        target = q->Head;
        next = target->nextNode;
        q->Head->patienceLevel--;
        if (q->Head->patienceLevel <= 0) {

            if (q->Head == q->Tail) {
                free(dequeue(q));
                free(q);
                q = initQueue();

                return 0;
            } else {
                printf("Head before: %p\n", q->Head);
                free(q->Head);
                printf("Head after: %p\n", q->Head);
                q->Head = next;
               
                customersLeft++;
            }
        }
    }

    q->Count -= customersLeft;
    return customersLeft;
}
*/
extern void enqueue(Queue* q, Customer* c)
{
    if (!q->Head) {
        q->Head = q->Tail = c;
        c->nextNode = NULL;
        c->previousNode = NULL;
    }
    else {
        c->previousNode = q->Tail;
        (q->Tail)->nextNode = c;
        q->Tail = c;
    }
    q->Count++;
}

extern Customer* dequeue(Queue* q)
{
    if (!isEmpty(q))
    {
        Customer* temp = q->Head;
        q->Head = (q->Head)->nextNode;
        if (q->Head) {
            q->Head->previousNode = NULL;
        }
        q->Count--;

        if (!q->Head) {
            free(q->Head);
            q->Tail = NULL;
        }

        return temp;
    }
    return NULL;
}

extern bool isEmpty(Queue* q) {
    return (q->Count == 0);
}

extern void printQueue(Queue* q)
{
    if (isEmpty(q)) {
        printf("The queue is empty, nothing to print\n");
        return;
    };
    Customer* current = q->Head;

    while (current != NULL) {
        if (current == q->Head) {
            printf("Head --> ");
        }
        if (current == q->Tail) {
            printf("Tail -->");
        }
        printf("[previousNode: %p] [Patience: %d, Serving: %d] [nextNode: %p]\n", current->previousNode, current->patienceLevel, current->servingTime, current->nextNode);

        if (current == q->Tail) { break; }
        current = current->nextNode;
    }

    printf("\n");
}