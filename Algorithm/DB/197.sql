-- 197. Rising Temperature
SELECT w1.id AS Id -- 选择第一个表中的 id 作为结果
FROM Weather w1 -- 从 Weather 表中选择记录，命名为 w1
JOIN Weather w2
  ON DATEDIFF(w1.recordDate, w2.recordDate) = 1 -- 将 w1 和 w2 连接，条件是 w1 的 recordDate 比 w2 的 recordDate 大 1 天
WHERE w1.temperature > w2.temperature;
