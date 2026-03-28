type automate_fini

val creer_automate_fini : int -> char list -> int -> automate_fini
val definir_transition_automate_fini : automate_fini -> int -> char -> int -> unit
val definir_etat_final_automate_fini : automate_fini -> int -> bool -> unit
val mot_est_reconnu_automate_fini : automate_fini -> string -> bool
val alphabet_automate_fini : automate_fini -> char list
val etats_finaux_automate_fini : automate_fini -> int list
