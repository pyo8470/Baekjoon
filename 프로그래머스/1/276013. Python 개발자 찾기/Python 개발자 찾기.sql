-- 코드를 작성해주세요
select ID, EMAIL, FIRST_NAME, LAST_NAME 
from DEVELOPER_INFOS
WHERE 'Python' IN (skill_1, skill_2, skill_3)
order by ID ASC
