SELECT eu.unique_id, e.name
FROM Employees AS e
LEFT JOIN EmployeeUNI as eu
ON e.id = eu.id;