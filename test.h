#ifndef TEST_H_
#define TEST_H_

typedef struct 	s_params
{
	void 	*param;
	void	(*callback)();
}		t_param;


void init_ptr_and_call(void * param, void (*ptr)(t_param), void (*func)())
{
	t_param args;

	args.param = param;
	args.callback = func;
	ptr(args);
}

void func(t_param arg);

#endif