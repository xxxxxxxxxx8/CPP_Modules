
#ifndef EXITER_HPP
# define EXITER_HPP

#include <AMateria.hpp>

#define FREE	"FREE"
#define COLL	"COLLECT"
#define PRINT	"PRINT"
#define IFID	"IFID"

typedef struct	gc_s {
	AMateria		*ptr;
	struct gc_s		*next;
}				gc_t;

class Exiter {
	public:
			Exiter();
			Exiter(const Exiter& copy);
Exiter&		operator=(const Exiter& copy);
			~Exiter();
};

void	ft_collector(AMateria* ptr, const std::string& cmd);

#endif
