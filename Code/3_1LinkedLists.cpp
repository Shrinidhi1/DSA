#include <iostream>
#include <cstring>
using namespace std;

#define MAXSIZE 15

// Declaring structure
struct NODE
{
    int num;
    char info[MAXSIZE];
    NODE *next;
};

// Pointer to initialize
NODE *start = NULL;

// Declaring functions
NODE *SLLcreateNode();
void SLLdisplayList();
void SLLinsertNodeAtBeginning();
void SLLinsertNodeAtEnd();
void SLLinsertNodeAtPosition();
void SLLdeleteAtBeginning();
void SLLdeleteAtend();
void SLLdeleteAtPosition();
void SLLsearch();
void SLLsortList();

int main()
{
    int choice;

    while (true)
    {
        // Choices available
        cout << "\n1.Create";
        cout << "\n2.Display";
        cout << "\n3.Insert at the beginning";
        cout << "\n4.Insert at the end";
        cout << "\n5.Insert at specified position";
        cout << "\n6.Delete from beginning";
        cout << "\n7.Delete from the end";
        cout << "\n8.Delete from specified position";
        cout << "\n9.Search";
        cout << "\n10.Sort list";
        cout << "\n11.Exit";
        cout << "\nEnter your choice: ";

        cin >> choice;

        // Switch to choose functions
        switch (choice)
        {
        case 1:
            start = SLLcreateNode();
            break;
        case 2:
            SLLdisplayList();
            break;
        case 3:
            SLLinsertNodeAtBeginning();
            break;
        case 4:
            SLLinsertNodeAtEnd();
            break;
        case 5:
            SLLinsertNodeAtPosition();
            break;
        case 6:
            SLLdeleteAtBeginning();
            break;
        case 7:
            SLLdeleteAtend();
            break;
        case 8:
            SLLdeleteAtPosition();
            break;
        case 9:
            SLLsearch();
            break;
        case 10:
            SLLsortList();
            break;
        case 11:
            exit(0);
            break;
        default:
            cout << "\n Incorrect Choice";
            break;
        }
    }
    return 0;
}

// To create a node
NODE *SLLcreateNode()
{
    NODE *temp, *ptr;
    temp = new NODE;

    if (temp == NULL)
    {
        cout << "\nNo Memory Space";
        exit(0);
    }
    cout << "\nEnter the node data: ";
    cin >> temp->num;
    cout << "\nEnter the node info: ";
    cin >> temp->info;
    temp->next = NULL;
    if (start == NULL)
        start = temp;
    else
    {
        ptr = start;
        while (ptr->next != NULL)
            ptr = ptr->next;
        ptr->next = temp;
    }
}

// To display list
void SLLdisplayList()
{
    NODE *ptr;
    if (start == NULL)
    {
        cout << "\nList is empty";
        exit(0);
    }
    else
    {
        ptr = start;
        cout << "\nThe List elements are";
        while (ptr != NULL)
        {
            cout << endl << ptr->num;
            cout << " " << ptr->info;
            ptr = ptr->next;
        }
    }
}

// To insert node at beginning
void SLLinsertNodeAtBeginning()
{
    NODE *temp = new NODE; 
    if (temp == NULL)
    {
        cout << "\nNo Memory Space";
        exit(0);
    }
    cout << "\nEnter the data value for the node: ";
    cin >> temp->num;
    cout << "Enter info for the node: ";
    cin >> temp->info;
    temp->next = NULL;
    if (start == NULL)
    {
        start = temp;
    }
    else
    {
        temp->next = start;
        start = temp;
    }
}

// To insert node at end
void SLLinsertNodeAtEnd()
{
    NODE *temp = new NODE;
    if (temp == NULL)
    {
        cout << "\nNo Memory Space:n";
        exit(0);
    }
    cout << "\nEnter the data value for the node: ";
    cin >> temp->num;
    cout << "\nEnter the info for the node: ";
    cin >> temp->info;
    temp->next = NULL;
    if (start == NULL)
    {
        start = temp;
    }
    else
    {
        NODE *ptr = start;
        while (ptr->next != nullptr)
        {
            ptr = ptr->next;
        }
        ptr->next = temp;
    }
}

