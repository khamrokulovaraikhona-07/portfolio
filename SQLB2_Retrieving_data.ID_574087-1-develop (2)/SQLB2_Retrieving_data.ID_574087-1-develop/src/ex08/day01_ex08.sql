SELECT po.order_date,
       person.name + ' (age: ' + CAST(person.age AS VARCHAR(10)) + ')' AS person_information
FROM person_order AS po
INNER JOIN person
    ON po.person_id = person.id
ORDER BY po.order_date, person_information;

