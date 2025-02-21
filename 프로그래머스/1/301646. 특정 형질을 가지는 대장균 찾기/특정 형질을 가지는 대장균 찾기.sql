-- 코드를 작성해주세요
select count(*) as COUNT
from ECOLI_DATA
where (GENOTYPE&2) != 2 
and(GENOTYPE & 4 = 4 or GENOTYPE & 1 = 1)