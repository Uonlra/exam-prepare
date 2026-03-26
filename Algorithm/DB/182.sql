-- 182. Duplicate Emails
SELECT Email
FROM Person
GROUP BY Email
HAVING COUNT(*) > 1; --只保留出现次数大于 1 的组
