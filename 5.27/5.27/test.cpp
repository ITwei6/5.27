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
//        //sum a[n];//����n�ι��캯����
//        return sum::GetRet();
//    }
//};
//
//
//class Solution {
//    //Ĭ����˽�еģ�������ñ��˷��ʿ���дpublic
//    class sum {
//    public:
//        sum()//�ڲ��࣬�������ⲿ�����Ԫ������ʹ���ⲿ��ĳ�Ա��������ΪΪ��̬��Ա�����Բ���Ҫ����Ϳ���ʹ��
//        {
//            _ret += _i;
//            ++_i;
//        }
//    };
//public:
//    int Sum_Solution(int n) {
//
//       // sum a[n];//����n�ι��캯����
//        return _ret;//�������ֱ�ӷ��ء���ret��Ϊ��������ĳ�Ա����
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
//	A(2);//��������
//	cout << "----" << endl;
//	A aa1(1);//��������
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
//	Solution().Sum_Solution(10);//����������ó�Ա������һ���Ե�
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
	A aa1 = 2;//����+����---->�Ż��ɹ���
	
	A aa3 = Func1();//����+����-->һ�ο���
	
	cout << "----------" << endl;
	A aa5;//���캯��
	aa3 = Func1();//��������+��ֵ���������
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
	// ��ֵ����
	A aa1;
	f1(aa1);
	cout << endl;
	// ��ֵ����
	f2();
	cout << endl;
	// ��ʽ���ͣ���������+��������->�Ż�Ϊֱ�ӹ���
	f1(1);
	// һ�����ʽ�У���������+��������->�Ż�Ϊһ������
	f1(A(2));
	cout << endl;
	// һ�����ʽ�У�������������+��������->�Ż�һ����������
	A aa2 = f2();
	cout << endl;
	// һ�����ʽ�У�������������+��ֵ����->�޷��Ż�
	aa1 = f2();
	cout << endl;
	return 0;
}