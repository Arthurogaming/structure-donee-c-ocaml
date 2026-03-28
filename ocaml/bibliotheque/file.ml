type file = {
  entree : int list;
  sortie : int list;
}

let normaliser_file file =
  match file.sortie with
  | [] -> { entree = []; sortie = List.rev file.entree }
  | _ -> file

let creer_file () =
  { entree = []; sortie = [] }

let est_vide_file file =
  file.entree = [] && file.sortie = []

let enfiler_element_file file valeur =
  { file with entree = valeur :: file.entree }

let defiler_element_file file =
  match (normaliser_file file).sortie with
  | [] -> None
  | valeur :: reste ->
      Some (valeur, { entree = []; sortie = reste })

let obtenir_tete_file file =
  match (normaliser_file file).sortie with
  | [] -> None
  | valeur :: _ -> Some valeur

let longueur_file file =
  List.length file.entree + List.length file.sortie

let vers_liste_standard_file file =
  let file_normalisee = normaliser_file file in
  file_normalisee.sortie @ List.rev file_normalisee.entree
