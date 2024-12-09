SELECT
    DISTINCT id,
    email,
    first_name,
    last_name
FROM
    developers
WHERE
# 비트연산
    skill_code & (SELECT SUM(code) FROM skillcodes WHERE name IN ('C#', 'Python')) 
ORDER BY
1
    