type entree_table_de_hachage = {
  cle : int;
  valeur : int;
}

type table_de_hachage

val creer_table_de_hachage : int -> table_de_hachage
val capacite_table_de_hachage : table_de_hachage -> int
val inserer_element_table_de_hachage : table_de_hachage -> int -> int -> unit
val rechercher_element_table_de_hachage : table_de_hachage -> int -> int option
val supprimer_element_table_de_hachage : table_de_hachage -> int -> bool
val contenu_table_de_hachage : table_de_hachage -> entree_table_de_hachage list list
