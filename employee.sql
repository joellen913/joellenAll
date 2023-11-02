
#29
select EMP_FNAME, EMP_LNAME, EMP_EMAIL
from LGEMPLOYEE
where EMP_HIREDATE between '2005-01-01' AND '2014-12-31'
order by EMP_LNAME, EMP_FNAME;

#31
SELECT 
    LGEMPLOYEE.EMP_NUM,
    LGEMPLOYEE.EMP_LNAME,
    LGEMPLOYEE.EMP_FNAME,
    SAL_FROM,
    SAL_END,
    SUM(SAL_AMOUNT)
FROM
    LGEMPLOYEE
        JOIN
    LGSALARY_HISTORY ON LGEMPLOYEE.EMP_NUM = LGSALARY_HISTORY.EMP_NUM
WHERE
    LGEMPLOYEE.EMP_NUM = '83731'
        OR LGEMPLOYEE.EMP_NUM = '83745'
        OR LGEMPLOYEE.EMP_NUM = '84039'
GROUP BY LGEMPLOYEE.EMP_NUM , SAL_FROM
ORDER BY LGEMPLOYEE.EMP_NUM;

#32
select distinct c.Cust_Fname, c.Cust_Lname, c.Cust_Street, c.Cust_City, c.Cust_State, c.Cust_Zip 
from LGCUSTOMER c, LGBRAND b, LGPRODUCT p, LGINVOICE i, LGLINE l
where c.Cust_Code = i.Cust_Code And b.Brand_ID = p.Brand_ID And i.Inv_Num = l.Inv_Num And p.Prod_SKU = l.Prod_SKU
and b.Brand_Name = 'Foresters Best' And Prod_Category = 'Top Coat' And i.Inv_Date > '2017-07-15' And i.Inv_Date < '2017-07-31'
order by c.Cust_State, c.Cust_Lname, c.Cust_Fname;

#38
select LGBRAND.BRAND_ID, BRAND_NAME, ROUND(AVG(PROD_PRICE),2) as AVGPRICE
from LGBRAND join LGPRODUCT on LGBRAND.BRAND_ID = LGPRODUCT.BRAND_ID
group by LGBRAND.BRAND_ID
order by LGBRAND.BRAND_NAME;

#41
select LGCUSTOMER.CUST_CODE, CUST_FNAME, CUST_LNAME, SUM(INV_TOTAL) as TotalInvoices
from LGCUSTOMER join LGINVOICE on LGCUSTOMER.CUST_CODE = LGINVOICE.CUST_CODE
group by LGCUSTOMER.CUST_CODE
having SUM(INV_TOTAL) > 1500
order by SUM(INV_TOTAL) DESC;

#43
SELECT 
    P.BRAND_ID, B.BRAND_NAME, B.BRAND_TYPE, MAX(AVGPRICE)
FROM
    LGPRODUCT P
        INNER JOIN
    LGBRAND B ON P.BRAND_ID = B.BRAND_ID,
    (SELECT 
        P.BRAND_ID, AVG(P.PROD_PRICE) AS AVGPRICE
    FROM
        LGPRODUCT P 
    GROUP BY P.BRAND_ID) AS AVGPRICE 
GROUP BY P.BRAND_ID , B.BRAND_NAME , B.BRAND_TYPE;

#46
SELECT P.BRAND_ID, B.BRAND_NAME, B.BRAND_TYPE, 
MAX(AVGPRICE) FROM  LGPRODUCT P INNER JOIN LGBRAND B ON P.BRAND_ID = B.BRAND_ID, (SELECT P.BRAND_ID, AVG (P.PROD_PRICE) AS AVGPRICE     
FROM  LGPRODUCT P
GROUP BY P.BRAND_ID) AS AVGPRICE 
GROUP BY P.BRAND_ID, B.BRAND_NAME, B.BRAND_TYPE; 

#47
SELECT MANAGER, D.DEPT_NAME, D.DEPT_PHONE, 
CONCAT(E.EMP_FNAME, ' ', E.EMP_LNAME) AS EMPNAME, 
CONCAT(C.CUST_FNAME, ' ', C.CUST_LNAME) AS 'CUSTNAME', 
I.INV_DATE, I.INV_TOTAL 
FROM LGEMPLOYEE E INNER JOIN LGDEPARTMENT D ON E.DEPT_NUM = D.DEPT_NUM INNER JOIN LGINVOICE I ON E.EMP_NUM = I.EMPLOYEE_ID INNER JOIN LGCUSTOMER C ON I.CUST_CODE = C.CUST_CODE, (SELECT CONCAT(E.EMP_NUM,' ',E.EMP_LNAME) AS MANAGER 
FROM LGDEPARTMENT D INNER JOIN LGEMPLOYEE E ON D.DEPT_NUM = E.DEPT_NUM 
WHERE E.EMP_TITLE LIKE '%MANAGER' ) AS MANAGER 
WHERE I.INV_DATE = '2013-MAY-18' AND C.CUST_LNAME LIKE '%Hagan';

#50
SELECT l.INV_NUM, l.LINE_NUM, p.PROD_SKU, p.PROD_DESCRIPT, l2.LINE_NUM, p2.PROD_SKU, p2.PROD_DESCRIPT, p.BRAND_ID
FROM (LGLINE AS l INNER JOIN LGPRODUCT AS p ON l.PROD_SKU = p.PROD_SKU) INNER JOIN (LGLINE AS l2 INNER JOIN LGPRODUCT AS p2 ON l2.PROD_SKU = p2.PROD_SKU) ON l.INV_NUM = l2.INV_NUM
WHERE p.BRAND_ID = p2.BRAND_ID AND p.PROD_CATEGORY = 'Sealer' AND p2.PROD_CATEGORY = 'Top Coat'
ORDER BY l.INV_NUM, l.LINE_NUM;

#53
select c.cust_code, c.cust_fname, c.cust_lname, c.cust_street, c.cust_city, c.cust_state, c.cust_zip, i.inv_date, i.inv_total as 'Largest Invoice' 
from LGCUSTOMER c, LGINVOICE i 
where i.cust_code = c.cust_code and c.cust_state = 'AL' and i.inv_total = (
     select max(ii.inv_total) 
	from LGINVOICE ii 
    where ii.cust_code = c.cust_code) 
     union select c2.cust_code, c2.cust_fname, c2.cust_lname, c2.cust_street, c2.cust_city, c2.cust_state, c2.cust_zip, null, 0 
     from LGCUSTOMER c2 
     where c2.cust_state = 'AL' and c2.cust_code not in (select iii.cust_code from LGINVOICE iii) 
     order by cust_lname, cust_fname;
