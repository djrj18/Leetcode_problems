​if value of root is less than low then whole left subtree will be less than low so will be discarded and return null for left subtree.
if value of root is greater than high then whole right subtree will be discarded and return null for right subtree.
if root value lies in range [low,high] then solve for left and right subtree and update root's left and right subtree and then return root.
Time complexity = O(n) --> n = number of nodes in tree
Space Complexity = O(Height of tree) for recursion calls.
