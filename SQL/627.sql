# 使用if函数,使用case when then else end

update salary set sex = if(sex='m','f','m');

update salary set sex = (case when sex = 'm' then 'f' else 'm' end)

