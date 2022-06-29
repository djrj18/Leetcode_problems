# Write your MySQL query statement below
SELECT P.email as Email
FROM (SELECT COUNT(email) as cnt,email FROM PERSON GROUP BY email) as P
WHERE P.cnt > 1;