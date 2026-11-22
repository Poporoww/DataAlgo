#ifndef __STUDENT_H_
#define __STUDENT_H_

#include "map_bst.h"

template <typename KeyT, typename MappedT, typename CompareT>
int CP::map_bst<KeyT, MappedT, CompareT>::parity_score(int d) {
    int diff = 0;
    parity_score_helper(mRoot, d, diff);
    return abs(diff);
}

template <typename KeyT, typename MappedT, typename CompareT>
void CP::map_bst<KeyT, MappedT, CompareT>::parity_score_helper(node *current_node, int depth, int &parity_score){
    if(depth < 0) return;
    if(current_node == NULL) return;

    if(current_node->data.first % 2 == 1) parity_score++;
    else parity_score--;

    parity_score_helper(current_node->left, depth - 1, parity_score);
    parity_score_helper(current_node->right, depth - 1, parity_score);
}


#endif
