# Write your MySQL query statement below

select MAX(Employee.salary) as SecondHighestSalary
from Employee
where Employee.salary < (
    select Max(Employee.salary)
    from Employee 
);