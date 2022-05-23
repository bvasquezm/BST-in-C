#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#include "node/node.h"

int main() 
{
    int N = 5;
    int tree_array[5] = {1, 2, 5, 4, 6};

    //          3               --> 0 (root)
    //      1       5           --> 1
    //        2   4   6         --> 2
    
    Node* root = create_node(3);
    Node* new_node = malloc(sizeof(Node));

    for (int i = 0; i < N; i++) {
        new_node = create_node(tree_array[i]);
        insert_node(root, new_node);
    }
    print_leftside(root);       
    print_rightside(root->right);
    printf("\n");
    return 0;
}