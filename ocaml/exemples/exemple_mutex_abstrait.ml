let () =
  let mutex = Mutex_abstrait.creer_mutex_abstrait () in
  Printf.printf "Etat initial du mutex : %b\n"
    (Mutex_abstrait.est_verrouille_mutex_abstrait mutex);
  Printf.printf "Verrouillage reussi : %b\n"
    (Mutex_abstrait.verrouiller_mutex_abstrait mutex);
  Printf.printf "Etat apres verrouillage : %b\n"
    (Mutex_abstrait.est_verrouille_mutex_abstrait mutex);
  Printf.printf "Deverrouillage reussi : %b\n"
    (Mutex_abstrait.deverrouiller_mutex_abstrait mutex)
