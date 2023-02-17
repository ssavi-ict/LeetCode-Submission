# Write your MySQL query statement below
select E1.name as Employee
from Employee E1
where E1.salary > (
    select E2.salary
    from Employee E2
    where E2.id = E1.managerId
);