#include <iostream>
#define STACKSIZE 5

using namespace std;

struct stack
{
    int items[STACKSIZE];
    int top;
};

typedef struct stack STACK;

void push(STACK *);
void pop(STACK *);
void peek(STACK);
void print(STACK);
int full(STACK *);
int empty(STACK *);

int main()
{
    STACK s;
    s.top = -1;
    int choice;
    while (true)
    {
        cout << "\nMenu" << endl;
        cout << "1.Push\n2.Pop\n3.Peek\n4.Print\n5.Exit" << endl;
        cout << "Enter choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            push(&s);
            break;
        case 2:
            pop(&s);
            break;
        case 3:
            peek(s);
            break;
        case 4:
            print(s);
            break;
        case 5:
            cout << "Terminating..." << endl;
            exit(1);
        default:
            cout << "Incorrect Choice" << endl;
            break;
        }
    }
}

void push(STACK *s)
{
    if (full(s))
    {
        cout << "Stack full" << endl;
        return;
    }
    int x;
    cout << "Enter the item to be pushed: ";
    cin >> x;
    s->top++;
    s->items[s->top] = x;
}

int full(STACK *s)
{
    if (s->top == STACKSIZE - 1)
        return 1;
    else
        return 0;
}

void pop(STACK *s)
{
    if (empty(s))
    {
        cout << "Stack empty" << endl;
        return;
    }
    int x;
    x = s->items[s->top];
    s->top--;
    cout << "Item popped: " << x << endl;
}

int empty(STACK *s)
{
    if (s->top == -1)
        return 1;
    else
        return 0;
}

void peek(STACK s)
{
    if (empty(&s))
    {
        cout << "Stack empty" << endl;
        return;
    }
    int x;
    x = s.items[s.top];
    cout << "Peek is " << x << endl;
}

void print(STACK s)
{
    int i;
    if (empty(&s))
    {
        cout << "Stack empty" << endl;
        return;
    }
    cout << "Stack elements:" << endl;
    for (i = s.top; i >= 0; i--)
        cout << s.items[i] << endl;
}
