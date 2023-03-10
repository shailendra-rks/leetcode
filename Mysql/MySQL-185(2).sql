# Write your MySQL query statement below
# 185. Department Top Three Salaries
SELECT name AS 'Department',
        Employee, 
        salary AS 'Salary'
FROM
    (SELECT d.name,
        e.name AS 'Employee', 
        e.salary,
        DENSE_RANK() OVER(PARTITION BY departmentId ORDER BY salary DESC) AS 'rank'
    FROM Employee e
    LEFT JOIN Department d
    ON e.departmentId = d.id) t
WHERE 
    t.rank < 4
;