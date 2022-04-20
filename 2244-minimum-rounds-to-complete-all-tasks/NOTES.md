​first store frequency of each number in array using map.
for geeting minimum rounds we have to compelete tasks as many as we can in one round(which is 3) so frequency must be combination of 3's and 2's (3*x+2*y = frequency).
Traverse the map and check following conditions:
    1. if frquency%3 == 0 means we can complete this task in frequency/3 round.
    2. if frequency%3 == 1 ( *** *** *** * so for combination of 3's and 2's we have to take one from second last group *** *** ** ** ) we can complete this type of         tasks in frequency/3 - 1 + 2 rounds. (frequency/3 - 1 3's and 2 2's).
    3.if frequency%3 == 2 then we can complete in frequency/3 + 1 rounds ( *** *** ** ) (3 3 2).
    4. if frequency%2 == 0 then we can complete in frequency/2 rounds.
    5. else there is no way to complete this task.
Time Complexity = O(n)
Space Complexity = O(n) for storing frequencies.
    
