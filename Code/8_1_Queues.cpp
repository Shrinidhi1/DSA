#include <iostream>
#include <cstdlib>
using namespace std;

#define QUEUESIZE 5

struct Queue
{
    int items[QUEUESIZE];
    int front;
    int rear;
};

void enqueue(Queue *);
int full(Queue *);
void dequeue(Queue *);
int empty(Queue *);
void peek(Queue);
void print(Queue);

int main()
{
    Queue q;
    q.front = -1;
    q.rear = -1;
    int choice;

    while (true)
    {
        cout << "\nMenu\n";
        cout << "1.Enqueue\n2.Dequeue\n3.Peek\n4.Print\n5.Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            enqueue(&q);
            break;
        case 2:
            dequeue(&q);
            break;
        case 3:
            peek(q);
            break;
        case 4:
            print(q);
            break;
        case 5:
            cout << "\nTerminating...";
            exit(0);
            break;
        default:
            cout << "\nIncorrect Choice";
            break;
        }
    }
}

void enqueue(Queue *q)
{
    if (full(q))
    {
        cout << "\nQueue full";
        return;
    }
    int x;
    cout << "Enter the item to be enqueued: ";
    cin >> x;
    q->rear++;
    q->items[q->rear] = x;
}

int full(Queue *q)
{
    if (q->rear == QUEUESIZE - 1)
        return 1;
    else
        return 0;
}

void dequeue(Queue *q)
{
    if (empty(q))
    {
        cout << "\nQueue empty";
        return;
    }
    int x;
    x = q->items[q->front];
    q->front++;
    cout << "Item dequeued: " << x << endl;
}

int empty(Queue *q)
{
    if (q->front == q->rear + 1)
        return 1;
    else
        return 0;
}

void peek(Queue q)
{
    if (empty(&q))
    {
        cout << "\nQueue empty";
        return;
    }
    int x;
    x = q.items[q.front];
    cout << "Peek is " << x << endl;
}

void print(Queue q)
{
    int i;
    if (empty(&q))
    {
        cout << "\nQueue empty";
        return;
    }
    for (i = q.front + 1; i <= q.rear; i++)
        cout << q.items[i] << "\n";
}