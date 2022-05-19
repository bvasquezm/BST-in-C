#pragma once

typedef struct node Node;

typedef struct node
{
    // type: {0: black | 1: red}
    // value: node's numerical value
    // left: pointer to node's left child
    // right: pointer to node's right child
    // parent: pointer to node's parent
    int type;
    int value;
    Node* left;
    Node* right;
    Node* parent;
} Node;

Node* create_node(int value);

void print_tree(Node* node);
Node* find_root (Node* node);
void insert_node(Node* root, Node* new_node);

void order_tree(Node* node);
void rotation(Node* gparent, Node* parent, bool caso);
void change_colors(Node* node, Node* uncle);
bool parent_relation(Node* node);

