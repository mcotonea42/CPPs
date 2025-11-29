# 42 C++ Modules

![Language](https://img.shields.io/badge/Language-C%2B%2B98-00599C?style=for-the-badge&logo=c%2B%2B)
![School](https://img.shields.io/badge/School-42-000000?style=for-the-badge&logo=42)
![Status](https://img.shields.io/badge/Status-Completed-success?style=for-the-badge)

## 📝 Description

Ce dépôt contient l'intégralité des modules C++ réalisés dans le cadre du cursus de l'école 42.
Cette série de projets a pour but d'effectuer la transition de la programmation impérative (C) vers la **Programmation Orientée Objet (POO)**, en respectant rigoureusement le standard **C++98**.

Chaque module aborde un concept spécifique du langage, allant de la syntaxe de base jusqu'à l'utilisation avancée de la STL (Standard Template Library).

## 🛠️ Concepts & Technologies

* **Forme Canonique Orthodoxe** (Constructeur, Destructeur, Copie, Assignation) obligatoire pour toutes les classes à partir du CPP02.
* **Compilation :** `c++ -Wall -Wextra -Werror -std=c++98`.

## 📚 Liste des Modules

| Module | Sujet Principal | Concepts Clés Abordés |
| :--- | :--- | :--- |
| **CPP 00** | Introduction | Class basics, Member functions, Stdio streams, Init lists. |
| **CPP 01** | Mémoire & Pointeurs | `new`/`delete`, Références vs Pointeurs, File streams. |
| **CPP 02** | Polymorphisme Ad-hoc | Surcharge d'opérateurs (Overloading), Forme Canonique Orthodoxe. |
| **CPP 03** | Héritage | Héritage simple et multiple, Diamond problem (`virtual`). |
| **CPP 04** | Polymorphisme | Sous-typage, Classes abstraites, Interfaces, Destructeurs virtuels. |
| **CPP 05** | Robustesse | Exceptions (`try`/`catch`), Classes d'exception personnalisées. |
| **CPP 06** | Casts | `static_cast`, `dynamic_cast`, `reinterpret_cast`. |
| **CPP 07** | Templates | Templates de fonctions et de classes. |
| **CPP 08** | STL (Basique) | Containers (`vector`, `list`, `map`), Algorithmes, Itérateurs. |
| **CPP 09** | STL (Avancé) | Conteneurs adaptés (`stack`, `deque`), Algorithmes complexes. |

## 🚀 Utilisation

Chaque module contient son propre `Makefile`. Pour tester un exercice spécifique :

1. Entrer dans le dossier du module et de l'exercice :
   ```bash
   cd CPP0X/ex0Y
   make
   ./[nom_éxécutable]
   ```