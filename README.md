# Calculatrice en C++

Bienvenue dans le projet de calculatrice en C++. Cette calculatrice vous permet d'effectuer des opérations mathématiques de base en utilisant des opérateurs +, -, *, /, ^ ou les fonctions comme exp, ln, log en prenant en compte les parenthèses pour gérer la priorité des opérations. Certaine constante comme `pi` et `e`sont aussi disponible.

## Comment utiliser la calculatrice

1. Clonez ce référentiel sur votre machine locale :
   
   ```
   git clone https://github.com/Sweadex/Calculatrice.git
   ```

2. Exécutez le programme "Calculatrice.exe" se trouvant dans le dossier "bin/":

3. Vous pouvez maintenant entrer des expressions mathématiques, telles que `(2+3)*4`, et obtenir le résultat.

## Fonctionnalités

- Prise en charge des opérations mathématiques de base : addition, soustraction, multiplication et division.
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


N'oubliez pas d'utiliser des parenthèses pour spécifier la priorité des opérations. Les multiplications peuvent être implicite, par exemple : `(2+4)4` et `(2+4)*4` sont correct, ce qui renverra `20`.

## Gestion des erreurs

La calculatrice est conçue pour gérer diverses erreurs, telles que la division par zéro et les entrées incorrectes. Si une erreur survient, le programme affichera un message d'erreur explicatif.

## Contributions

Ce projet a été créé par Sweadex. Si vous souhaitez contribuer au développement de la calculatrice en C++, n'hésitez pas à ouvrir une issue ou à envoyer une demande de tirage (pull request).

Amusez-vous bien à utiliser la calculatrice en C++ !
