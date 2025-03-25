-- Ex 14

delimiter $$

create procedure proc_rating()
begin
    declare finished int default 0;
    declare c_name varchar(20);
    declare c_score int;
    declare c_risk varchar(15);
    declare cur_rate cursor for select company_name, score, risk from company_credit_score;
    declare continue handler for not found set finished = 1;
    open cur_rate;
    XYZ: loop
        fetch cur_rate into c_name, c_score, c_risk;
        if finished = 1 then
            leave XYZ;
        end if;
        case
            when c_score >= 30 then
                set c_risk = 'Low risk';
            when c_score >= 21 and c_score < 30 then
                set c_risk = 'Medium risk';
            when c_score >= 11 and c_score < 20 then
                set c_risk = 'High risk';
            else
                set c_risk = 'Junk';
        end case;
        update company_credit_score set risk = c_risk where company_name = c_name;
    end loop XYZ;
    close cur_rate;
end $$

delimiter ;

call proc_rating();
