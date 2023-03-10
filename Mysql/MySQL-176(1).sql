# Write your MySQL query statement below
# 176. Second Highest Salary
SELECT
    IFNULL(
      (SELECT DISTINCT Salary
       FROM Employee
       ORDER BY Salary DESC
        LIMIT 1 OFFSET 1),
    NULL) AS 'SecondHighestSalary';