let chaine_de_liste_entiere valeurs =
  "[" ^ String.concat " ; " (List.map string_of_int valeurs) ^ "]"

let () =
  let graphe = Graphe_matrice_adjacence.creer_graphe_matrice_adjacence 4 false in
  Graphe_matrice_adjacence.ajouter_arete_graphe_matrice_adjacence graphe 0 1;
  Graphe_matrice_adjacence.ajouter_arete_graphe_matrice_adjacence graphe 0 2;
  Graphe_matrice_adjacence.ajouter_arete_graphe_matrice_adjacence graphe 2 3;
  Printf.printf "Voisins de 0 : %s\n"
    (chaine_de_liste_entiere
       (Graphe_matrice_adjacence.voisins_graphe_matrice_adjacence graphe 0));
  Graphe_matrice_adjacence.retirer_arete_graphe_matrice_adjacence graphe 0 2;
  Printf.printf "Voisins de 0 apres suppression : %s\n"
    (chaine_de_liste_entiere
       (Graphe_matrice_adjacence.voisins_graphe_matrice_adjacence graphe 0))
