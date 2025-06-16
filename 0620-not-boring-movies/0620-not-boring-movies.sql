SELECT *
FROM Cinema
WHERE description != 'Boring' AND ID % 2 = 1
ORDER BY rating DESC;