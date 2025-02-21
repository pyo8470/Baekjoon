-- 코드를 작성해주세요
select A.item_id, A.item_name, A.rarity
from item_info as A
join item_tree as B on A.item_id = B.item_id
join item_info as C on B.PARENT_ITEM_ID = C.item_id
where C.Rarity = "rare"
order by A.item_id desc