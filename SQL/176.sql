# Write your MySQL query statement below
select max(Salary) as SecondHighestSalary from Employee
where Salary < 
(select max(Salary) from Employee);

## 下面是更加通用的写法
select max(Salary) as SecondHighestSalary from Employee E1
where 1 = 
(select count(distinct(E2.Saraly)) #E2最小值比E1最大值大的数目，如果是第二高，则where后面就为2-1
from Employee E2
where E2.Salary > E1.Salary)