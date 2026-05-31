select name,bonus from Employee as E LEFT JOIN Bonus AS B ON 
E.empId=B.empId WHERE B.bonus<1000 OR B.bonus iS NULL