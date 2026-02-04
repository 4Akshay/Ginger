#include<iostream>
#include<queue>
#include "Node.h"

Node* BuildTree(Node* root)
{
    int input;
    std::cout << "Enter the numeric value: ";
    std::cin >> input;
    if (input == -1)
        return nullptr;
    std::cout << std::endl;
    root = new Node(input);
    std::cout << "Enter the data for left node 0f " << input << std::endl;
    root->_left = BuildTree(root->_left);
    std::cout << "Enter the data for right node of " << input << std::endl;
    root->_right = BuildTree(root->_right);
    return root;
}
void PrintTree(Node* iNode)
{
    if (!iNode)
        return;
    std::cout << iNode->_data << std::endl;
    PrintTree(iNode->_left);
    PrintTree(iNode->_right);
    return;
}

void LevelOrderTraversal(Node* iNode)
{
    std::queue<Node*> store;
    store.push(iNode);
    store.push(nullptr);
    while (!store.empty())
    {
        Node* temp = store.front();
        store.pop();
        if (temp == nullptr)
        {
            //check if queue is emptry or not. if it is not empty then push nullptr as separator.
            std::cout << std::endl;
            if (!store.empty())
                store.push(nullptr);
        }
        else {
            //do print node data and push child node in queue
            std::cout << temp->_data << " ";
            if (temp->_left)
                store.push(temp->_left);
            if (temp->_right)
                store.push(temp->_right);
        }
    }
    return;
}

int main()
{
    Node* node = nullptr;
    node = BuildTree(node);
    LevelOrderTraversal(node);
    PrintTree(node);
    return 0;
}