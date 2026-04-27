INSERT INTO person_visits (id, person_id, pizzeria_id, visit_date)
SELECT
    (SELECT MAX(id) FROM person_visits) + ROW_NUMBER() OVER (),
    p.id,
    (SELECT id FROM pizzeria WHERE name = 'Dominos'),
    '2022-02-24'
FROM person p
WHERE p.name IN ('Denis', 'Irina');