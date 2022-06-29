# Write your MySQL query statement below
SELECT E1.name as Employee 
FROM Employee as E1
WHERE E1.salary > (SELECT E2.salary FROM Employee as E2 WHERE E2.id = E1.managerId);