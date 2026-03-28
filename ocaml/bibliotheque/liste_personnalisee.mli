type liste_personnalisee =
  | Vide
  | Noeud of int * liste_personnalisee

val creer_liste_personnalisee : unit -> liste_personnalisee
val est_vide_liste_personnalisee : liste_personnalisee -> bool
val ajouter_element_en_tete_liste_personnalisee : liste_personnalisee -> int -> liste_personnalisee
val ajouter_element_en_queue_liste_personnalisee : liste_personnalisee -> int -> liste_personnalisee
val supprimer_premier_element_liste_personnalisee : liste_personnalisee -> (int * liste_personnalisee) option
val longueur_liste_personnalisee : liste_personnalisee -> int
val vers_liste_standard_liste_personnalisee : liste_personnalisee -> int list
val chaine_de_liste_personnalisee : liste_personnalisee -> string
