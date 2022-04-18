​As BSt have the property values in left subtree are lesser than root value and values in right subtree are greater than root,So in order traversal gives us the increasing order.
So while Traversing in order reduce k by 1 for every node after traversing its left subtree and when k == 0 then return curr node as the kth smallest.
Time Complexity = O(n) n = number of nodes in BST
Space Complexity = O(Height of Tree) for recursive Calls.
