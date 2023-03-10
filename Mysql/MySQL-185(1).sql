# Write your MySQL query statement below
# 185. Department Top Three Salaries
WITH temp AS
(
    SELECT id, salary, departmentId, DENSE_RANK() OVER(PARTITION BY departmentId ORDER BY salary DESC) AS 'rank' FROM Employee
)
SELECT d.name AS 'Department',
        e.name AS 'Employee', 
        e.salary AS 'Salary'
FROM Employee e
    LEFT JOIN Department d
    ON e.departmentId = d.id
    LEFT JOIN temp t
    ON e.id = t.id
WHERE 
    t.rank < 4
;