# Write your MySQL query statement below
# 181. Employees Earning More Than Their Managers
SELECT emp.name AS 'Employee'
FROM Employee emp
    JOIN Employee mgr 
ON emp.managerId = mgr.id
    AND emp.salary > mgr.salary
;