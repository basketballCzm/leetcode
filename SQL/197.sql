/*
给定一个 Weather 表，编写一个 SQL 查询，来查找与之前（昨天的）日期相比温度更高的所有日期的 Id。

+---------+------------------+------------------+
| Id(INT) | RecordDate(DATE) | Temperature(INT) |
+---------+------------------+------------------+
|       1 |       2015-01-01 |               10 |
|       2 |       2015-01-02 |               25 |
|       3 |       2015-01-03 |               20 |
|       4 |       2015-01-04 |               30 |
+---------+------------------+------------------+
例如，根据上述给定的 Weather 表格，返回如下 Id:

+----+
| Id |
+----+
|  2 |
|  4 |
+----+
*/

# 思路: 还是两个相同的表进行相互比较，注意使用DATEDIFF和TO_DAYS两个函数
select w1.Id from Weather w1, Weather w2
where w1.Temperature > w2.Temperature AND DATEDIFF(w1.Date, w2.Date) = 1;

select w1.Id from Weather w1, Weather w2
where w1.Temperature > w2.Temperature AND TO_DAYS(w1.date) = TO_DAYS(w2.date) + 1;
