type pile = int list

let creer_pile () = []

let est_vide_pile pile =
  pile = []

let empiler_element_pile pile valeur =
  valeur :: pile

let depiler_element_pile pile =
  match pile with
  | [] -> None
  | valeur :: reste -> Some (valeur, reste)

let obtenir_sommet_pile pile =
  match pile with
  | [] -> None
  | valeur :: _ -> Some valeur

let longueur_pile pile =
  List.length pile
