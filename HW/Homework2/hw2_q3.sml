datatype cell = alive | empty;

fun is_alive (c1, c2, c3) (c4, c5, c6) (c7, c8, c9)=
    let
      val lst = c1::c2::c3::c4::c6::c7::c8::[c9];
      val aliveCells=List.filter (fn x => (x=alive)) lst;
    in
      case c5 of
        empty => if (List.length aliveCells)=3 then alive else empty
       | alive => if (List.length aliveCells)=2 orelse (List.length aliveCells)=3 then alive else empty
       end
    
    