CREATE OR REPLACE FUNCTION NthHighestSalary(N INT)
RETURNS TABLE (Salary INT) AS $$
BEGIN
  -- 可选健壮性处理：N 非法时返回 NULL
  IF N < 1 THEN
    RETURN QUERY SELECT NULL::INT;
    RETURN;
  END IF;

  RETURN QUERY
  SELECT (
    SELECT DISTINCT e.Salary
    FROM Employee e
    ORDER BY e.Salary DESC
    OFFSET N - 1
    LIMIT 1
  ) AS Salary;
END;
$$ LANGUAGE plpgsql;