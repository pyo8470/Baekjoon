-- 코드를 입력하세요
SELECT  ANIMAL_ID, 
        NAME,
        case 
            when SEX_UPON_INTAKE LIKE "%Neutered%" or SEX_UPON_INTAKE LIKE "%Spayed%" then 'O'
            else 'X' end as '중성화'
from ANIMAL_INS