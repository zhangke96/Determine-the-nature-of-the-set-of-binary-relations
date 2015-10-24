#include<iostream>
#include<vector>
#include<ctime>
#include<cstdlib>
using std::vector;
using std::cin;
using std::cout;
using std::endl;
int main()
{
	vector<char> a;                    //用来保存读入的集合
	int a_size=0;                        //用来保存读入集合的元素个数
	char a_temp;                       //用来保存接下来要读入的集合
	cout<<"请输入集合,按ctrl+z结束输入"<<endl;
	while(cin>>a_temp)
	{
		a.push_back(a_temp);
		++a_size;
	}
	cin.clear();
	cout<<"集合为"<<endl;
	int relation[a_size][a_size];
	for(int k=0;k<a_size;++k)
	{
		for(int l=0;l<a_size;++l)
			relation[k][l]=0;
	}
	for(vector<char>::iterator beg=a.begin();beg!=a.end();++beg)
		cout<<*beg<<" ";
	cout<<endl;
/*	for(int k=0;k<a_size;++k)
	{
		for(int l=0;l<a_size;++l)
			cout<<relation[k][l]<<" ";
		cout<<endl;
	}   */
	cout<<"请输入它们的关系集合,按ctrl+z结束输入"<<endl;
	vector<char> b;                  //用来保存读入的关系
	char b_temp;                    
	int b_size=0;					//用来保存读入关系的长度
	while(cin>>b_temp)
	{
		b.push_back(b_temp);
		++b_size;
	}
	int temp=0;
	int i=0;
	for(;i<b_size;++++i)
	{
		int x=0,y=0;
		for(int j=0;j<a_size;++j)
		{
			if(b[i]==a[j])
			{
				x=j;
				break;
			}
		}
		
		for(int j=0;j<a_size;++j)
		{
			if(b[i+1]==a[j])
			{
				y=j;
				break;
			}
		}
		relation[x][y]=1;
	}
/*	for(int k=0;k<a_size;++k)
	{
		for(int l=0;l<a_size;++l)
			cout<<relation[k][l]<<" ";
		cout<<endl;
	}    */
	//判断自反性
	int fan=0;
	for(int k=0;k<a_size;++k)
	{
		if(!relation[k][k])
		{
			cout<<"不满足自反性的反例: '"<<a[k]<<" "<<a[k]<<"' 不在关系里面"<<endl;
			fan=1;
		}
	
	}
	if(!fan)
		cout<<"满足自反性"<<endl;
	//判断反自反性
	int fanzi=0;
	for(int k=0;k<a_size;++k)
	{
		if(relation[k][k])
		{
			cout<<"不满足反自反性的反例: '"<<a[k]<<" "<<a[k]<<"'在关系里面"<<endl;
			fanzi=1;
		}
	}
	if(!fanzi)
		cout<<"满足反自反性"<<endl;
	//判断对称性
	int duichen=0;
	for(int k=0;k<a_size;++k)
	{
		for(int m=k;m<a_size;++m)
			if((relation[k][m]!=relation[m][k])&&relation[k][m])
			{
				cout<<"不满足对称性的反例: '"<<a[k]<<" "<<a[m]<<"'没有与之对称的关系"<<endl;
				duichen=1;
			}
	}
	if(!duichen)
		cout<<"满足对称性"<<endl;
	//判断反对称性
	int fanduichen=0;
	for(int k=0;k<a_size;++k)
	{
		for(int m=k;m<a_size;++m)
			if((relation[k][m]==relation[m][k])&&relation[k][m]&&k!=m)
			{
				cout<<"不满足反对称性的反例: '"<<a[k]<<" "<<a[m]<<"'有与之对称的关系"<<endl;
				fanduichen=1;
			}
	}
	if(!fanduichen)
		cout<<"满足反对称性"<<endl;
	//判断传递性
	int chuandi=0;
	for(int k=0;k<a_size;++k)
	{
		for(int m=0;m<a_size;++m)
		{
			if(relation[k][m])
			{
				for(int l=0;l<a_size;++l)
				{
					if(relation[m][l])
					{
						if(!relation[k][l])
						{
							cout<<"不满足传递性的反例: '"<<a[k]<<" "<<a[l]<<"'不在关系中"<<endl;
							chuandi=1;
						}
					}
				}
			}
		}
	}
	if(!chuandi)
		cout<<"满足传递性"<<endl;
	cout<<"下面自行生成关系"<<endl;
	srand(time(NULL));
	for(int temp_i=0;temp_i<a_size;++temp_i)
	{
		for(int temp_j=0;temp_j<a_size;++temp_j)
			relation[temp_i][temp_j]=rand()%2;
	}	
/*	for(int temp_i=0;temp_i<a_size;++temp_i)
	{
		for(int temp_j=0;temp_j<a_size;++temp_j)
		{
			cout<<relation[temp_i][temp_j]<<" ";
		}
		cout<<endl;
	}*/
	//输出生成的关系
	int judge=0;
	for(int temp_i=0;temp_i<a_size;++temp_i)
	{
		for(int temp_j=0;temp_j<a_size;++temp_j)
		{
			if(relation[temp_i][temp_j])
			{
				if(!judge)
					cout<<"{ ";
				if(judge)
					cout<<",";
				cout<<"<"<<a[temp_i]<<","<<a[temp_j]<<">";
				judge=1;
			}
		}
	}
	if(judge)
		cout<<" }"<<endl;
	//判断自反性
	 fan=0;
	for(int k=0;k<a_size;++k)
	{
		if(!relation[k][k])
		{
			cout<<"不满足自反性的反例: '"<<a[k]<<" "<<a[k]<<"' 不在关系里面"<<endl;
			fan=1;
		}
	
	}
	if(!fan)
		cout<<"满足自反性"<<endl;
	//判断反自反性
	fanzi=0;
	for(int k=0;k<a_size;++k)
	{
		if(relation[k][k])
		{
			cout<<"不满足反自反性的反例: '"<<a[k]<<" "<<a[k]<<"'在关系里面"<<endl;
			fanzi=1;
		}
	}
	if(!fanzi)
		cout<<"满足反自反性"<<endl;
	//判断对称性
	 duichen=0;
	for(int k=0;k<a_size;++k)
	{
		for(int m=k;m<a_size;++m)
			if((relation[k][m]!=relation[m][k])&&relation[k][m])
			{
				cout<<"不满足对称性的反例: '"<<a[k]<<" "<<a[m]<<"'没有与之对称的关系"<<endl;
				duichen=1;
			}
	}
	if(!duichen)
		cout<<"满足对称性"<<endl;
	//判断反对称性
	 fanduichen=0;
	for(int k=0;k<a_size;++k)
	{
		for(int m=k;m<a_size;++m)
			if((relation[k][m]==relation[m][k])&&relation[k][m]&&k!=m)
			{
				cout<<"不满足反对称性的反例: '"<<a[k]<<" "<<a[m]<<"'有与之对称的关系"<<endl;
				fanduichen=1;
			}
	}
	if(!fanduichen)
		cout<<"满足反对称性"<<endl;
	//判断传递性
	 chuandi=0;
	for(int k=0;k<a_size;++k)
	{
		for(int m=0;m<a_size;++m)
		{
			if(relation[k][m])
			{
				for(int l=0;l<a_size;++l)
				{
					if(relation[m][l])
					{
						if(!relation[k][l])
						{
							cout<<"不满足传递性的反例: '"<<a[k]<<" "<<a[l]<<"'不在关系中"<<endl;
							chuandi=1;
						}
					}
				}
			}
		}
	}
	if(!chuandi)
		cout<<"满足传递性"<<endl;
	return 0;
	
}
