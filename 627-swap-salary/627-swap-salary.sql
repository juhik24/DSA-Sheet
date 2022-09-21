# Write your MySQL query statement below
Update salary
set 
   sex = case sex 
      when 'm' then 'f'
      else 'm'
   END;