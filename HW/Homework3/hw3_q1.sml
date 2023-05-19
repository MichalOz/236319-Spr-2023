use "hw3_q1_def.sml";

fun mapState f s = map (map f) s;

fun toString chars = foldr (op ^) "" (map str chars);

fun frameToState frame = mapState (fn n => ord n = ord #"*" orelse false) (map String.explode frame);

fun stateToFrame state = map (toString) (mapState toChar state);

fun printFrame frame = (fn _ => ()) (map print (map (fn s => s^"\n") frame));