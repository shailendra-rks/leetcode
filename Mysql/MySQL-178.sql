# Write your MySQL query statement below
# 178. Rank Scores
SELECT score, DENSE_RANK() OVER(ORDER BY score DESC) as 'rank' FROM Scores;