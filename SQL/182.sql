/*
编写一个 SQL 查询，查找 Person 表中所有重复的电子邮箱。

示例：

+----+---------+
| Id | Email   |
+----+---------+
| 1  | a@b.com |
| 2  | c@d.com |
| 3  | a@b.com |
+----+---------+
根据以上输入，你的查询应返回以下结果：

+---------+
| Email   |
+---------+
| a@b.com |
+---------+
说明：所有电子邮箱都是小写字母。
*/

# 思路：直接使用group by having 来进行解答  这是一组搭配
#where在数据分组之前进行过滤，having在数据分组之后进行过滤

select Email, count(*) Num from Person
# where
group by Email
having 2 = Num

