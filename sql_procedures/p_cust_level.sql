-- Ex 11

delimiter $$

create procedure p_cust_level(in p_cust_no int, in p_credit double(8,2))
begin
    declare p_level varchar(15);
    select Credit_Limit into p_credit from customer where Cust_No = p_cust_no;
    if p_credit <= 25000 then
        set p_level = 'Silver';
    elseif p_credit <= 50000 then
        set p_level = 'Gold';
    else
        set p_level = 'Platinum';
    end if;
    update customer set Level = p_level where Cust_No = p_cust_no;
end $$

delimiter ;

call p_cust_level(101, 20000);
