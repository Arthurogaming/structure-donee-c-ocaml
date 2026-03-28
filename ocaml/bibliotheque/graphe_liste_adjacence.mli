type graphe_liste_adjacence

val creer_graphe_liste_adjacence : int -> bool -> graphe_liste_adjacence
val nombre_sommets_graphe_liste_adjacence : graphe_liste_adjacence -> int
val est_oriente_graphe_liste_adjacence : graphe_liste_adjacence -> bool
val ajouter_arete_graphe_liste_adjacence : graphe_liste_adjacence -> int -> int -> unit
val retirer_arete_graphe_liste_adjacence : graphe_liste_adjacence -> int -> int -> unit
val arete_existe_graphe_liste_adjacence : graphe_liste_adjacence -> int -> int -> bool
val voisins_graphe_liste_adjacence : graphe_liste_adjacence -> int -> int list
