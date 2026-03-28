let () =
  let semaphore = Semaphore_abstrait.creer_semaphore_abstrait 1 in
  Printf.printf "Valeur initiale : %d\n"
    (Semaphore_abstrait.obtenir_valeur_semaphore_abstrait semaphore);
  Printf.printf "Attente reussie : %b\n"
    (Semaphore_abstrait.attendre_semaphore_abstrait semaphore);
  Printf.printf "Valeur apres attente : %d\n"
    (Semaphore_abstrait.obtenir_valeur_semaphore_abstrait semaphore);
  Semaphore_abstrait.signaler_semaphore_abstrait semaphore;
  Printf.printf "Valeur apres signal : %d\n"
    (Semaphore_abstrait.obtenir_valeur_semaphore_abstrait semaphore)
