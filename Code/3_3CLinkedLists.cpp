#include <iostream>
#include <cstdlib>
#include <cstring>

using namespace std;

#define MAXSIZE 15

// Declaring structure
typedef struct node
{
    int num;
    char info[MAXSIZE];
    struct node *next;
} NODE;

// Pointer to last node in the list
NODE *head;

// Declaring functions
NODE *CSLLcreateNode();
NODE *CSLLinsertNodeAtBeginning();
NODE *CSLLinsertNodeAtEnd();
NODE *CSLLinsertNodeAtPosition();
NODE *CSLLdeleteNodeAtBeginning();
NODE *CSLLdeleteNodeAtEnd();
NODE *CSLLdeleteNodeAtPosition();
NODE *CSLLdisplayList();
void CSLLsearchNode();
void CSLLsortList();

int main()
{
    int choice;
    while (true)
    {
        // Choices available
        cout << "\n1.Create.";
        cout << "\n2.Insert at the beginning";
        cout << "\n3.Insert at the end";
        cout << "\n4.Insert at specified position";
        cout << "\n5.Delete from beginning";
        cout << "\n6.Delete from the end";
        cout << "\n7.Delete from specified position";
        cout << "\n8.Search data";
        cout << "\n9.Sort data";
        cout << "\n10.Display";
        cout << "\n11.Exit";
        cout << "\n----------------------------------------";
        cout << "\nEnter your choice: ";
        cin >> choice;

        // Switch to choose functions
        switch (choice)
        {
        case 1:
            CSLLcreateNode();
            break;
        case 2:
            CSLLinsertNodeAtBeginning();
            break;
        case 3:
            CSLLinsertNodeAtEnd();
            break;
        case 4:
            CSLLinsertNodeAtPosition();
            break;
        case 5:
            CSLLdeleteNodeAtBeginning();
            break;
        case 6:
            CSLLdeleteNodeAtEnd();
            break;
        case 7:
            CSLLdeleteNodeAtPosition();
            break;
        case 8:
            CSLLsearchNode();
            break;
        case 9:
            CSLLsortList();
            break;
        case 10:
            CSLLdisplayList();
            break;
        case 11:
            exit(0);
            break;
        default:
            std::cout << "\nInvalid Choice";
            break;
        }
    }
    return 0;
}

// To create node
NODE *CSLLcreateNode()
{
    NODE *newNode = new NODE;
    if (newNode == NULL)
    {
        cout << "\nMemory not allocated";
        exit(0);
    }
    cout << "\nEnter the node data: ";
    cin >> newNode->num;
    cout << "\nEnter the node info: ";
    cin >> newNode->info;
    head = newNode;
    newNode->next = head;
    return newNode;
}

// To insert a node at the beginning of the list
NODE *CSLLinsertNodeAtBeginning()
{
    NODE *ptr, *temp;
    ptr = new NODE();
    if (ptr == NULL)
    {
        cout << "\nOVERFLOW";
    }
    else
    {
        cout << "\nEnter the node data: ";
        cin >> ptr->num;
        cout << "\nEnter the node info: ";
        cin >> ptr->info;
        if (head == NULL)
        {
            head = ptr;
            ptr->next = head;
        }
        else
        {
            temp = head;
            while (temp->next != head)
                temp = temp->next;
            ptr->next = head;
            temp->next = ptr;
            head = ptr;
        }
    }
    return head;
}

// To insert node at the end of the list
NODE *CSLLinsertNodeAtEnd()
{
    NODE *ptr, *temp;
    ptr = new NODE();
    if (ptr == NULL)
    {
        cout << "\nMemory not allocated";
    }
    else
    {
        cout << "\nEnter the node data: ";
        cin >> ptr->num;
        cout << "\nEnter the node info: ";
        cin >> ptr->info;
        if (head == NULL)
        {
            head = ptr;
            ptr->next = head;
        }
        else
        {
            temp = head;
            while (temp->next != head)
            {
                temp = temp->next;
            }
            temp->next = ptr;
            ptr->next = head;
        }
    }
    return head;
}

