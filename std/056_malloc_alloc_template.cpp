#if 0
#include<new>
#define __THROW_BAD_ALLOC throw bad_alloc
#elif !defined(__THROW_BAD_ALLOC)
#include<iostream.h>
#define __THROW_BAD_ALLOC cerr << "out of memory" << endl; exit(1)
#endif

template<int inst>
class __malloc_alloc_template {

	//these functions are used to process out of memory problem(oom)
	private:
		static void *oom_malloc(size_t);
		static void *oom_realloc(void *, size_t);
		static void (* __malloc_alloc_oom_handler)();
	
	public:
		static void* allocate(size_t n) {
			void *reuslt = malloc(n);
			if (0 == result) {
				result = oom_malloc(n);
			}
			return result;
		}
		static void deallocate(void *p, size_t) {
			free(p);
		}
		static void* reallocate(void *p, size_t, size_t new_sz) {
			void *result = realloc(p, new_sz);
			if (0 == result) {
				result = oom_realloc(p, new_sz);
			}
			return result;
		}

		static void (* set_malloc_handler(void (*f)())) (){
			void (* old) () = __malloc_alloc_oom_handler;
			__malloc_alloc_oom_handler = f;
			return (old);
		}
};
