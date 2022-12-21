# Write your MySQL query statement below
# 180. Consecutive Numbers using WITH-AS, Lead() and Lag()
WITH temp AS
(
    SELECT  num,
            Lead(num) OVER(ORDER BY id) AS 'LD',
            Lag(num) OVER(ORDER BY id) AS 'LG'
    FROM    Logs
)
SELECT DISTINCT num AS 'ConsecutiveNums'
FROM temp
WHERE   num = LD AND num = LG
;