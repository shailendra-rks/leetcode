# Write your MySQL query statement below
# 175. Combine Two Tables
select Person.firstName, Person.lastName, Address.city, Address.state from Person LEFT JOIN Address ON Person.personId = Address.personId;