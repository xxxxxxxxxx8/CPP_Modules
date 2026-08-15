
templates:
	The process of creating functions (with specific types) from function templates (with template types) is called function template instantiation (or instantiation for short). When a function is instantiated due to a function call, it’s called implicit instantiation. A function that is instantiated from a template is technically called a specialization, but in common language is often called a function instance. The template from which a specialization is produced is called a primary template. Function instances are normal functions in all regards.




I think the offical C standard does not allow zero-size arrays, but many C/C++ compilers support it anyway.

For example, The GNU C compiler says this:
https://gcc.gnu.org/onlinedocs/gcc/Zero-Length.html

When it comes to dynamic memory allocation, malloc() officially supports zero-size allocations. Calling malloc(0) will either return a NULL pointer or a special "unique" pointer value. In both cases, it is guaranteed that the returned pointer can safely be passed to free().

Another important thing to note is that, in C++, the operator new T[n] actually allocates a memory block that is slightly larger than n times sizeof(T). That is because it allocates a little extra space where n (i.e. the length of the array) is stored. The pointer returned by new T[n] is pointing to the first element of the array, not to the beginning of the allocated memory block – because the value n is "secretly" stored right in front of the first element (i.e. at the very beginning of the memory block). It is done this way, because the delete[] operator later needs a way to figure out the actual length of the array, so that it can iterate over the array and call the destructor of each element!

That is also the reason why the delete and delete[] operators can not be used interchanagbly: The former simply destroys a sinlge object; the latter destroys and array and thus expectecs/requires the length of the array to be stored in front of the given given pointer.

If you do new T[0], it probably still allocates the extra space for n, which would hold a zero in this case, so that delete[] can work correctly.