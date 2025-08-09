# Write your MySQL query statement below
select round(count(*)/(select count(distinct player_id) from Activity),2) as fraction
from(select player_id, min(event_date) as first_date
    from Activity
    group by player_id
) a 
Join Activity b
on a.player_id = b.player_id and datediff(b.event_date, a.first_date) = 1;