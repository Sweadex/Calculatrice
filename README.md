# Calculatrice en C++

Bienvenue dans le projet de calculatrice en C++. Cette calculatrice vous permet d'effectuer des opérations mathématiques de base en utilisant des opérateurs +, -, *, /, ^, ainsi que des fonctions telles que sqrt, exp, ln, log, en prenant en compte les parenthèses pour gérer la priorité des opérations. Certaines constantes telles que `pi` et `e` sont également disponibles.

## Comment utiliser la calculatrice

1. Téléchargez et exécutez le programme "Calculatrice.exe" se trouvant dans la dernière Releases :

2. Vous pouvez maintenant entrer des expressions mathématiques, telles que `(2+3)*4`, et obtenir le résultat.

## Fonctionnalités

- Prise en charge des opérations mathématiques de base : addition, soustraction, multiplication, division et puissance.
- Prise en charge des fonctions mathématiques de base : racine carrée, exponentielle, logarithme népérien et logarithme décimal.
- Prise en charge des constantes mathématiques de base : `pi` et `e`.
- Possibilité d'inclure le dernier résultat obtenu dans la prochaine opération avec `ans`.
- Gestion des multiplications implicites.
- Gestion des parenthèses pour définir la priorité des opérations.
- Gestion des erreurs, y compris la division par zéro et les entrées incorrectes.

## Exemple d'utilisation

1. Addition : `2+3` renverra `5`.
2. Soustraction : `5-2` renverra `3`.
3. Multiplication : `2*pi` renverra `6,28318`.
4. Division : `8/2` renverra `4`.
5. Puissance : `2^4` renverra `16`.
6. Exponentielle : `e^2` ou `exp2` renverra `7.38906`.
7. Racine carrée : `sqrt16` renverra `4`.
8. Logarithme népérien : `ln(e)` renverra `1`.
9. Logarithme décimal : `log100` renverra `10`.
10. Résultats précédents : `2+2` renverra `4` puis `ans*2` renverra `8`.


N'oubliez pas d'utiliser des parenthèses pour spécifier la priorité des opérations. Les multiplications peuvent être implicites, par exemple : `(2+4)4` et `(2+4)*4` sont correctes, ce qui renverra `20`.

## Gestion des erreurs

La calculatrice est conçue pour gérer diverses erreurs, telles que la division par zéro et les entrées incorrectes. Si une erreur survient, le programme affichera un message d'erreur explicatif.

## Contributions

Ce projet a été créé par Sweadex. Si vous souhaitez contribuer au développement de la calculatrice en C++, n'hésitez pas à ouvrir une issue.

Amusez-vous bien à utiliser la calculatrice en C++ !
