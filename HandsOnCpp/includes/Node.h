#pragma once
#ifndef NODE_H

struct Node
{
public:
    Node();
    Node(int iData);
    ~Node();
    int _data;
    Node* _left;
    Node* _right;
};
#endif // !NODE_H