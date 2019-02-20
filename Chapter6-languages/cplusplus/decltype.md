# decltype 用法介绍
## 1.作用一个变量时候var ，显示的是该变量的类型，包括顶层const和应用
	例子： 	const int ci=0,&cj=ci;
			decltype(ci) x=0; x是const int
			decltype(cj) y=x; y是const int&
			decltype(cj) z;   错误，引用必须初始化
## 2.当变量用括弧括起来的时候，此时返回的永远是引用
	例子： 	decltype((ci)) d; 错误，此时返回的是引用，应该初始化

## 3.当decltype作用与表达式的时候，表达式的结果是左值和右值有很大的区别
	当表达式的结果是左值的时候，此时返回的是引用；
	当表达式的结果是右值的时候，此时返回的不是应用；
	例子： int r=0;int *p=&r;
      decltype(r)       返回的是int
      decltype(r+0)     返回的是int
      decltype((r))     返回的是int&
      decltype(*p)      返回的是int&，因为*p是表达式，且是左值
      decltype(&p)      返回的是int**，因为&p是表达式，且是右值

      int a=1,b=2;
      decltype(a=b) c=a;返回的是int&，因为a是左值
