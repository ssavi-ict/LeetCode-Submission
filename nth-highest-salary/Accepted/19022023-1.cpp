CREATE FUNCTION getNthHighestSalary(N INT) RETURNS INT
BEGIN
  set n = n - 1;
  RETURN (
      select distinct(Employee.salary)
      from Employee
      order by Employee.salary desc
      limit 1 offset n
  );
END