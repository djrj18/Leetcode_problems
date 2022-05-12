​starts from index 0 element and swap it with all other elements one by one after swaping find permutation for array starting from index 1 and so on
Don't swap with similar element twice(duplicate occurances).
Let's suppose we are index i currently then swap ith elements  with index i+1 th element and solve for array i+1 onwards after completing this,swap ith element  with i+2 th element  and again solve for array i+1 onwards avoid swaping of same elements twice.
Time Complexity = (n!);
