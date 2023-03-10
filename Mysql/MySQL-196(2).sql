# Please write a DELETE statement and DO NOT write a SELECT statement.
# Write your MySQL query statement below
DELETE t1 
FROM Person t1,
    Person t2
WHERE t1.email = t2.email
    AND t1.id > t2.id

# using NOT IN and min() function

DELETE FROM Person
WHERE id NOT IN(SELECT * FROM
    (SELECT min(id) as 'id' FROM Person t2 GROUP BY email) p
)
;