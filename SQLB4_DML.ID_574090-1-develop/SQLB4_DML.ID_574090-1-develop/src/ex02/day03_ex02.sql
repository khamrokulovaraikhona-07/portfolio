SELECT pizza_name, price, pizzeria_name
FROM menu
WHERE id NOT IN (
    SELECT menu_id
    FROM person_order
)
ORDER BY pizza_name, price;