
#include <Character.hpp>
#include <Exiter.hpp>

bool	is_here(AMateria* ptr, gc_t *list) {
	if (list && ptr) {
		for (gc_t *it = list;it;it=it->next) {
			if (ptr == it->ptr)
				return true;
		}
	}
	return false;
}

void	ft_delete_one(AMateria* ptr, gc_t** list) {
	if(NULL == *list)
		return ;
	if ((*list)->ptr == ptr) {
		gc_t *tmp = (*list);
		(*list) = (*list)->next;
		delete tmp;
	} else {
		for (gc_t *it=(*list);it->next;it = it->next) {
			if (it->next->ptr == ptr) {
				gc_t *tmp = it->next;
				it->next = it->next->next;
				delete tmp;
			}
		}
	}
}

void	ft_collector(AMateria* ptr, const std::string& cmd) {

	static gc_t* list = NULL;

	if (ptr && cmd == COLL && !is_here(ptr, list)) {
		gc_t* node = new gc_t;
		node->ptr = ptr;
		if (!list) {
			list = node;
			list->next = NULL;
		} else {
			node->next = list;
			list = node;
		}
	} else if (cmd == FREE && list) {
		gc_t *tmp = list;
		for (;list != NULL;) {
			tmp = list;
			list = list->next;
			delete tmp->ptr;
			delete tmp;
		}
	} else if (cmd == PRINT) {
		for (gc_t *iter = list ; iter; iter = iter->next) {
			std::cout << iter->ptr << '\n';
		}
	} else if (cmd == IFID) {
		if (is_here(ptr, list)) {
			ft_delete_one(ptr, &list);
		}
	}
}

Exiter::Exiter() {

}

Exiter::Exiter(const Exiter& copy) {
	(void)copy;
}

Exiter&		Exiter::operator=(const Exiter& copy) {
	(void)copy;
	return *this;
}

Exiter::~Exiter() {
	ft_collector(0, "FREE");
}
