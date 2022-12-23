# Write your MySQL query statement below
# 183. Customers Who Never Order using "not in"
select customers.name as 'Customers'
from customers
where customers.id not in
(
    select customerid from orders
);