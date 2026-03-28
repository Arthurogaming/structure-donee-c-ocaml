type pile = int list

val creer_pile : unit -> pile
val est_vide_pile : pile -> bool
val empiler_element_pile : pile -> int -> pile
val depiler_element_pile : pile -> (int * pile) option
val obtenir_sommet_pile : pile -> int option
val longueur_pile : pile -> int
