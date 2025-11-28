/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melvin <melvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 22:50:47 by melvin            #+#    #+#             */
/*   Updated: 2025/07/01 23:01:18 by melvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main(){
    {
        std::cout << "Fil in a table with half Dog and half Cat" << std::endl;
        const int size = 6;
        Animal* animals[size];
        
        for (int i = 0; i < size / 2; ++i)
            animals[i] = new Dog();
        for (int i = size / 2; i < size; ++i)
            animals[i] = new Cat();

        for (int i = 0; i < size; ++i)
            animals[i]->makeSound();
        
        for (int i = 0; i < size; ++i)
            delete animals[i];

  }
        std::cout << std::endl;
    {
        std::cout << "Testing the deep copy of the Cat class" << std::endl;
        Cat cat1;
        cat1.makeSound();
        cat1.getType();

        cat1.setIdea(0, "Chase the laser pointer!");
        std::cout << "cat1's idea 0: " << cat1.getIdea(0) << std::endl;

        Cat cat2(cat1);
        std::cout << "cat2's idea 0 (after copy): " << cat2.getIdea(0) << std::endl;

        cat2.setIdea(0, "Sleep on the keyboard.");
        std::cout << "cat1's idea 0: " << cat1.getIdea(0) << std::endl;
        std::cout << "cat2's idea 0: " << cat2.getIdea(0) << std::endl; 

    }
    std::cout << std::endl;
    {	
        std::cout << "Testing the deep copy of the Dog class" << std::endl;
        Dog dog1;
        dog1.makeSound();
        std::cout << "dog1 type: " << dog1.getType() << std::endl;

        dog1.setIdea(0, "Bury the bone!");
        std::cout << "dog1's idea 0: " << dog1.getIdea(0) << std::endl;

        Dog dog2(dog1);
        std::cout << "dog2's idea 0 (after copy): " << dog2.getIdea(0) << std::endl;

        dog2.setIdea(0, "Chase the cat!");
        std::cout << "dog1's idea 0: " << dog1.getIdea(0) << std::endl;
        std::cout << "dog2's idea 0: " << dog2.getIdea(0) << std::endl;
    }
    std::cout << std::endl;
    return 0;
}
