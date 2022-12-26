# Write your MySQL query statement below
# 184. Department Highest Salary Group BY faster than OVER(PARTITION BY)
WITH max_sal AS(
    SELECT DISTINCT MAX(salary) as 'M_sal', departmentId FROM Employee GROUP BY departmentId
    # SELECT DISTINCT MAX(salary) OVER(PARTITION BY departmentId) as 'M_sal', departmentId FROM Employee
)
SELECT d.name AS 'Department',
        e.name AS 'Employee', 
        e.salary
FROM Employee e
    LEFT JOIN Department d
    ON e.departmentId = d.id,
    max_sal
WHERE 
    e.salary = max_sal.M_sal
    AND e.departmentId = max_sal.departmentId
;