/*
编写一个 SQL 查询，来删除 Person 表中所有重复的电子邮箱，重复的邮箱里只保留 Id 最小 的那个。

+----+------------------+
| Id | Email            |
+----+------------------+
| 1  | john@example.com |
| 2  | bob@example.com  |
| 3  | john@example.com |
+----+------------------+
Id 是这个表的主键。
例如，在运行你的查询语句之后，上面的 Person 表应返回以下几行:

+----+------------------+
| Id | Email            |
+----+------------------+
| 1  | john@example.com |
| 2  | bob@example.com  |
+----+------------------+
*/

# 这样写会报错You can't specify target table 'Person' for update in FROM clause，意思是不能在同一个sql语句中，先select同一个表的某些值，然后再update这个表
# 解决办法是select的结果再通过一个中间表select多一次，就可以避免这个错误
delete from Person where Id not in
(select min(Id) as Id from Person group by Email)

# error Every derived table must have its own alias 意思是每个派生出来的表必须有一个自己的别名
delete from Person where Id not in
(select Id from (select min(Id) as Id from Person group by Email))

delete from Person where Id not in
(select Id from (select min(Id) as Id from Person group by Email) p)


# 思路2: 直接使用内交，删除Id大的值
DELETE p2 FROM Person p1 JOIN Person p2 
ON p2.Email = p1.Email WHERE p2.Id > p1.Id;

