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
    Node *next;
};

void insertBegin(Node **head, int data)
{
    Node *new_node = new Node();
    new_node->data = data;
    new_node->next = (*head);
    (*head) = new_node;
}

void insertAfter(Node *prev_node, int data)
{
    if (prev_node == NULL)
    {
        cout << "The given previous node cannot be NULL";
        return;
    }

    Node *new_node = new Node();
    new_node->data = data;
    new_node->next = prev_node->next;
    prev_node->next = new_node;
}

void insertEnd(Node **head, int data)
{
    Node *new_node = new Node();
    new_node->data = data;
    Node *last = *head;
    new_node->next = NULL;

    if (*head == NULL)
    {
        *head = new_node;
        return;
    }

    while (last->next != NULL)
    {
        last = last->next;
    }

    last->next = new_node;
}

void deleteBegin(Node **head)
{
    Node *temp = *head;
    *head = (*head)->next;
    free(temp);
}

void deleteEnd(Node **head)
{
    if (*head == NULL)
    {
        return;
    }

    if ((*head)->next == NULL)
    {
        delete *head;
        return;
    }

    Node *second_last = *head;
    while (second_last->next->next != NULL)
    {
        second_last = second_last->next;
    }
    delete (second_last->next);
    second_last->next = NULL;
}

void deletePos(Node **head, int pos)
{
    Node *temp;
    Node *prev;
    temp = *head;
    prev = *head;
    for (int i = 0; i < pos; i++)
    {
        if (i == 0 && pos == 1)
        {
            *head = (*head)->next;
            free(temp);
        }
        else
        {
            if (i == pos - 1 && temp)
            {
                prev->next = temp->next;
                free(temp);
            }
            else
            {
                prev = temp;
                if (prev == NULL)
                    break;
                temp = temp->next;
            }
        }
    }
}

void deleteKey(Node **head, int key)
{
    Node *temp;

    if ((*head)->data == key)
    {
        temp = *head;
        *head = (*head)->next;
        free(temp);
    }
    else
    {
        Node *current = *head;
        while (current->next != NULL)
        {
            if (current->next->data == key)
            {
                temp = current->next;
                current->next = current->next->next;
                free(temp);
                break;
            }
            else
            {
                current = current->next;
            }
        }
    }
}

void reverse1(Node **head)
{
    Node *temp = NULL;
    Node *prev = NULL;
    Node *current = (*head);
    while (current != NULL)
    {
        temp = current->next;
        current->next = prev;
        prev = current;
        current = temp;
    }
    (*head) = prev;
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
    insertBegin(&ll, 2);
    insertBegin(&ll, 5);
    insertAfter(ll, 4);
    insertEnd(&ll, 7);
    deletePos(&ll, 2);
    insertEnd(&ll, 1);
    printList(ll);
    reverse1(&ll);
    cout << endl;
    printList(ll);
    deleteKey(&ll, 7);
    deleteBegin(&ll);
    deleteEnd(&ll);
    cout << endl;
    printList(ll);
    return 0;
}