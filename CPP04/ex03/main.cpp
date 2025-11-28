/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcotonea <mcotonea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 09:54:53 by mcotonea          #+#    #+#             */
/*   Updated: 2025/07/02 13:00:19 by mcotonea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "AMateria.hpp"
#include "ICharacter.hpp"
#include "IMateriaSource.hpp"
#include "MateriaSource.hpp"

// int main()
// {
//     Character bob("Bob");
//     Character alice("Alice");

//     AMateria* ice1 = new Ice();
//     AMateria* cure1 = new Cure();
//     AMateria* ice2 = new Ice();
//     AMateria* cure2 = new Cure();
//     AMateria* extra = new Ice();

//     // Equip 4 materias
//     bob.equip(ice1);
//     bob.equip(cure1);
//     bob.equip(ice2);
//     bob.equip(cure2);

//     // Essayer d'ajouter une 5eme materia
//     std::cout << "Trying to equip a 5th materia:" << std::endl;
//     bob.equip(extra);

//     std::cout << "\n-- Use materias on Alice --\n";
//     for (int i = 0; i < 4; ++i)
//         bob.use(i, alice);

//     std::cout << "\n-- Unequip slot 2 and try to use it --\n";
//     bob.unequip(2);
//     bob.use(2, alice);

//     std::cout << "\n-- Test invalid indices --\n";
//     bob.use(-1, alice);
//     bob.use(4, alice);
//     bob.unequip(-1);
//     bob.unequip(4);

//     delete extra;

//     return 0;
// }

int main()
{
    IMateriaSource* src = new MateriaSource();
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());
    ICharacter* me = new Character("me");
    AMateria* tmp;
    tmp = src->createMateria("ice");
    me->equip(tmp);
    tmp = src->createMateria("cure");
    me->equip(tmp);
    ICharacter* bob = new Character("bob");
    me->use(0, *bob);
    me->use(1, *bob);
    delete bob;
    delete me;
    delete src;
    return 0;
}