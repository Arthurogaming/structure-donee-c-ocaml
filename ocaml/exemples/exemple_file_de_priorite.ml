let chaine_de_liste_entiere valeurs =
  "[" ^ String.concat " ; " (List.map string_of_int valeurs) ^ "]"

let () =
  let file_de_priorite =
    File_de_priorite.creer_file_de_priorite ()
    |> fun file_de_priorite -> File_de_priorite.inserer_element_file_de_priorite file_de_priorite 7
    |> fun file_de_priorite -> File_de_priorite.inserer_element_file_de_priorite file_de_priorite 2
    |> fun file_de_priorite -> File_de_priorite.inserer_element_file_de_priorite file_de_priorite 9
    |> fun file_de_priorite -> File_de_priorite.inserer_element_file_de_priorite file_de_priorite 4
  in
  Printf.printf "File de priorite initiale : %s\n"
    (chaine_de_liste_entiere file_de_priorite);
  match File_de_priorite.supprimer_element_prioritaire_file_de_priorite file_de_priorite with
  | None -> print_endline "Aucun element prioritaire."
  | Some (valeur, reste) ->
      Printf.printf "Element prioritaire retire : %d\n" valeur;
      Printf.printf "File restante : %s\n" (chaine_de_liste_entiere reste)
