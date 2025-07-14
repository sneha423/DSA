#include<iostream>
using namespace std;
class base{
	protected:
		static int count;
		public:
			base()
			{count++;
			}
			virtual ~base()
			{count--;
			}
			static void showcount()
			{cout<<"count:"<<count<<endl;
			}
};
int base::count=0;
class derived:public base{
	public:
	derived()
	{count++;
	}
	~derived()
	{count--;
	}
};
int main()
{base *b1=new base();
base *b2=new derived();
derived *d1=new derived();
base::showcount();
delete b1;
base::showcount();
delete b2;
base::showcount();
delete d1;
base::showcount();
return 0;

}