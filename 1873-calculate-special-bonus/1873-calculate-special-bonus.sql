# Write your MySQL query statement below
SELECT employee_id, if (employee_id%2 and name not like "M%", salary, 0) as BONUS
from Employees order by employee_id;