SELECT pz.name AS pizzeria_name
FROM person_visits pv
JOIN person p ON p.id = pv.person_id
JOIN pizzeria pz ON pz.id = pv.pizzeria_id
WHERE p.name = 'Andrey'

EXCEPT

SELECT pz.name
FROM person_order po
JOIN person p ON p.id = po.person_id
JOIN menu m ON m.id = po.menu_id
JOIN pizzeria pz ON pz.id = m.pizzeria_id
WHERE p.name = 'Andrey'

ORDER BY pizzeria_name;