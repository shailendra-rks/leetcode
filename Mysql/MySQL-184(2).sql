# Write your MySQL query statement below
# 184. Department Highest Salary using WHERE IN clauses
# leetcode OFFICIAL Solution
SELECT d.name AS 'Department',
        e.name AS 'Employee', 
        e.salary
FROM Employee e
    LEFT JOIN Department d
    ON e.departmentId = d.id
WHERE 
    (e.salary, e.departmentId) IN
    (SELECT DISTINCT MAX(salary) as 'salary', departmentId FROM Employee GROUP BY departmentId)
;