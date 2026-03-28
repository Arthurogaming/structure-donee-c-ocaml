type arbre_binaire_de_recherche =
  | Vide
  | Noeud of int * arbre_binaire_de_recherche * arbre_binaire_de_recherche

val creer_arbre_binaire_de_recherche_vide : unit -> arbre_binaire_de_recherche
val inserer_element_arbre_binaire_de_recherche : arbre_binaire_de_recherche -> int -> arbre_binaire_de_recherche
val rechercher_element_arbre_binaire_de_recherche : arbre_binaire_de_recherche -> int -> bool
val supprimer_element_arbre_binaire_de_recherche : arbre_binaire_de_recherche -> int -> arbre_binaire_de_recherche
val parcours_prefixe_arbre_binaire_de_recherche : arbre_binaire_de_recherche -> int list
val parcours_infixe_arbre_binaire_de_recherche : arbre_binaire_de_recherche -> int list
val parcours_suffixe_arbre_binaire_de_recherche : arbre_binaire_de_recherche -> int list
