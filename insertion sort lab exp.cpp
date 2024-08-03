#include<iostream>
#include<vector>
#include<string>
using namespace std;
struct Student{
	int rollnumber;
	string name;
};
void insertionsort(vector<Student>&students)
{
	int n=students.size();
	for(int i=1;i<n;++i)
	{
		Student key=students[i];
		int j=i-1;
		while(j>=0&&students[j].name>key.name)
		{
			students[j+1]=students[j];
			j=j-1;
			
		}
		students[j+1]=key;
	}
}
int main()
{
	vector<Student>students={
		{101,"alice"},
		{103,"charlie"},
		{102,"bob"}
		};
		cout<<"before sorting"<<endl;
		for(const auto&student:students)
		{
			cout<<student.rollnumber<<":"<<student.name<<endl;
		}
		insertionsort(students);
		cout<<"after sorting"<<endl;
		for(const auto&student:students)
		{
			cout<<student.rollnumber<<":"<<student.name<<endl;
		}
		return 0;
	
}