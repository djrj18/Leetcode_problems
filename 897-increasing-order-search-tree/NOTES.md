​For in order traversal we first traverse left substree then root and then right subtree.---   left  root   right.

I used morris traversal here--
      1. if there is left subtree for current root then we find the greatest node in left subtree and set it's right pointer to curr node and set curr node's left              pointer to NULL as we are traversing in order. (in BST left < root < right) and set current node to current node's left node.
      2. if there is no left subtree then set previous node's right node to current node if previous node is not NULL else set previos to current node and current node          to current node's right node. 
      
Time Complexity = O(n) -- n = number of nodes in tree.
Space Complexity = O(1)
      
