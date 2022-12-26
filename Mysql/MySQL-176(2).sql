# Write your MySQL query statement below
# 176. Second Highest Salary
SELECT MAX( Salary) as 'SecondHighestSalary'
  FROM Employee
 WHERE Salary < ( SELECT MAX( Salary) FROM Employee );