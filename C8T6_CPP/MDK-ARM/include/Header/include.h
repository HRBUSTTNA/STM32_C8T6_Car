#ifndef INCLUDE_H_
#define INCLUDE_H_

#ifdef __cplusplus
extern "C"
{
#endif
//这里添加CPP函数，因为CPP无法正确被C调用，因此要进行转换
	void cpp_main();
	void cpp_while_main();
#ifdef __cplusplus
}
#endif

#endif