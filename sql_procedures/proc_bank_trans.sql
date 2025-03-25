delimiter $$

create procedure proc_bank_trans(in account_no int, in amt double(18,2), out trans_status varchar(50))
XYZ: begin
    declare finished int default 0;
    declare x int default 0;
    declare bal_amt double(10,2) default 0;
    declare cur_bank cursor for select balance from bank_account where acc_no = account_no;
    declare continue handler for not found set finished = 1;
    open cur_bank;
    fetch cur_bank into bal_amt;
    if finished = 1 then
        set trans_status = 'Account does not exist';
        select trans_status;
        leave XYZ;
    end if;
    if (bal_amt - amt) < 1000 then
        set trans_status = 'Maintain minimum balance';
    else
        update bank_account set balance = bal_amt - amt where acc_no = account_no;
        select row_count() into x;
        if x = 1 then
            set trans_status = 'Transaction successful';
        end if;
    end if;
    select trans_status;
    close cur_bank;
end $$

delimiter ;
