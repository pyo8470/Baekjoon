-- 코드를 입력하세요
SELECT BOOK_ID, DATE_FORMAT(PUBLISHED_DATE,'%Y-%m-%d') AS PUBLISHED_DATE
from Book
where  category = '인문' and PUBLISHED_DATE Like "2021%"
order by PUBLISHED_DATE asc