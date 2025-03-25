-- Ex 13

delimiter $$

create procedure pro_book()
begin
    declare finished int default 0;
    declare c_bid int;
    declare c_btitle varchar(25);
    declare c_bprice decimal(8,2);
    declare cur_book cursor for select * from book;
    declare continue handler for not found set finished = 1;
    open cur_book;
    XYZ: loop
        fetch cur_book into c_bid, c_btitle, c_bprice;
        if finished = 1 then leave XYZ;
        end if;
        select c_bid, c_btitle, c_bprice;
    end loop XYZ;
    close cur_book;
end $$

delimiter ;

call pro_book();
