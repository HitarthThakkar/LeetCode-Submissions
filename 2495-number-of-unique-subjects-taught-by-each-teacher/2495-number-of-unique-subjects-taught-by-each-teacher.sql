# Write your MySQL query statement below

select t.teacher_id, 
        count(distinct(subject_id)) as cnt
from teacher as t
group by teacher_id