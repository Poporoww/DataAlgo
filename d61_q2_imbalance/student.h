// Your code here
int recur(node* n, int& max, KeyT& val) {
    if(n == NULL) return -1;

    int l = recur(n->left, max, val);
    int r = recur(n->right, max, val);
    int diff = abs(l - r);
    if(diff > max) {
        max = diff;
        val = n->data.first;
    } else if(diff == max and n->data.first < val) {
        val = n->data.first;
    }

    return 1 + std::max(l, r);
}

KeyT getValueOfMostImbalanceNode() {
    // Your code here
    if(mSize == 1) return mRoot->data.first;

    int max = 0;
    KeyT val = 0;
    recur(mRoot, max, val);
    return val;
}
