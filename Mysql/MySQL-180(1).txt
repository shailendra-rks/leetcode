# Write your MySQL query statement below
# 180. Consecutive Numbers atleast 3 times
SELECT DISTINCT x.num AS 'ConsecutiveNums'
FROM Logs x,
     Logs y,
     Logs z
WHERE x.id = y.id - 1
     AND y.id = z.id - 1
     AND x.num = y.num
     AND y.num = z.num
;