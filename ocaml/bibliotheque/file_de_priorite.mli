type file_de_priorite = int list

val creer_file_de_priorite : unit -> file_de_priorite
val est_vide_file_de_priorite : file_de_priorite -> bool
val inserer_element_file_de_priorite : file_de_priorite -> int -> file_de_priorite
val supprimer_element_prioritaire_file_de_priorite : file_de_priorite -> (int * file_de_priorite) option
val obtenir_element_prioritaire_file_de_priorite : file_de_priorite -> int option
