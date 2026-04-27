INSERT INTO person_order (id, person_id, menu_id, order_date)
SELECT
    (SELECT MAX(id) FROM person_order) + ROW_NUMBER() OVER (ORDER BY p.id),
    p.id,
    (SELECT id FROM menu WHERE pizza_name = 'sicilian pizza'),
    '2022-02-24'
FROM person p
WHERE p.name IN ('Denis', 'Irina');