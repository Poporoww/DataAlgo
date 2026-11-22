#ifndef __STUDENT_H_
#define __STUDENT_H_

// You may include library here
#include "map_bst.h"
#include <cmath>

template <typename KeyT, 
          typename MappedT, 
          typename CompareT>
int CP::map_bst<KeyT, MappedT, CompareT>::recursive1(node* n) const 
{
    if(n == NULL) return 0;
    return 1 + std::max(recursive1(n->left), recursive1(n->right));
}

template <typename KeyT, 
          typename MappedT, 
          typename CompareT>
void CP::map_bst<KeyT, MappedT, CompareT>::recursive2(node* n, std::size_t i, std::vector<KeyT>& v) const 
{
    if(n == NULL) return;
    v[i] = n->data.first;
    recursive2(n->left, 2*i + 1, v);
    recursive2(n->right, 2*i + 2, v);
}

template <typename KeyT, 
          typename MappedT, 
          typename CompareT>
std::vector<KeyT> CP::map_bst<KeyT, MappedT, CompareT>::flatten() const 
{
    int h = recursive1(mRoot);
    std::vector<KeyT> v(pow(2, h) - 1, 0);
    recursive2(mRoot, 0, v);
    return v;
}

#endif
