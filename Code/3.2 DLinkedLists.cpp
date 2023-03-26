#include <iostream>
using namespace std;

typedef struct node
{
    int data;
    char info[15];
    struct node *next;
    struct node *prev;
} NODE;

NODE *head;

void DLLinsertAtBeginning();
void DLLinsertAtLast();
void DLLinsertAtPosition();
void DLLdeleteAtBeginning();
void DLLdeleteAtLast();
void DLLdeleteSpecific();
void DLLdeleteAtPosition();
void DLLsort();
void DLLdisplay();
void DLLsearch();

int main()
{
    int choice;
    while (1)
    {
        cout << "\n===============================================";
        cout << "\n1.Insert in beginning";
        cout << "\n2.Insert at last";
        cout << "\n3.Insert at any random location";
        cout << "\n4.Delete from Beginning";
        cout << "\n5.Delete from last";
        cout << "\n6.Delete by data";
        cout << "\n7.Delete at position";
        cout << "\n8.Search";
        cout << "\n9.Sort";
        cout << "\n10.Display";
        cout << "\n11.Exit";
        cout << "\nEnter your choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            DLLinsertAtBeginning();
            break;
        case 2:
            DLLinsertAtLast();
            break;
        case 3:
            DLLinsertAtPosition();
            break;
        case 4:
            DLLdeleteAtBeginning();
            break;
        case 5:
            DLLdeleteAtLast();
            break;
        case 6:
            DLLdeleteSpecific();
            break;
        case 7:
            DLLdeleteAtPosition();
            break;
        case 8:
            DLLsearch();
            break;
        case 9:
            DLLsort();
            break;
        case 10:
            DLLdisplay();
            break;
        case 11:
            exit(0);
            break;
        default:
            cout << "Invalid Choice";
        }
    }
    return 0;
}

void DLLinsertAtBeginning()
{
    NODE *ptr;
    ptr = new NODE;
    if (ptr == NULL)
    {
        cout << "\nOVERFLOW";
    }
    else
    {
        cout << "Enter Item value: ";
        cin >> ptr->data;
        cout << "Enter Item info: ";
        cin >> ptr->info;

        if (head == NULL)
        {
            ptr->next = NULL;
            ptr->prev = NULL;
            head = ptr;
        }
        else
        {
            ptr->prev = NULL;
            ptr->next = head;
            head->prev = ptr;
            head = ptr;
        }
        cout << "\nNode inserted\n";
    }
}

void DLLinsertAtLast()
{
    NODE *ptr, *temp;
    ptr = new NODE;
    if (ptr == NULL)
    {
        cout << "\nOVERFLOW";
    }
    else
    {
        cout << "Enter Item value: ";
        cin >> ptr->data;
        cout << "Enter Item info: ";
        cin >> ptr->info;

        if (head == NULL)
        {
            ptr->next = NULL;
            ptr->prev = NULL;
            head = ptr;
        }
        else
        {
            temp = head;
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = ptr;
            ptr->prev = temp;
            ptr->next = NULL;
        }
    }
    cout << "\nNode inserted\n";
}

void DLLinsertAtPosition()
{
    NODE *ptr, *temp;
    int loc, i;
    ptr = new NODE();
    if (ptr == NULL)
    {
        cout << "\nOVERFLOW";
    }
    else
    {
        temp = head;
        cout << "Enter the location: ";
        cin >> loc;
        for (i = 0; i < loc; i++)
        {
            temp = temp->next;
            if (temp == NULL)
            {
                cout << "\nThere are less than " << loc << " elements";
                return;
            }
        }
        cout << "Enter Item value: ";
        cin >> ptr->data;
        cout << "Enter Item info: ";
        cin >> ptr->info;
        ptr->next = temp->next;
        ptr->prev = temp;
        temp->next = ptr;
        temp->next->prev = ptr;
        cout << "\nNode inserted";
    }
}

void DLLdeleteAtBeginning()
{
    NODE *ptr;
    if (head == NULL)
    {
        cout << "\nUNDERFLOW";
    }
    else if (head->next == NULL)
    {
        head = NULL;
        free(head);
        cout << "\nNode deleted\n";
    }
    else
    {
        ptr = head;
        head = head->next;
        head->prev = NULL;
        free(ptr);
        cout << "\nNode deleted\n";
    }
}

void DLLdeleteAtLast()
{
    NODE *ptr;
    if (head == NULL)
    {
        cout << "\nUNDERFLOW";
    }
    else if (head->next == NULL)
    {
        head = NULL;
        free(head);
        cout << "\nNode deleted\n";
    }
    else
    {
        ptr = head;
        if (ptr->next != NULL)
        {
            ptr = ptr->next;
        }
        ptr->prev->next = NULL;
        free(ptr);
        cout << "\nNode deleted\n";
    }
}

void DLLdeleteSpecific()
{
    NODE *ptr, *temp;
    int val;
    cout << "Enter the data of node to be deleted: ";
    cin >> val;
    ptr = head;
    while (ptr->data != val)
        ptr = ptr->next;

    if (ptr->next == NULL)
    {
        ptr->prev->next = NULL;
        free(ptr);
    }
    else
    {
        temp = ptr->prev;
        temp->next = ptr->next;
        ptr->next->prev = temp;
        free(ptr);
        cout << "Node deleted\n";
    }
}

void DLLdeleteAtPosition()
{
    NODE *temp;
    int i, position;
    cout << "Enter the position: ";
    cin >> position;
    temp = head;
    if (position == 1)
    {
        temp->next->prev = NULL;
        free(temp);
    }
    else
    {
        for (i = 0; i < position - 1; i++)
        {
            temp = temp->next;
        }
        if (temp != NULL)
        {
            if (temp->next != NULL)
            {
                temp->prev->next = temp->next;
                temp->next->prev = temp->prev;
                free(temp);
            }
            else
            {
                temp->prev->next = NULL;
                free(temp);
            }
        }
        else
        {
            cout << "Invalid position!\n";
        }
    }
}

void DLLdisplay()
{
    NODE *ptr;
    cout << "List: ";
    ptr = head;
    while (ptr != NULL)
    {
        cout << endl << ptr->data << " " << ptr->info;
        ptr = ptr->next;
    }
}

void DLLsearch()
{
    NODE *ptr;
    int item, i = 0, flag;
    ptr = head;
    if (ptr == NULL)
    {
        cout << "\nEmpty List\n";
    }
    else
    {
        cout << "\nEnter item which you want to search?\n";
        cin >> item;
        while (ptr != NULL)
        {
            if (ptr->data == item)
            {
                cout << "\nItem is " << ptr->data << " " << ptr->info;
                cout << "\nItem found at location " << i + 1;
                flag = 0;
                break;
            }
            else
            {
                flag = 1;
            }
            i++;
            ptr = ptr->next;
        }
        if (flag == 1)
        {
            cout << "\nItem not found\n";
        }
    }
}

void DLLsort()
{
    NODE *current = NULL, *index = NULL;
    int temp;
    if (head == NULL)
    {
        return;
    }
    else
    {
        for (current = head; current->next != NULL; current = current->next)
        {
            for (index = current->next; index != NULL; index = index->next)
            {
                if (current->data > index->data)
                {
                    temp = current->data;
                    current->data = index->data;
                    index->data = temp;
                }
            }
        }
    }
    cout << "Sorted";
}
