delimiter $$

create procedure p_salary(in p_eno int, out p_inc double)
begin
    declare p_des varchar(15);
    declare p_sal double(8,2);
    select Designation into p_des from employee where E_No = p_eno;
    select Salary into p_sal from employee where E_No = p_eno;
    set p_inc =
        case
            when p_des = 'Manager' then p_sal * 0.25
            when p_des = 'Team Lead' then p_sal * 0.20
            when p_des = 'Developer' then p_sal * 0.15
            else p_sal * 0.10
        end;
    update employee set Salary = Salary + p_inc where E_No = p_eno;
end $$

delimiter ;

p_salary(101, @p_inc);
