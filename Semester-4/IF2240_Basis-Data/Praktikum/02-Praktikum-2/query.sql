SELECT
    c.title, c.dept_name, COUNT(t.grade)
FROM
    student s
    NATURAL JOIN takes t
    NATURAL JOIN section sc
    NATURAL JOIN course c
WHERE
    t.grade = 'D'
    OR t.grade = 'E'

GROUP BY
    c.title

HAVING
    COUNT(t.grade) > 2

ORDER BY
    COUNT(t.grade) DESC;



