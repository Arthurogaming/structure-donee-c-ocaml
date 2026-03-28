type arbre_binaire =
  | Vide
  | Noeud of int * arbre_binaire * arbre_binaire

val creer_arbre_binaire_vide : unit -> arbre_binaire
val creer_noeud_arbre_binaire : int -> arbre_binaire -> arbre_binaire -> arbre_binaire
val taille_arbre_binaire : arbre_binaire -> int
val hauteur_arbre_binaire : arbre_binaire -> int
val parcours_prefixe_arbre_binaire : arbre_binaire -> int list
val parcours_infixe_arbre_binaire : arbre_binaire -> int list
val parcours_suffixe_arbre_binaire : arbre_binaire -> int list
