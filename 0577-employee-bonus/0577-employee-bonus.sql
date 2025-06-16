SELECT name, bonus
FROM (
    SELECT e.name, b.bonus
    FROM Employee AS e
    LEFT JOIN Bonus AS b
    ON e.empId = b.empId
) AS derived
WHERE bonus IS NULL OR bonus < 1000;