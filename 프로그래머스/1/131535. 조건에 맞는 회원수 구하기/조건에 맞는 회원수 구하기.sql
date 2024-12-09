-- 코드를 입력하세요
SELECT count(User_Id) from user_info
where  age <=29 and age >=20 and joined <= '2021-12-31' and joined >= '2021-01-01'