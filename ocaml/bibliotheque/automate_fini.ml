type automate_fini = {
  alphabet : char list;
  transitions : int option array array;
  etat_initial : int;
  etats_finaux : bool array;
}

let creer_automate_fini nombre_etats alphabet etat_initial =
  if nombre_etats <= 0 then invalid_arg "nombre_etats non positif";
  if etat_initial < 0 || etat_initial >= nombre_etats then invalid_arg "etat_initial hors limites";
  if alphabet = [] then invalid_arg "alphabet vide";
  {
    alphabet;
    transitions =
      Array.init nombre_etats (fun _ -> Array.make (List.length alphabet) None);
    etat_initial;
    etats_finaux = Array.make nombre_etats false;
  }

let verifier_etat_automate_fini automate etat =
  if etat < 0 || etat >= Array.length automate.transitions then
    invalid_arg "etat hors limites"

let rec trouver_indice_symbole_automate_fini alphabet symbole =
  match alphabet with
  | [] -> None
  | symbole_courant :: reste ->
      if symbole_courant = symbole then
        Some 0
      else
        Option.map (fun indice -> indice + 1) (trouver_indice_symbole_automate_fini reste symbole)

let definir_transition_automate_fini automate etat_source symbole etat_destination =
  verifier_etat_automate_fini automate etat_source;
  verifier_etat_automate_fini automate etat_destination;
  match trouver_indice_symbole_automate_fini automate.alphabet symbole with
  | None -> invalid_arg "symbole absent de l_alphabet"
  | Some indice -> automate.transitions.(etat_source).(indice) <- Some etat_destination

let definir_etat_final_automate_fini automate etat est_final =
  verifier_etat_automate_fini automate etat;
  automate.etats_finaux.(etat) <- est_final

let mot_est_reconnu_automate_fini automate mot =
  let longueur_mot = String.length mot in
  let rec parcourir position etat_courant =
    if position = longueur_mot then
      automate.etats_finaux.(etat_courant)
    else
      match trouver_indice_symbole_automate_fini automate.alphabet mot.[position] with
      | None -> false
      | Some indice_symbole -> (
          match automate.transitions.(etat_courant).(indice_symbole) with
          | None -> false
          | Some etat_suivant -> parcourir (position + 1) etat_suivant)
  in
  parcourir 0 automate.etat_initial

let alphabet_automate_fini automate =
  automate.alphabet

let etats_finaux_automate_fini automate =
  let resultat = ref [] in
  for indice = Array.length automate.etats_finaux - 1 downto 0 do
    if automate.etats_finaux.(indice) then resultat := indice :: !resultat
  done;
  !resultat
