#include <iostream>
#define QUEUESIZE 5

using namespace std;

struct Queue
{
    int items[QUEUESIZE];
    int front;
    int rear;
};

bool isFull(Queue *q)
{
    if (q->front == 0 && q->rear == QUEUESIZE - 1)
        return true;
    if (q->front == q->rear + 1)
        return true;
    return false;
}

bool isEmpty(Queue *q)
{
    if (q->front == -1)
        return true;
    else
        return false;
}

void enQueue(Queue *q, int element)
{
    if (isFull(q))
        cout << "Queue is full";
    else
    {
        if (q->front == -1)
            q->front = 0;
        q->rear = (q->rear + 1) % QUEUESIZE;
        q->items[q->rear] = element;
        cout << endl
             << "Inserted " << element << endl;
    }
}

int deQueue(Queue *q)
{
    int element;
    if (isEmpty(q))
    {
        cout << "Queue is empty" << endl;
        return (-1);
    }
    else
    {
        element = q->items[q->front];
        if (q->front == q->rear)
        {
            q->front = -1;
            q->rear = -1;
        }
        else
            q->front = (q->front + 1) % QUEUESIZE;
        return (element);
    }
}

void print(Queue *q)
{
    int i;
    if (isEmpty(q))
    {
        cout << "Empty Queue" << endl;
    }
    else
    {
        for (i = q->front; i != q->rear; i = (i + 1) % QUEUESIZE)
            cout << q->items[i] << " ";
        cout << q->items[i];
    }
}

int main()
{
    Queue q;
    q.front = -1;
    q.rear = -1;

    int choice;

    while (true)
    {
        cout << "\nMenu\n";
        cout << "1.Enqueue\n2.Dequeue\n3.Print\n4.Exit\n";
        cout << "Enter choice: ";
        cin >> choice;
        int n;

        switch (choice)
        {
        case 1:
            cout << "Enter item to be added: ";
            cin >> n;
            enQueue(&q, n);
            break;
        case 2:
            deQueue(&q);
            break;
        case 3:
            print(&q);
            break;
        case 4:
            cout << "\nTerminating...";
            exit(0);
            break;
        default:
            cout << "\nIncorrect Choice";
            break;
        }
    }
    return 0;
}