let chaine_de_contenu_table contenu =
  let chaine_alveole alveole =
    let elements =
      List.map
        (fun element ->
          Printf.sprintf "(%d, %d)" element.cle element.valeur)
        alveole
    in
    "[" ^ String.concat " ; " elements ^ "]"
  in
  String.concat " | " (List.map chaine_alveole contenu)

let () =
  let table = Table_de_hachage.creer_table_de_hachage 5 in
  Table_de_hachage.inserer_element_table_de_hachage table 1 100;
  Table_de_hachage.inserer_element_table_de_hachage table 6 600;
  Table_de_hachage.inserer_element_table_de_hachage table 11 1100;
  Printf.printf "Contenu de la table : %s\n"
    (chaine_de_contenu_table (Table_de_hachage.contenu_table_de_hachage table));
  begin
    match Table_de_hachage.rechercher_element_table_de_hachage table 6 with
    | None -> print_endline "Cle 6 absente."
    | Some valeur -> Printf.printf "Valeur associee a la cle 6 : %d\n" valeur
  end;
  ignore (Table_de_hachage.supprimer_element_table_de_hachage table 1);
  Printf.printf "Apres suppression de la cle 1 : %s\n"
    (chaine_de_contenu_table (Table_de_hachage.contenu_table_de_hachage table))
