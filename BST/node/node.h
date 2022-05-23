#pragma once

typedef struct node Node;

typedef struct node
{
    // value: node's numerical value
    // left: pointer to node's left child
    // right: pointer to node's right child
    int value;
    Node* left;
    Node* right;
} Node;

Node* create_node(int value);

void print_tree(Node* node);
void print_leftside(Node* node);
void print_rightside(Node* node); 
void insert_node(Node* root, Node* new_node);


