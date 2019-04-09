/*
编写一个 SQL 查询，获取 Employee 表中第 n 高的薪水（Salary）。

+----+--------+
| Id | Salary |
+----+--------+
| 1  | 100    |
| 2  | 200    |
| 3  | 300    |
+----+--------+
例如上述 Employee 表，n = 2 时，应返回第二高的薪水 200。如果不存在第 n 高的薪水，那么查询应返回 null。

+------------------------+
| getNthHighestSalary(2) |
+------------------------+
| 200                    |
+------------------------+
*/

# 思路：就是求第N高元素的扩展，注意相同数值的元素属于同一个高的元素
# 注意SQL中function的写法
CREATE FUNCTION getNthHighestSalary(N INT) RETURNS INT
BEGIN
  RETURN (
      # Write your MySQL query statement below.
      select max(Salary) from Employee e1
      where N-1 = 
      (select count(distinct(Salary)) from Employee e2
      where e2.Salary > e1.Salary)   
  );
END