# Write your MySQL query statement below
select Department.name as Department, Employee.name as Employee, Employee.salary as Salary
from Employee
join Department
on Employee.departmentId = Department.id
where (Employee.salary, Employee.departmentId) in (
    select MAX(Employee.salary), Employee.departmentId
    from Employee
    group by Employee.departmentId
);