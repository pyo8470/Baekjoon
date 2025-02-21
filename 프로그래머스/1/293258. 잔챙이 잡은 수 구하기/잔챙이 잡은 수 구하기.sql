-- 코드를 작성해주세요
select count(*) as FISH_COUNT
from FISH_INFO 
where length<10 or length is null