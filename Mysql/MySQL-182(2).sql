# Write your MySQL query statement below
# 182. Duplicate Emails
SELECT email FROM Person
GROUP BY email HAVING COUNT(email) > 1
;