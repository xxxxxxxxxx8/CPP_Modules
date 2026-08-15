
#include <MateriaSource.hpp>

MateriaSource::MateriaSource() {
	std::cout << "MateriaSource default constructor called\n";
	Materias[0] = NULL;
	Materias[1] = NULL;
	Materias[2] = NULL;
	Materias[3] = NULL;
}

MateriaSource::MateriaSource(const MateriaSource& copy) : IMateriaSource(copy) {
	std::cout << "MateriaSource copy constructor called\n";
	for (int i = 0; i < 4; i++) {
		if (copy.Materias[i]) {
			Materias[i] = copy.Materias[i]->clone();
		}
		else
			Materias[i] = NULL;
	}
}

MateriaSource::~MateriaSource() {

	std::cout << "MateriaSource destructor called\n";
		for (int i(0); i < 4; i++) {
		if (Materias[i]) {
			delete Materias[i];
		}
	}
}

MateriaSource&	MateriaSource::operator=(const MateriaSource& copy) {
	std::cout << "MateriaSource copy assignment operator overload function called\n";
	for (int i(0); i < 4; i++) {
		if (Materias[i]) {
			delete Materias[i];
			Materias[i] = copy.Materias[i] ? copy.Materias[i]->clone() : NULL;
		} else {
			Materias[i] = copy.Materias[i] ? copy.Materias[i]->clone() : NULL;
		}
	}
	return *this;
}

void 	MateriaSource::learnMateria(AMateria* mat) {
	if (NULL == mat) {
		std::cerr << "learn material pointer is NULL!\n";
		return ;
	}
	bool	is_full = true;
	for (int i(0); i < 4; i++) {
		if (!Materias[i]) {
			Materias[i] = mat;
			is_full = false;
			break ;
		}
	}
	(void)(is_full  ? (bool)(std::cout << "Materias are all full, can't learn more!\n") : false);

}

AMateria* 	MateriaSource::createMateria(std::string const & type) {

	for (int i(0); i < 4; i++) {
		if (Materias[i] && Materias[i]->getType() == type) {
			return Materias[i]->clone();
		}
	}
	std::cout << "there's no Materia of type: " << type << '\n';
	return NULL;
}
