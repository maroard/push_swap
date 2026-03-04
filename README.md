*This project has been created as part of the 42 curriculum by eolivier and maroard.*

## Description
**Push_swap** est un projet d'algorithmie dont l'objectif est de trier une pile de données (Stack A) en utilisant une pile auxiliaire (Stack B) et un set d'instructions limité. 

Pour optimiser le nombre de coups tout en respectant les contraintes de performance, nous avons sélectionné et implémenté les algorithmes suivants :
* **Simple Strategy (Min-Max) :** Pour les piles de petite taille, nous utilisons une stratégie d'extraction du minimum et du maximum afin de réduire drastiquement le nombre d'opérations.
* **Medium Strategy :** Une approche basée sur des "chunk " (plages de valeurs) pour assurer une transition fluide entre les petits et les grands ensembles.
* **Radix Sort (LSD) :** Utilisé pour les listes importantes, ce tri par base (Least Significant Digit) traite les nombres selon leur représentation binaire, garantissant une efficacité constante sur de grands volumes de données.


## Justification des choix algorithmiques
Le choix de nos algorithmes repose sur un compromis entre efficacité (nombre de coups) et rigueur logique :

* **Radix Sort (LSD) :** Nous avons choisi le Radix pour sa prédictibilité. Contrairement à d'autres tris, sa complexité temporelle est stable en $O(n \times k)$ (où $k$ est le nombre de bits). Cela garantit que, même avec un set de 500 nombres très désordonnés, le programme ne dépassera jamais un seuil critique d'opérations. Peut importe le desordre il fera toujours le meme nombre d'opperation

**Stratégie Min-Max (Extraction Sélective) :**
* **Principe :** Recherche du minimum/maximum absolu pour l'isoler et le pousser.
* **Usage :** Idéal pour les petites piles où le coût de recherche est compensé par un tri immédiat.

**Stratégie Chunk-Based (Découpage par Plages) :**
* **Principe :** Utilisation d'une "fenêtre glissante" dynamique indexée. On attribue un index à chaque nombre (de 0 à N-1). On parcourt la Stack A et on pousse les éléments vers la Stack B si leur index appartient à une plage définie qui s'élargit progressivement.
* **Justification :**Contrairement aux chunks statiques, le range-based permet une distribution en forme de "sablier" ou de "papillon" dans la Stack B (les plus petits et les plus grands se retrouvent aux extrémités). Cela réduit drastiquement le nombre de rotations (ra/rra) lors de la phase de remontée vers la Stack A, car les éléments sont déjà pré-triés de manière approximative.

## Instructions

### Compilation
Le projet utilise un `Makefile` pour automatiser la compilation. Les commandes disponibles sont :

* `make` : Compile l'exécutable principal `push_swap`.
* `make bonus` : Compile l'exécutable `checker` pour vérifier manuellement le tri.
* `make clean` : Supprime les fichiers objets (`.o`).
* `make fclean` : Supprime les fichiers objets et les exécutables.
* `make re` : Réinitialise le projet (fclean + make).

### Exécution
Pour lancer le trieur :
```bash
./push_swap 3 2 1
```
## L'Arbitre du Tri : Implémentation du Checker

Le bonus de ce projet consiste en la création d'un programme de vérification autonome nommé `checker`. Son rôle est d'agir comme un juge impartial pour valider la validité et l'efficacité de l'algorithme de tri.

### Fonctionnement Technique
Le `checker` fonctionne comme un interpréteur de commandes en temps réel :
* **Lecture des instructions :** Il écoute sur l'entrée standard (`stdin`) les opérations générées par `push_swap` (ex: `sa`, `pb`, `rra`).
* **Exécution sur pile :** Pour chaque instruction valide, il applique la transformation correspondante sur une réplique de la pile initiale.
* **Gestion d'erreurs :** Si une instruction lue n'existe pas ou est mal formatée, le programme arrête immédiatement l'exécution et affiche `Error` sur la sortie d'erreur.

### Verdict et Validation
Une fois le flux d'instructions terminé (EOF), le programme effectue une double vérification :
1. **État de la Stack A :** Tous les nombres doivent être classés par ordre croissant.
2. **État de la Stack B :** La pile auxiliaire doit être impérativement vide.

**Résultats :**
* **`OK`** : La pile est triée et la mémoire est propre.
* **`KO`** : La pile n'est pas triée ou la Stack B contient encore des éléments.

### Exemple d'utilisation
L'utilisation de "pipes" permet d'automatiser la vérification du tri :
```bash
ARG="3 5 1 2 4"; ./push_swap $ARG | ./checker $ARG
```

## Resources
* **Documentation :**
    * [Tutoriel Push_swap - Mécaniques de base](https://www.youtube.com/watch?v=1RHwovkGLuw)
    * [Analyse approfondie des algorithmes de tri](https://www.youtube.com/watch?v=4dMsuxfqufg)
* **Articles :** https://medium.com/nerd-for-tech/push-swap-tutorial-fa746e6aba1e

### Rapport d'usage de l'IA (Gemini)
Conformément aux directives, nous déclarons l'utilisation de l'IA pour les tâches suivantes :
* **Rédaction technique :** Structuration et mise en forme du fichier `README.md` pour respecter les standards de documentation.
* **Débogage ponctuel :** Assistance lors de phases de blocage sur la logique des rotations inverses et l'identification de certains cas d'erreurs (leaks de mémoire ou mauvaises manipulations d'index) lors de l'implémentation du `checker`.
* **Note :** Toute la logique algorithmique fondamentale, la structure des données (listes/tableaux) et le parsing des arguments ont été conçus et codés manuellement par les auteurs.
