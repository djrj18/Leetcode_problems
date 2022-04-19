​As the property of BST values in left subtree < root < values in right subtree in order will give sorted order.
we have to find two swapped nodes.
   1.for first node we traverse in order in increasing order (i.e. left subtree then root then right subtree) if there is a node whose value if greater than root value        then this will be  one of the swapped node and we return it.
   2.for second node we traverse in order in decreasing order (i,e right subtree then root then left subtree) if there is a nodee whose value is lesser than current node      then this will be another one of the swapped nodes.
   
   For example: 1 4 3 2 5
   while traversing in increasing order 4 > 3 then 4 is one of the node.
   while traversing in decreasing order 2 < 3 then 2 is another node.
   swap them.
   
   Time Complexity = O(n)+O(n); n = number of nodes in tree.
   Space Complexity = O(Height of Tree) 
