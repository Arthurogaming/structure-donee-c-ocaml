let chaine_de_liste_entiere valeurs =
  "[" ^ String.concat " ; " (List.map string_of_int valeurs) ^ "]"

let () =
  let graphe = Graphe_liste_adjacence.creer_graphe_liste_adjacence 4 true in
  Graphe_liste_adjacence.ajouter_arete_graphe_liste_adjacence graphe 0 1;
  Graphe_liste_adjacence.ajouter_arete_graphe_liste_adjacence graphe 0 2;
  Graphe_liste_adjacence.ajouter_arete_graphe_liste_adjacence graphe 2 3;
  Printf.printf "Voisins de 0 : %s\n"
    (chaine_de_liste_entiere
       (Graphe_liste_adjacence.voisins_graphe_liste_adjacence graphe 0));
  Printf.printf "L'arete 0 -> 2 existe : %b\n"
    (Graphe_liste_adjacence.arete_existe_graphe_liste_adjacence graphe 0 2);
  Graphe_liste_adjacence.retirer_arete_graphe_liste_adjacence graphe 0 2;
  Printf.printf "Voisins de 0 apres suppression : %s\n"
    (chaine_de_liste_entiere
       (Graphe_liste_adjacence.voisins_graphe_liste_adjacence graphe 0))
