

-- select c.user_id, count(c.action) from confirmations as c
-- join confirmations cc
-- on c.user_id =  cc.user_id and 
--                 c.action = cc.action and 
--                 c.action = 'timeout' and 
--                 c.time_stamp = cc.time_stamp
-- group by c.user_id

select s.user_id, ifnull(round(succ / total, 2), 0) as confirmation_rate from signups as s
left join(
    select two.user_id, one.suc as succ, two.ttl as total
    from (
        select *, count(action) as suc
        from confirmations
        where action = 'confirmed'
        group by user_id, action
        ) as one
    right join 
            (select *, count(*) as ttl
            from confirmations
            group by user_id) as two
    on one.user_id = two.user_id
) as final
on s.user_id = final.user_id