// To insert node at a specific position
NODE *CSLLinsertNodeAtPosition()
{
    NODE *newNode = new NODE();
    NODE *current;
    int i, pos;
    cout << "\nEnter the position: ";
    cin >> pos;

    if (head == NULL)
    {
        cout << "List is empty.\n";
    }
    else if (pos == 1)
    {
        return CSLLinsertNodeAtBeginning();
    }
    else
    {
        cout << "\nEnter the node data: ";
        cin >> newNode->num;
        cout << "\nEnter the node info: ";
        cin >> newNode->info;

        current = head;
        for (i = 2; i <= pos - 1; i++)
        {
            current = current->next;
        }

        /* Links new node with node ahead of it and previous to it*/
        newNode->next = current->next;
        current->next = newNode;
    }
    return head;
}

// To delete node at beginning of the list
NODE *CSLLdeleteNodeAtBeginning()
{
    NODE *ptr;
    if (head == NULL)
    {
        cout << "\nUNDERFLOW" << endl;
    }
    else if (head->next == head)
    {
        head = NULL;
        free(head);
    }
    else
    {
        ptr = head;
        while (ptr->next != head)
            ptr = ptr->next;
        ptr->next = head->next;
        free(head);
        head = ptr->next;
    }
    return head;
}

NODE *CSLLdeleteNodeAtEnd()
{
    NODE *ptr, *preptr;
    if (head == NULL)
    {
        cout << "\nUNDERFLOW";
    }
    else if (head->next == head)
    {
        head = NULL;
        free(head);
    }
    else
    {
        ptr = head;
        while (ptr->next != head)
        {
            preptr = ptr;
            ptr = ptr->next;
        }
        preptr->next = ptr->next;
        free(ptr);
    }

    return head;
}

// To delete node at a specific position
NODE *CSLLdeleteNodeAtPosition()
{
    NODE *temp = head;
    NODE *temp1 = NULL;

    if (head == NULL)
    {
        cout << "\n List is empty" << endl;
        return NULL;
    }
    else
    {
        int i = 1, pos;
        cout << "\n Enter the position to be deleted: ";
        cin >> pos;

        while (i < pos)
        {
            temp1 = temp;
            temp = temp->next;
            i++;
        }
        temp1->next = temp->next;
        free(temp);
        return head;
    }
}

// To display the list
NODE *CSLLdisplayList()
{
    NODE *ptr;
    ptr = head;
    if (head == NULL)
    {
        cout << "\nnothing to print";
    }
    else
    {
        while (ptr->next != head)
        {
            cout << ptr->num << " " << ptr->info << endl;
            ptr = ptr->next;
        }
        cout << ptr->num << " " << ptr->info << endl;
    }
}

void CSLLsearchNode()
{
    NODE *ptr;
    int item, flag = 1;
    ptr = head;
    if (ptr == NULL)
    {
        cout << "\nEmpty List\n";
    }
    else
    {
        cout << "\nEnter item which you want to search?\n";
        cin >> item;
        if (head->num == item)
        {
            cout << "item found is " << head->num << " " << head->info;
            flag = 0;
        }
        else
        {
            while (ptr->next != head)
            {
                if (ptr->num == item)
                {
                    cout << "item found is " << ptr->num << " " << ptr->info << " ";
                    flag = 0;
                    break;
                }
                else
                {
                    flag = 1;
                }
                ptr = ptr->next;
            }
        }
        if (flag != 0)
        {
            cout << "Item not found\n";
        }
    }
}

void CSLLsortList()
{
    NODE *current = head, *index = NULL;
    int temp;
    if (head == NULL)
    {
        printf("List is empty");
    }
    else
    {
        do
        {
            index = current->next;
            while (index != head)
            {
                if (current->num > index->num)
                {
                    temp = current->num;
                    current->num = index->num;
                    index->num = temp;
                }
                index = index->next;
            }
            current = current->next;
        } while (current->next != head);
    }
}