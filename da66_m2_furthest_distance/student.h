#ifndef __STUDENT_H_
#define __STUDENT_H_

#include "map_bst.h"

template <typename KeyT,
          typename MappedT,
          typename CompareT>
int CP::map_bst<KeyT, MappedT, CompareT>::my_recur(node* n, int &aux){
	// You MAY use this function
	if(n == NULL) return -1;
    int l = my_recur(n->left, aux);
    int r = my_recur(n->right, aux);
    aux = std::max(aux, l + r + 2);
    return 1 + std::max(l, r);
}

template <typename KeyT,
          typename MappedT,
          typename CompareT>
int CP::map_bst<KeyT, MappedT, CompareT>::furthest_distance() {
	// write your code here
    if(mRoot == NULL) return -1;

    int aux = 0;
    my_recur(mRoot, aux);
    return aux;
}

#endif
