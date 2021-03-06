#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#include "node.h"

Node* create_node(int value) 
{
    Node* node = malloc(sizeof(Node));

    *node = (Node) {
    .type = 1,          // starts as red node
    .value = value,
    .left = NULL,
    .right = NULL,
    .parent = NULL,
    };
    return node;
}

const char* node_type(Node* node) {
    if (node->type == 0) {
        return "Black";
    } else {
        return "Red";
    }
}

void print_tree(Node* node) {
    if (!node) { return; }
    printf("%d %s\n", node->value, node_type(node));
    if (node->left) { print_tree(node->left); }
    if (node->right) { print_tree(node->right); }
}

Node* find_root (Node* node) {
    while (node->parent) {
        node = node->parent;
    } return node;
}

void insert_node(Node* root, Node* new_node) {
    Node* actual_node = root;

    while(actual_node) {
        if (new_node->value < actual_node->value)
            if (!actual_node->left) { 
                actual_node->left = new_node; 
                new_node->parent = actual_node;
                break;
            }
            else { actual_node = actual_node->left; }
        else if (new_node->value > actual_node->value)
            if (!actual_node->right) { 
                actual_node->right = new_node; 
                new_node->parent = actual_node;
                break; 
            }
            else { actual_node = actual_node->right; }
    }
    order_tree(new_node);
}

void order_tree(Node* node) {
    Node* parent = node->parent;
    Node* gparent = parent->parent;
    Node* uncle = malloc(sizeof(Node));
    if (gparent) {
        if (gparent->left == parent) { 
            uncle = gparent->right; 
            if (uncle == NULL) {
                rotation(gparent, parent, false);
            } else if (uncle->type == 1) {
                change_colors(node, uncle);
            } else if (uncle->type == 0) {
                return;
            }
        } else if (gparent->right == parent) {
            uncle = gparent->left;
            if (uncle == NULL) {
                rotation(gparent, parent, true);
            } else if (uncle->type == 1) {
                change_colors(node, uncle);
            } else if (uncle->type == 0) {
                return;
            }
        }
    }
    return;
}

void rotation(Node* gparent, Node* parent, bool caso) {
    // Left rotation
    if (caso) {
        if (parent->right) {
            if (gparent->parent) {
                if (parent_relation(gparent)) {
                    gparent->parent->left = parent;
                } else {
                    gparent->parent->right = parent;}
            }
            parent->left = gparent;
            gparent->right = NULL;
            parent->parent = gparent->parent;
            gparent->parent = parent;
            parent->type = 0;
            gparent->type = 1;
        } else if (parent->left) {
            Node* node = parent->left;
            parent->parent = node;
            parent->left = NULL;
            node->right = parent;
            gparent->right = node;
            node->parent = gparent;
            rotation(gparent, node, true);        
        }
    }
    // Right rotation
    else { 
        if (parent->left) {
            if (gparent->parent) {
                if (parent_relation(gparent)) {
                    gparent->parent->left = parent;
                } else {
                    gparent->parent->right = parent;}
            }
            parent->right = gparent;
            gparent->left = NULL;
            parent->parent = gparent->parent;
            gparent->parent = parent;
            parent->type = 0;
            gparent->type = 1;
        } else if (parent->right) {
            Node* node = parent->right;
            parent->parent = node;
            parent->right = NULL;
            node->left = parent;
            gparent->left = node;
            node->parent = gparent;
            rotation(gparent, node, false);        
        } 
    }
}

void change_colors(Node* node, Node* uncle) {
    Node* parent = node->parent;
    Node* gparent = parent->parent;
    parent->type = 0;
    uncle->type = 0;
    gparent->type = 1;
    order_tree(node);   // Check for possible changes needed
}

bool parent_relation(Node* node) {
    if (node->parent->left == node) {
        return true; // Left child
    } else {
        return false; // Right child
    }
}