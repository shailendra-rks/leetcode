# Write your MySQL query statement below
# 182. Duplicate Emails
# we can use this logic to delete duplicated from the Table
WITH temp AS(
    SELECT id, email, ROW_NUMBER() OVER(PARTITION BY email ORDER BY id) as 'RowNumber' FROM Person
)
SELECT DISTINCT email
FROM temp
WHERE RowNumber > 1
;