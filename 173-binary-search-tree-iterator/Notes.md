just convert the tree to flatten tree(linked list) using morris traversal.
morris traversal:
    1.find largest node in left subtree of current node (which is rightmost node) and connect it's right pointer to current node and set current node's left pointer to NULL and update  current pointer to it's left pointer.
    2. if there is no left subtree (i.e left pointer is NULL) then update current pointer to it's right pointer.
Time Complexity = O(1) (average) ---O(n) for morris traversal.
Space complexity = O(1) as there is no recursion involve and no extra memory is being used.
