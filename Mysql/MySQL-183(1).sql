# Write your MySQL query statement below
# 183. Customers Who Never Order using join and IS NULL
SELECT name AS 'Customers' 
FROM Customers c
LEFT JOIN Orders o
ON c.id = o.customerId
WHERE o.customerID IS null
;