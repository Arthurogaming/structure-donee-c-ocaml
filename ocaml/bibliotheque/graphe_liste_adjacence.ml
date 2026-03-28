type graphe_liste_adjacence = {
  est_oriente : bool;
  listes_adjacence : int list array;
}

let creer_graphe_liste_adjacence nombre_sommets est_oriente =
  if nombre_sommets < 0 then invalid_arg "nombre_sommets negatif";
  {
    est_oriente;
    listes_adjacence = Array.make nombre_sommets [];
  }

let nombre_sommets_graphe_liste_adjacence graphe =
  Array.length graphe.listes_adjacence

let est_oriente_graphe_liste_adjacence graphe =
  graphe.est_oriente

let verifier_sommet_graphe_liste_adjacence graphe sommet =
  if sommet < 0 || sommet >= nombre_sommets_graphe_liste_adjacence graphe then
    invalid_arg "sommet hors limites"

let rec ajouter_voisin_liste_adjacence liste sommet =
  if List.mem sommet liste then liste else sommet :: liste

let rec retirer_voisin_liste_adjacence liste sommet =
  match liste with
  | [] -> []
  | sommet_courant :: reste ->
      if sommet_courant = sommet then reste else sommet_courant :: retirer_voisin_liste_adjacence reste sommet

let ajouter_arete_graphe_liste_adjacence graphe sommet_source sommet_destination =
  verifier_sommet_graphe_liste_adjacence graphe sommet_source;
  verifier_sommet_graphe_liste_adjacence graphe sommet_destination;
  graphe.listes_adjacence.(sommet_source) <-
    ajouter_voisin_liste_adjacence graphe.listes_adjacence.(sommet_source) sommet_destination;
  if not graphe.est_oriente then
    graphe.listes_adjacence.(sommet_destination) <-
      ajouter_voisin_liste_adjacence graphe.listes_adjacence.(sommet_destination) sommet_source

let retirer_arete_graphe_liste_adjacence graphe sommet_source sommet_destination =
  verifier_sommet_graphe_liste_adjacence graphe sommet_source;
  verifier_sommet_graphe_liste_adjacence graphe sommet_destination;
  graphe.listes_adjacence.(sommet_source) <-
    retirer_voisin_liste_adjacence graphe.listes_adjacence.(sommet_source) sommet_destination;
  if not graphe.est_oriente then
    graphe.listes_adjacence.(sommet_destination) <-
      retirer_voisin_liste_adjacence graphe.listes_adjacence.(sommet_destination) sommet_source

let arete_existe_graphe_liste_adjacence graphe sommet_source sommet_destination =
  verifier_sommet_graphe_liste_adjacence graphe sommet_source;
  verifier_sommet_graphe_liste_adjacence graphe sommet_destination;
  List.mem sommet_destination graphe.listes_adjacence.(sommet_source)

let voisins_graphe_liste_adjacence graphe sommet =
  verifier_sommet_graphe_liste_adjacence graphe sommet;
  List.rev graphe.listes_adjacence.(sommet)
