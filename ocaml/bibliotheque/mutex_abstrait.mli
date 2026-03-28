type mutex_abstrait

val creer_mutex_abstrait : unit -> mutex_abstrait
val est_verrouille_mutex_abstrait : mutex_abstrait -> bool
val verrouiller_mutex_abstrait : mutex_abstrait -> bool
val deverrouiller_mutex_abstrait : mutex_abstrait -> bool
