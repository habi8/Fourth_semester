
SQL> connect system
Enter password:
Connected.

SQL> alter user hr
  2  identified by hr
  3  account unlock ;
User altered.

SQL> grant dba to hr;
Grant succeeded.

SQL> connect hr
Enter password:
Connected.

SQL> select * from tab ;

select * from COUNTRIES ;

select * from EMPLOYEES ;

describe JOB_HISTORY;

select employee_id, salary,commission_pct from EMPLOYEES;

     UPDATE EMPLOYEES
  2  SET COMMISSION_PCT = '0'
  3  WHERE COMMISSION_PCT IS NULL;

select (salary+salary*commission_pct)*12 "Mahin" from EMPLOYEES;

select first_name ||''|| salary AS "EMPLOYEES" from employees;

select last_name ||'''s annual salary is '|| (salary+salary*commission_pct)*12 AS "EMPLOYEES" from employees;
@D:\n\A.sql





