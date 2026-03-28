type graphe_matrice_adjacence = {
  est_oriente : bool;
  matrice_adjacence : bool array array;
}

let creer_graphe_matrice_adjacence nombre_sommets est_oriente =
  if nombre_sommets < 0 then invalid_arg "nombre_sommets negatif";
  {
    est_oriente;
    matrice_adjacence = Array.make_matrix nombre_sommets nombre_sommets false;
  }

let nombre_sommets_graphe_matrice_adjacence graphe =
  Array.length graphe.matrice_adjacence

let est_oriente_graphe_matrice_adjacence graphe =
  graphe.est_oriente

let verifier_sommet_graphe_matrice_adjacence graphe sommet =
  if sommet < 0 || sommet >= nombre_sommets_graphe_matrice_adjacence graphe then
    invalid_arg "sommet hors limites"

let ajouter_arete_graphe_matrice_adjacence graphe sommet_source sommet_destination =
  verifier_sommet_graphe_matrice_adjacence graphe sommet_source;
  verifier_sommet_graphe_matrice_adjacence graphe sommet_destination;
  graphe.matrice_adjacence.(sommet_source).(sommet_destination) <- true;
  if not graphe.est_oriente then
    graphe.matrice_adjacence.(sommet_destination).(sommet_source) <- true

let retirer_arete_graphe_matrice_adjacence graphe sommet_source sommet_destination =
  verifier_sommet_graphe_matrice_adjacence graphe sommet_source;
  verifier_sommet_graphe_matrice_adjacence graphe sommet_destination;
  graphe.matrice_adjacence.(sommet_source).(sommet_destination) <- false;
  if not graphe.est_oriente then
    graphe.matrice_adjacence.(sommet_destination).(sommet_source) <- false

let arete_existe_graphe_matrice_adjacence graphe sommet_source sommet_destination =
  verifier_sommet_graphe_matrice_adjacence graphe sommet_source;
  verifier_sommet_graphe_matrice_adjacence graphe sommet_destination;
  graphe.matrice_adjacence.(sommet_source).(sommet_destination)

let voisins_graphe_matrice_adjacence graphe sommet =
  verifier_sommet_graphe_matrice_adjacence graphe sommet;
  let resultat = ref [] in
  for indice = nombre_sommets_graphe_matrice_adjacence graphe - 1 downto 0 do
    if graphe.matrice_adjacence.(sommet).(indice) then
      resultat := indice :: !resultat
  done;
  !resultat
