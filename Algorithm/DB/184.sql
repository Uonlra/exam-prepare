-- Department Highest Salary (LeetCode: Department Highest Salary)
SELECT d.name AS Department,
       e.name AS Employee,
       e.salary AS Salary
FROM Employee e
JOIN Department d
  ON e.departmentId = d.id

-- 子查询先按 departmentId 分组，计算每个部门的最高工资 MAX(salary)，得到形如 (departmentId, max_salary) 的结果集（别名 m）。
JOIN ( -- 子查询，计算每个部门的最高工资
  SELECT departmentId, MAX(salary) AS max_salary
  FROM Employee
  GROUP BY departmentId
) m 
-- 用条件 e.departmentId = m.departmentId AND e.salary = m.max_salary 回连员工表，只保留工资等于该部门最高工资的员工。
  ON e.departmentId = m.departmentId
 AND e.salary = m.max_salary;
