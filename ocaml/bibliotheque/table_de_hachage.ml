type entree_table_de_hachage = {
  cle : int;
  valeur : int;
}

type table_de_hachage = {
  alveoles : entree_table_de_hachage list array;
}

let creer_table_de_hachage capacite =
  let capacite_corrigee = max 1 capacite in
  { alveoles = Array.make capacite_corrigee [] }

let capacite_table_de_hachage table =
  Array.length table.alveoles

let indice_pour_cle_table_de_hachage table cle =
  let capacite = capacite_table_de_hachage table in
  let reste = cle mod capacite in
  if reste < 0 then reste + capacite else reste

let inserer_element_table_de_hachage table cle valeur =
  let indice = indice_pour_cle_table_de_hachage table cle in
  let rec remplacer_ou_ajouter_elements elements =
    match elements with
    | [] -> [ { cle; valeur } ]
    | element_courant :: reste when element_courant.cle = cle ->
        { cle; valeur } :: reste
    | element_courant :: reste ->
        element_courant :: remplacer_ou_ajouter_elements reste
  in
  table.alveoles.(indice) <- remplacer_ou_ajouter_elements table.alveoles.(indice)

let rechercher_element_table_de_hachage table cle =
  let indice = indice_pour_cle_table_de_hachage table cle in
  let rec chercher elements =
    match elements with
    | [] -> None
    | element_courant :: reste ->
        if element_courant.cle = cle then Some element_courant.valeur else chercher reste
  in
  chercher table.alveoles.(indice)

let supprimer_element_table_de_hachage table cle =
  let indice = indice_pour_cle_table_de_hachage table cle in
  let suppression_effectuee = ref false in
  let rec retirer_elements elements =
    match elements with
    | [] -> []
    | element_courant :: reste when element_courant.cle = cle ->
        suppression_effectuee := true;
        reste
    | element_courant :: reste ->
        element_courant :: retirer_elements reste
  in
  table.alveoles.(indice) <- retirer_elements table.alveoles.(indice);
  !suppression_effectuee

let contenu_table_de_hachage table =
  Array.to_list table.alveoles
