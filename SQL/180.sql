/*
编写一个 SQL 查询，查找所有至少连续出现三次的数字。

+----+-----+
| Id | Num |
+----+-----+
| 1  |  1  |
| 2  |  1  |
| 3  |  1  |
| 4  |  2  |
| 5  |  1  |
| 6  |  2  |
| 7  |  2  |
+----+-----+
例如，给定上面的 Logs 表， 1 是唯一连续出现至少三次的数字。

+-----------------+
| ConsecutiveNums |
+-----------------+
| 1               |
+-----------------+
*/

# 思路： 有两种方法，一种方法是使用内连接(join(inner join),left join,right join, full join)

/*select Num as ConsecutiveNums from Logs
group by Num
having count(*) >=3*/

# 下面的ll1.Num ll2.Num ll3.Num都是同一个表中的Num
select distinct ll1.Num as ConsecutiveNums from Logs ll1
join Logs ll2 on ll1.Id = ll2.Id-1
join Logs ll3 on ll1.Id = ll3.Id-2
where ll1.Num = ll2.Num and ll2.Num = ll3.Num

select distinct ll1.Num as ConsecutiveNums from Logs ll1, Logs ll2, Logs ll3
where ll1.Id = ll2.Id-1 and ll1.Id = ll3.Id-2
and ll1.Num = ll2.Num and ll2.Num = ll3.Num