// To insert node at a specific position
void SLLinsertNodeAtPosition()
{
    NODE *ptr, *temp;
    int i, pos;
    temp = new NODE;
    if (temp == NULL)
    {
        cout << "\nNo Memory Space";
        exit(0);
    }
    cout << "\nEnter the position for the new node to be inserted";
    cin >> pos;
    cout << "\nEnter the data value of the node: ";
    cin >> temp->num;
    cout << "\nEnter the info for the node: ";
    cin >> temp->info;

    temp->next = NULL;
    if (pos == 0)
    {
        temp->next = start;
        start = temp;
    }
    else
    {
        for (i = 0, ptr = start; i < pos - 1; i++)
        {
            ptr = ptr->next;
            if (ptr == NULL)
            {
                cout << "\nPosition not found";
                exit(0);
            }
        }
        temp->next = ptr->next;
        ptr->next = temp;
    }
}

// To delete node at beginning
void SLLdeleteAtBeginning()
{
    NODE *ptr;
    if (start == NULL)
    {
        cout << "\nList is Empty:n";
        exit(0);
    }
    else
    {
        ptr = start;
        start = start->next;
        cout << "\nThe deleted element is : " << ptr->num << " " << ptr->info;
        delete ptr;
    }
}

// To delete node at end
void SLLdeleteAtend()
{
    NODE *temp, *ptr;
    if (start == NULL)
    {
        cout << "\nList is Empty";
        exit(0);
    }
    else if (start->next == NULL)
    {
        ptr = start;
        start = NULL;
        cout << "\nThe deleted element is: " << ptr->num << " " << ptr->info;
        free(ptr);
    }
    else
    {
        ptr = start;
        while (ptr->next->next != NULL)
        {
            ptr = ptr->next;
        }

        cout << "\nThe deleted element is: " << ptr->next->num << " " << ptr->next->info;
        ptr->next = NULL;
    }
}

// To delete node at a specific position
void SLLdeleteAtPosition()
{
    int i, pos;
    NODE *temp, *ptr;
    if (start == NULL)
    {
        cout << "\nThe List is Empty";
        exit(0);
    }
    else
    {
        cout << "\nEnter the position of the node to be deleted";
        cin >> pos;
        if (pos == 0)
        {
            ptr = start;
            start = start->next;
            cout << "\nThe deleted element is: " << ptr->num << " " << ptr->info;
            free(ptr);
        }
        else
        {
            ptr = start;
            for (i = 0; i < pos; i++)
            {
                temp = ptr;
                ptr = ptr->next;
                if (ptr == NULL)
                {
                    cout << "\nPosition not Found";
                    exit(0);
                }
            }
            temp->next = ptr->next;
            cout << "\nThe deleted element is: " << ptr->num << " " << ptr->info;
            free(ptr);
        }
    }
}

void SLLsearch()
{
    NODE *ptr;
    int item, i = 0, flag;
    ptr = start;
    if (ptr == NULL)
    {
        cout << "\nEmpty List\n";
        exit(0);
    }
    else
    {
        cout << "\nEnter item which you want to search?\n";
        cin >> item;
        while (ptr != NULL)
        {
            if (ptr->num == item)
            {
                cout << "item " << ptr->num << " found at location " << i + 1 << " has info: " << ptr->info;
                flag = 0;
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
            cout << "Item not found\n";
        }
    }
}

// Increasing order
void SLLsortList()
{
    NODE *current = start, *index = NULL;
    int temp;

    if (start == NULL)
        return;
    else
    {
        while (current != NULL)
        {
            index = current->next;
            while (index != NULL)
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
        }
    }
}