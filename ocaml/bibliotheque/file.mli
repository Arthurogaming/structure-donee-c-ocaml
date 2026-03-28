type file = {
  entree : int list;
  sortie : int list;
}

val creer_file : unit -> file
val est_vide_file : file -> bool
val enfiler_element_file : file -> int -> file
val defiler_element_file : file -> (int * file) option
val obtenir_tete_file : file -> int option
val longueur_file : file -> int
val vers_liste_standard_file : file -> int list
