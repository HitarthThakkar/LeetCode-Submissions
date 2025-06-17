SELECT wleft.id
FROM Weather AS wleft
INNER JOIN Weather AS wright
ON DATEDIFF(wleft.recordDate, wright.recordDate) = 1
WHERE wleft.temperature > wright.temperature;