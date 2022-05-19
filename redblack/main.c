#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#include "node/node.h"

int main() 
{
    int N = 2;
    int tree_array[2] = {1, 2};
    
    Node* root = create_node(3);
    root->type = 0; // root node has to be black
    Node* new_node = malloc(sizeof(Node));

    for (int i = 0; i < N; i++) {
        new_node = create_node(tree_array[i]);
        insert_node(root, new_node);
    }
    print_tree(root->parent);
    printf("\n");
    return 0;
}