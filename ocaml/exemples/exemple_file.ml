let chaine_de_liste_entiere valeurs =
  "[" ^ String.concat " ; " (List.map string_of_int valeurs) ^ "]"

let () =
  let file =
    File.creer_file ()
    |> fun file -> File.enfiler_element_file file 4
    |> fun file -> File.enfiler_element_file file 9
    |> fun file -> File.enfiler_element_file file 12
  in
  begin
    match File.obtenir_tete_file file with
    | None -> print_endline "File vide."
    | Some tete -> Printf.printf "Tete de la file : %d\n" tete
  end;
  match File.defiler_element_file file with
  | None -> print_endline "Aucun element a defiler."
  | Some (valeur, file_restante) ->
      Printf.printf "Element defile : %d\n" valeur;
      Printf.printf "File restante : %s\n"
        (chaine_de_liste_entiere (File.vers_liste_standard_file file_restante))
