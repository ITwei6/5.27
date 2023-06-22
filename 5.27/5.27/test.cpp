#include <iostream>
using namespace std;
//class sum {
//public:
//    sum()
//    {
//        _ret += _i;
//        ++_i;
//    }
//    static int GetRet()
//    {
//        return _ret;
//    }
//private:
//    static int _i;
//    static int _ret;
//};
//int sum::_i = 1;
//int sum::_ret = 0;
//class Solution {
//public:
//    int Sum_Solution(int n) {
//
//        //sum a[n];//调用n次构造函数。
//        return sum::GetRet();
//    }
//};
//
//
//class Solution {
//    //默认是私有的，如果想让别人访问可以写public
//    class sum {
//    public:
//        sum()//内部类，天生是外部类的友元，可以使用外部类的成员变量，因为为静态成员，所以不需要对象就可以使用
//        {
//            _ret += _i;
//            ++_i;
//        }
//    };
//public:
//    int Sum_Solution(int n) {
//
//       // sum a[n];//调用n次构造函数。
//        return _ret;//这里可以直接返回——ret因为它就是类的成员变量
//    }
//private:
//    static int _i;
//    static int _ret;
//};
//int Solution::_i = 1;
//int Solution::_ret = 0;
//
//class A
//{
//public:
//    class B
//    {
//    public:
//        void func(const A& a1)
//        {
//            cout << _a << endl;
//            cout << a1.x << endl;
//        }
//    };
//private: 
//   static int _a;
//    int x=0;
//    B b1;
//};
//int A::_a = 1;
//int main()
//{
//    A a1;
//    cout << sizeof(A) << endl;
//    /*A::B b1;
//    b1.func(a1);*/
//}
//int main()
//{
//	A(2);//匿名对象
//	cout << "----" << endl;
//	A aa1(1);//有名对象
//	cout << "----" << endl;
//}
//class A
//{
//public:
//	A(int a = 10)
//		:_a(a)
//	{
//		cout << "A(int a = 10)" << endl;
//	}
//
//	~A()
//	{
//		cout << "~A()" << endl;
//	}
//	
//private:
//	int _a;
//};
//class Solution {
//public:
//	int Sum_Solution(int n) {
//		cout << "Sum_Solution(int n)" << endl;
//	}
//};
//int main()
//{
//	
//	Solution().Sum_Solution(10);//匿名对象调用成员函数，一次性的
//}
class A
{
public:
	A(int a = 10)
		:_a(a)
	{
	   cout << "A(int a = 10)" << endl;
	}	
	A(const A& aa)
		:_a(aa._a)
	{
		cout << "A(const A& aa)" << endl;
	}
	A& operator=(const A& aa)
	{
		if (this != &aa)
		{
			_a = aa._a;
		}
		return *this;
   }
	~A()
	{
	   cout << "~A()" << endl;
	}
private:
	int _a;
};
A Func1()
{
	A aa2;
	return aa2;
}

int main()
{
	A aa1 = 2;//构造+拷贝---->优化成构造
	
	A aa3 = Func1();//拷贝+拷贝-->一次拷贝
	
	cout << "----------" << endl;
	A aa5;//构造函数
	aa3 = Func1();//拷贝函数+赋值运算符重载
}
void f1(A aa)
{}
A f2()
{
	A aa;
	return aa;
}
int main()
{
	// 传值传参
	A aa1;
	f1(aa1);
	cout << endl;
	// 传值返回
	f2();
	cout << endl;
	// 隐式类型，连续构造+拷贝构造->优化为直接构造
	f1(1);
	// 一个表达式中，连续构造+拷贝构造->优化为一个构造
	f1(A(2));
	cout << endl;
	// 一个表达式中，连续拷贝构造+拷贝构造->优化一个拷贝构造
	A aa2 = f2();
	cout << endl;
	// 一个表达式中，连续拷贝构造+赋值重载->无法优化
	aa1 = f2();
	cout << endl;
	return 0;
}