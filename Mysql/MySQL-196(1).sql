# Please write a DELETE statement and DO NOT write a SELECT statement.
# Write your MySQL query statement below
DELETE FROM Person 
WHERE id IN 
    (
        SELECT id FROM (
            SELECT id, ROW_NUMBER() OVER(PARTITION BY email ORDER BY id) AS 'dup' FROM Person
        ) t 
        WHERE dup > 1
    )
;