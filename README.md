# Philosophers

Simulation du problème des philosophes en C avec threads et mutex. Chaque philosophe alterne entre manger, dormir et réfléchir ; le programme surveille les délais et les arrêts.

## Compilation et lancement

    make
    ./philo nombre_de_philosophes temps_mort_ms temps_repas_ms temps_sommeil_ms [repas_par_philosophe]

Les durées sont exprimées en millisecondes. Le dernier argument est facultatif.

## Sujet 42

Le sujet officiel est consultable sur la [page Projets de l’intranet 42](https://projects.intra.42.fr/) après connexion. Le PDF n’est pas recopié dans ce dépôt.
