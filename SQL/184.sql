/*
Employee 表包含所有员工信息，每个员工有其对应的 Id, salary 和 department Id。

+----+-------+--------+--------------+
| Id | Name  | Salary | DepartmentId |
+----+-------+--------+--------------+
| 1  | Joe   | 70000  | 1            |
| 2  | Henry | 80000  | 2            |
| 3  | Sam   | 60000  | 2            |
| 4  | Max   | 90000  | 1            |
+----+-------+--------+--------------+
Department 表包含公司所有部门的信息。

+----+----------+
| Id | Name     |
+----+----------+
| 1  | IT       |
| 2  | Sales    |
+----+----------+
编写一个 SQL 查询，找出每个部门工资最高的员工。例如，根据上述给定的表格，Max 在 IT 部门有最高工资，Henry 在 Sales 部门有最高工资。

+------------+----------+--------+
| Department | Employee | Salary |
+------------+----------+--------+
| IT         | Max      | 90000  |
| Sales      | Henry    | 80000  |
+------------+----------+--------+
*/

# 思路：因为测试用例中要除去为NULL的行，左连接或者右连接都会产生NULL的行，因此使用内连接，这里使用group by会使得Employee.Name
# 的行得不到匹配，注意使用相同表连接的写法
select d.Name as Department, e1.Name as Employee, e1.Salary as Salary
from Employee e1 inner join Department d on e1.DepartmentId = d.Id
where Salary in 
(select max(Salary) from Employee e2 where e1.DepartmentId = e2.departmentId)