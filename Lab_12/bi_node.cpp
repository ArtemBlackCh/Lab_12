#include "bi_node.h"
#include <iostream>

BiNode* BiNode::get_back(BiNode* F)
{
    BiNode* temp = F;

    while (temp->next)
    {
        temp = temp->next;
    }

    return temp;
}

BiNode* BiNode::push_back(BiNode* F, int x)
{
    BiNode* nodeBack = get_back(F);
    BiNode* nodeNew = new BiNode(x);

    nodeNew->prev = nodeBack;
    nodeBack->next = nodeNew;

    return F;
}

BiNode* BiNode::push_front(BiNode* F, int x)
{
    BiNode* nodeNew = new BiNode(x);
    
    nodeNew->next = F;
    F->prev = nodeNew;

    return nodeNew;
}

BiNode* BiNode::insert(BiNode* F, int x, BiNode* node)
{
    BiNode* nodePrev = node->prev;

    if (nodePrev)
    { 
        BiNode* nodeNew = new BiNode(x);

        nodePrev->next = nodeNew;

        nodeNew->next = node;
        nodeNew->prev = nodePrev;

        node->prev = nodeNew;
    }
    else
    {
        F = push_front(F,x);
    }
    
    return F;
}

BiNode* BiNode::insert(BiNode* F, BiNode* node, int x)
{
    BiNode* nodeNext = node->next;

    if (nodeNext)
    {
        BiNode* nodeNew = new BiNode(x);

        nodeNext->prev = nodeNew;

        nodeNew->next = nodeNext;
        nodeNew->prev = node;

        node->next = nodeNew;
    }
    else
    {
        F = push_back(F, x);
    }

    return F;
}

BiNode* BiNode::remove(BiNode* F, BiNode* node)
{
    BiNode* nodeNext = node->next;
    BiNode* nodePrev = node->prev;

    if (nodeNext && nodePrev)
    {
        nodeNext->prev = nodePrev;
        nodePrev->next = nodeNext;
    }
    else if (nodeNext)
    {
        nodeNext->prev = nullptr;
        F = nodeNext;
    }
    else if(nodePrev)
    {
        nodePrev->next = nullptr;
    }
    else
    {
        F = nullptr;
    }
    
    delete node;

    return F;
}

void BiNode::forward_view(BiNode* F)
{
    BiNode* temp = F;

    while (temp)
    {
        std::cout << temp->data << " ";
        temp = temp->next;
    }
    std::cout << '\n';
}

void BiNode::reverse_view(BiNode* F)
{
    BiNode* temp = get_back(F);

    while (temp)
    {
        std::cout << temp->data << " ";
        temp = temp->prev;
    }
    std::cout << '\n';
}

BiNode* BiNode::clear(BiNode* F)
{
    BiNode* temp = F;

    while (temp)
    {
        F = temp;
        temp = temp->next;

        delete F;
    }

    return nullptr;
}

BiNode* BiNode::find(BiNode* F, int key)
{
    BiNode* temp = F;

    while (temp)
    {
        if (temp->data == key)
        {
            return temp;
        }

        temp = temp->next;
    }

    return nullptr;
}

BiNode* BiNode::get(BiNode* F, int index)
{
    if (index >= 0)
    {
        BiNode* temp = F;

        for (int i = 0; i < index; i++)
        {
            temp = temp->next;

            if (!temp)
            {
                return nullptr;
            }
        }

        return temp;
    }
    else
    {
        return nullptr;
    }
}

BiNode* BiNode::splice_in(BiNode* F1, BiNode* F2, int index)
{
    if (index == -1)
    {
        BiNode* F2Back = F2->get_back(F2);

        F2Back->next = F1;
        F1->prev = F2Back;

        return F2;
    }
    else
    {
        BiNode* nodeIndex = F1->get(F1, index);
        BiNode* nodeNext = nodeIndex->next;
        BiNode* F2Back = F2->get_back(F2);

        if (nodeNext)
        {
            nodeNext->prev = F2Back;
            nodeIndex->next = F2;

            F2->prev = nodeIndex;
            F2Back->next = nodeNext;

        }
        else
        {
            nodeIndex->next = F2;
            F2->prev = nodeIndex;
        }
        
        return F1;
    }
}

BiNode* BiNode::splice_out(BiNode* F1, BiNode* F2, int index1, int index2)
{
    BiNode* nodeIndex1 = F1->get(F1, index1);
    BiNode* nodeIndex2 = F1->get(F1, index2);

    if (nodeIndex1 && nodeIndex2 && index1 <= index2)
    {
        BiNode* nodePriv = nodeIndex1->prev;
        BiNode* nodeNext = nodeIndex2->next;
        BiNode* F2Back = F2->get_back(F2);

        if (nodePriv && nodeNext)
        {
            nodePriv->next = nodeNext;
            nodeNext->prev = nodePriv;
        }
        else if (nodePriv)
        {
            nodePriv->next = nullptr;
        }
        else if (nodeNext)
        {
            nodeNext->prev = nullptr;
            F1 = nodeNext;
        }
        else
        {
            F1 = nullptr;
        }

        nodeIndex1->prev = F2Back;
        nodeIndex2->next = nullptr;
        F2Back->next = nodeIndex1;
    }
    
    return F1;
}

void BiNode::swap(BiNode* N1, BiNode* N2)
{
    if (N1 && N2)
    {
        std::swap(N1->data, N2->data);
    }
}

BiNode* BiNode::sort(BiNode* F)
{
    int size = 1;

    BiNode* Last = F;

    while (Last->next)
    {
        Last = Last->next;
        size++;
    }

    BiNode* min;
    BiNode* temp;
    int workSize = size;
    
    for(int i = 0; i < size; i++)
    {
        temp = F;
        min = F;

        for (int j = 0; j < workSize; j++)
        {
            if (temp->data < min->data)
            {
                min = temp;
            }

            temp = temp->next;
        }

        swap(Last, min);

        Last = Last->prev;
        workSize--;
    }

    return F;
}

int BiNode::size(BiNode* F)
{
    int size = 1;

    BiNode* Last = F;

    while (Last->next)
    {
        Last = Last->next;
        size++;
    }

    return size;
}
