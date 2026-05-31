# Write your MySQL query statement below
SELECT e.unique_id, eu.name FROM Employees AS eu LEFT JOIN EmployeeUNI AS e ON
eu.id=e.id;