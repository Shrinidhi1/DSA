#include <iostream>
#include <cmath>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *prev;
    Node *next;
};

void insertAtBegin(Node **head, int newData)
{
    Node *new_node = new Node();
    new_node->data = newData;
    new_node->next = *head;
    new_node->prev = NULL;
    if (*head != NULL)
    {
        (*head)->prev = new_node;
    }
    *head = new_node;
}

void insertAfter(Node *prev_node, int newData)
{
    if (prev_node == NULL)
    {
        cout << "The given previous node cannot be NULL";
        return;
    }

    Node *new_node = new Node();
    new_node->data = newData;
    new_node->next = prev_node->next;
    prev_node->next = new_node;
    new_node->prev = prev_node;
    if (new_node->next != NULL)
    {
        new_node->next->prev = new_node;
    }
}

void insertAtEnd(Node **head, int newData)
{
    Node *new_node = new Node();
    Node *last = *head;
    new_node->data = newData;
    new_node->next = NULL;
    if (*head == NULL)
    {
        new_node->prev = NULL;
        *head = new_node;
        return;
    }

    while (last->next != NULL)
    {
        last = last->next;
    }

    last->next = new_node;
    new_node->prev = last;
}

void deleteBegin(Node **head)
{
    if (head != NULL)
    {
        Node *temp = *head;
        *head = (*head)->next;
        free(temp);
        if ((*head) != NULL)
        {
            (*head)->prev = NULL;
        }
    }
}

void deleteEnd(Node **head)
{
    if (*head != NULL)
    {
        if ((*head)->next == NULL)
        {
            *head = NULL;
        }
        else
        {
            Node *temp = *head;
            while (temp->next->next != NULL)
            {
                temp = temp->next;
            }
            Node *lastNode = temp->next;
            temp->next = NULL;
            free(lastNode);
        }
    }
}

void deletePos(Node **head, int pos)
{

    if (pos < 1)
    {
        cout << "Position should be >= 1." << endl;
    }
    else if (pos == 1 && (*head) != NULL)
    {

        Node *nodeToDelete = *head;
        *head = (*head)->next;
        free(nodeToDelete);
        if ((*head) != NULL)
            (*head)->prev = NULL;
    }
    else
    {
        Node *temp = *head;
        for (int i = 1; i < pos - 1; i++)
        {
            if (temp != NULL)
            {
                temp = temp->next;
            }
        }
        if (temp != NULL && temp->next != NULL)
        {
            Node *nodeToDelete = temp->next;
            temp->next = temp->next->next;
            if (temp->next->next != NULL)
            {
                temp->next->next->prev = temp->next;
            }
            free(nodeToDelete);
        }
        else
        {
            cout << "\nThe node is already null.";
        }
    }
}

void deleteKey(Node **head, int key)
{
    Node *nodeToDelete;
    while ((*head) != NULL && (*head)->data == key)
    {
        nodeToDelete = *head;
        *head = (*head)->next;
        free(nodeToDelete);
        if ((*head) != NULL)
        {
            (*head)->prev = NULL;
        }
    }

    Node *temp = *head;
    if (temp != NULL)
    {
        while (temp->next != NULL)
        {
            if (temp->next->data == key)
            {
                nodeToDelete = temp->next;
                temp->next = temp->next->next;
                if (temp->next != NULL)
                    temp->next->prev = temp;
                free(nodeToDelete);
            }
            else
            {
                temp = temp->next;
            }
        }
    }
}

void reverse1(Node **head)
{
    Node *temp = NULL;
    Node *current = *head;

    while (current != NULL)
    {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        current = current->prev;
    }

    if (temp != NULL)
        *head = temp->prev;
}

void printList(Node *node)
{
    if (node == NULL)
    {
        cout << "Empty List" << endl;
    }
    while (node != NULL)
    {
        cout << node->data << " ";
        node = node->next;
    }
}

int main()
{
    Node *ll = NULL;
    insertAtBegin(&ll, 5);
    insertAtBegin(&ll, 2);
    insertAfter(ll->next, 7);
    insertAtEnd(&ll, 1);
    printList(ll);
    cout << endl;
    reverse1(&ll);
    printList(ll);
    cout << endl;
    deleteBegin(&ll);
    deleteEnd(&ll);
    deletePos(&ll, 1);
    deleteKey(&ll, 7);
    printList(ll);
    return 0;
}
