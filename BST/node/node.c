#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#include "node.h"

Node* create_node(int value) 
{
    Node* node = malloc(sizeof(Node));

    *node = (Node) {
    .value = value,
    .left = NULL,
    .right = NULL,
    };
    return node;
}

// prints all tree nodes
void print_tree(Node* node) {
    if (!node) { return; }
    printf("%d", node->value);
    if (node->left) { print_tree(node->left); }
    if (node->right) { print_tree(node->right); }
}

// prints tree left side view
void print_leftside(Node* node) {
    if (!node) { return; }
    printf("%d", node->value);
    if (node->left) { print_leftside(node->left); }
}

// prints tree right side view
void print_rightside(Node* node) {
    if (!node) { return; }
    printf("%d", node->value);
    if (node->right) { print_rightside(node->right); }
}

void insert_node(Node* root, Node* new_node) {
    Node* actual_node = root;

    while(actual_node) {
        if (new_node->value < actual_node->value)
            if (!actual_node->left) { 
                actual_node->left = new_node; 
                break;
            }
            else { actual_node = actual_node->left; }
        else if (new_node->value > actual_node->value)
            if (!actual_node->right) { 
                actual_node->right = new_node; 
                break; 
            }
            else { actual_node = actual_node->right; }
    }
}