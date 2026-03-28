type graphe_matrice_adjacence

val creer_graphe_matrice_adjacence : int -> bool -> graphe_matrice_adjacence
val nombre_sommets_graphe_matrice_adjacence : graphe_matrice_adjacence -> int
val est_oriente_graphe_matrice_adjacence : graphe_matrice_adjacence -> bool
val ajouter_arete_graphe_matrice_adjacence : graphe_matrice_adjacence -> int -> int -> unit
val retirer_arete_graphe_matrice_adjacence : graphe_matrice_adjacence -> int -> int -> unit
val arete_existe_graphe_matrice_adjacence : graphe_matrice_adjacence -> int -> int -> bool
val voisins_graphe_matrice_adjacence : graphe_matrice_adjacence -> int -> int list
