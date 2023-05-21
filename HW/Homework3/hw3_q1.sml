use "hw3_q1_def.sml";

fun mapState f s = List.map (List.map f) s;

fun toString chars = List.foldr (op ^) "" (List.map str chars);

fun frameToState frame = mapState (fn n => ord n = ord #"*" orelse false) (map String.explode frame);

fun stateToFrame state = List.map (toString) (mapState toChar state);

fun printFrame frame = (fn _ => ()) (List.map print (map (fn s => s^"\n") frame));