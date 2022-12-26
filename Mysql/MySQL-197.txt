# Write your MySQL query statement below
# 197. Rising Temperature

# SELECT id 
# FROM
#     (SELECT id, temperature, Lag(temperature) OVER() as 'lag'
#         FROM Weather
#     ) p
# WHERE p.temperature > p.lag

#above fails in unordered and missing dates cases


SELECT
    t1.id
FROM
    weather t1
    JOIN
    weather t2 ON DATEDIFF(t1.recordDate, t2.recordDate) = 1
        AND t1.Temperature > t2.Temperature
;