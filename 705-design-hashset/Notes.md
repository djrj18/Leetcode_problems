implement the Hash Table from scratch.
use a table of size prime number to reduce collisions.
map keys to index of table and insert in  the list at that index if it is not in the list.
for checking the key is present or not just traverse the list at index obtained fron key.
for removing a key traverse the list at index obtained by key and if key is found then delete it by shifting the elements(after the key) towards left by one index and delete last element.
Time Complexity = O(n) on an avg.
Space Complexity = (139+n);
