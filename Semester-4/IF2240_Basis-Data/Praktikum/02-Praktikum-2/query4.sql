WITH popular_course AS (
SELECT c.course_id FROM course WHERE c.course_id IN (SELECT c.course_id FROM course NATURAL JOIN section
    NATURAL JOIN takes GROUP BY c.course_id HAVING COUNT(*) > 200)
)

SELECT c.title, .credits, sc.semester, sc.year
