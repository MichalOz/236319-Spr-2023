datatype 'a Sexp = Atom of 'a | List of 'a Sexp list;
exception error;

fun cons (a , List b) = List (a::b)
  | cons _ = raise error;

fun car (List (a::b)) = a
  | car _ = raise error;

fun cdr (List (a::b)) = List b 
  | cdr (List []) = List []
  | cdr _ = raise error;

local
    fun space ((Atom a)::xs) = if xs = [] then ((Atom a)::xs) else ((Atom (a ^ " "))::(space xs))
      | space ((List c)::xs) = ((List (space c))::(space xs))
      | space _ = [];

    fun toStringAux ((Atom a), b) = a ^ b 
      | toStringAux (List [], y) = "() " ^ y
      | toStringAux ((List (x::xs)), y) = "(" ^ (foldr (toStringAux) ("") (x::xs)) ^ ")"^((fn y => if y="" then "" else " ") y)^y;
in
    fun toString (Atom a) = a 
      | toString (List []) = "()"
      | toString (List (x::xs)) = "(" ^ (foldr (toStringAux) ("") (space (x::xs))) ^ ")";
end
