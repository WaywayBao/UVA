#include<iostream>		//uva 10263
#include<cmath>
#include<iomanip>
#define Length(x,y) pow(((x)*(x))+((y)*(y)),0.5)
using namespace std;

struct vector{
	vector(double x,double y){
		this->x=x;
		this->y=y;
		length=Length(x,y);
	}
	double x;
	double y;
	double length;
};

int main(){
	double Xm,Ym,N,ans_x,ans_y,shortest_length;
	double segment_x[2],segment_y[2];
	while(cin>>Xm){		// M(Xm,Ym)
		cin>>Ym>>N;
		cin>>segment_x[0]>>segment_y[0];		//the first point
		shortest_length=0x3f3f3f3f;		//a temporarily variable to store minimal length
		ans_x=segment_x[0];		//if there no segment (only one point on coodinate, i.e. N=0) 
		ans_y=segment_y[0];
		for(int i=1;i<N+1;i++){
			cin>>segment_x[i%2]>>segment_y[i%2];		//input point alternate in array by loop
			vector v(segment_x[1]-segment_x[0],segment_y[1]-segment_y[0]);		//store vector from two corner-point
			double m1,m2,b1,b2,temp_x,temp_y;		//(temp_x,temp_y) is projection point
			if(v.x!=0&&v.y!=0){
				m1=v.y/v.x;		//y=mx+b
				b1=segment_y[0]-m1*segment_x[0];		//b=y-mx
				if(m1)
					m2=-1/m1;		//m1*m2=-1 if two lines are vertical each other
				b2=Ym-m2*Xm;
				temp_x=(b2-b1)/(m1-m2);		//m1*x+b1=m2*x+b2 ----> x=(b2-b1)/(m1-m2)
				temp_y=m1*temp_x+b1;
			}else if(v.x==0){		//if vector v is vertical x axis
				temp_x=segment_x[0];
				temp_y=Ym;
			}else{		//if vector v is vertical y axis
				temp_x=Xm;
				temp_y=segment_y[0];
			}
			vector u(segment_x[0]-temp_x,segment_y[0]-temp_y);		//store vector from projection point to corner-point (segment_x[0],segment_y[0])
			vector w(segment_x[1]-temp_x,segment_y[1]-temp_y);		//store vector from projection point to corner-point (segment_x[1],segment_y[1])
			if(u.length+w.length>v.length){		//if projection point not on the segment
				if(u.length>w.length){		//the shortest distance from M to segment is corner-point
					temp_x=segment_x[1];		
					temp_y=segment_y[1];
				}else{
					temp_x=segment_x[0];
					temp_y=segment_y[0];
				}
			}
			if(Length(temp_x-Xm,temp_y-Ym)<shortest_length){		//determine shortest length
				ans_x=temp_x;
				ans_y=temp_y;
				shortest_length=Length(temp_x-Xm,temp_y-Ym);
			}
		}
		cout<<fixed<<setprecision(4)<<ans_x<<endl;
		cout<<ans_y<<endl;
	}
	return 0;
} 




/* 
	vector v(segment_x[1]-segment_x[0],segment_y[1]-segment_y[0]);		//�N�K�y2���I�c�����V�q�s�bstruct�� 
	if(v.x!=0&&v.y!=0){		//�����u�ײv����0
		m1=v.y/v.x;		//y=mx+b (y�V�q���Hx�V�q�Y�����K�y�ײvm1) 
		b1=segment_y[0]-m1*segment_x[0];		//b=y-mx
		m2=-1/m1;		//m1*m2=-1 m2�O�������K�y�����u���ײv�A�]�⪽�u�������ܡA�ײv�ۭ���-1
		b2=Ym-m2*Xm; 
		temp_x=(b2-b1)/(m1-m2);		//m1*x+b1=m2*x+b2 ����----> x=(b2-b1)/(m1-m2)
		temp_y=m1*temp_x+b1;		//�⪽�u���I��(temp_x,temp_y) 
	}else if(v.x==0){		//�p�G�K�y�ײv���L���j(����x�b)�Ϊ��K�y���@�I 
		temp_x=segment_x[0];
		temp_y=Ym;
	}else{		//�p�G�K�y�ײv��0(����y�b)
		temp_x=Xm;
		temp_y=segment_y[0];
	}
	vector u(segment_x[0]-temp_x,segment_y[0]-temp_y);		//�x�s���I��@���K�y���I���V�q 
	vector w(segment_x[1]-temp_x,segment_y[1]-temp_y);		//�x�s���I��t�@�Ӻ��I���V�q 
	if(u.length+w.length>v.length){		//�p�G��V�q���׬ۥ[�j���K�y���ת�ܥ��I�b�K�y�~ 
		if(u.length>w.length){		//�̵u�Z�����K�y���I 
			temp_x=segment_x[1];		
			temp_y=segment_y[1];
		}else{
			temp_x=segment_x[0];
			temp_y=segment_y[0];
		}
	}
	if(Length(temp_x-Xm,temp_y-Ym)<shortest_length){		//�P�_�O�_���̵u���| 
		ans_x=temp_x;
		ans_y=temp_y;
		shortest_length=Length(temp_x-Xm,temp_y-Ym);
	}
*/ 





/*
#include<iostream>
#include<cmath>
#include<iomanip>
#define inf 0x3f3f3f3f
using namespace std;

struct vector{
	vector(double x,double y){
		this->x=x;
		this->y=y;
		length=pow(x*x+y*y,0.5);
	}
	double x;
	double y;
	double length;
};

int main(){
	double Xm,Ym,N,ans_x,ans_y,shortest_length;
	double segment_x[2],segment_y[2];
	while(cin>>Xm){		// M(Xm,Ym)
		cin>>Ym>>N;
		cin>>segment_x[0]>>segment_y[0];		//the first point
		shortest_length=inf;		//a temporarily variable to store minimal length
		ans_x=segment_x[0];		//if there no segment (only one point on coodinate, i.e. N=0) 
		ans_y=segment_y[0];
		for(int i=1;i<N+1;i++){
			cin>>segment_x[i%2]>>segment_y[i%2];		//input point alternate in array by loop
			vector v(segment_x[0]-Xm,segment_y[0]-Ym);		//store vector from M to corner-point A(segment_x[0],segment_y[0])
			vector u(segment_x[1]-Xm,segment_y[1]-Ym);		//store vector from M to corner-point B(segment_x[1],segment_y[1])
			vector w(segment_x[1]-segment_x[0],segment_y[1]-segment_y[0]);		//store vector from two corner-point
			if(pow(v.length,2)>=pow(u.length,2)+pow(w.length,2)){		//if projection point of M not on the segment and vector v length is longer than vector u and w
				if(u.length<shortest_length){		//the shortest distance from M to segment is the length of vector u
					shortest_length=u.length;
					ans_x=segment_x[1];		//corner-point B
					ans_y=segment_y[1];
				}
			}else if(pow(u.length,2)>=pow(v.length,2)+pow(w.length,2)){		//if projection point of M is not on the segment and vector u length is longer than vector v and w
				if(v.length<shortest_length){		//the shortest distance from M to segment is the length of vector v
					shortest_length=v.length;
					ans_x=segment_x[0];		//corner-point A
					ans_y=segment_y[0];
				}
			}
			else{		//projection of M is on the segment
				double tempx=segment_x[0]-Xm;
				double tempy=segment_y[0]-Ym;
				double t=-(w.x*tempx+w.y*tempy)/(w.x*w.x+w.y*w.y);
				double x=segment_x[0]+w.x*t;		//x coodinate of projection point
				double y=segment_y[0]+w.y*t;		//y coodinate of projection point
				double distance=pow((Xm-x)*(Xm-x)+(Ym-y)*(Ym-y),0.5);		//distance from M to projection point
				if(distance<shortest_length){
					shortest_length=distance;
					ans_x=x;
					ans_y=y;
				}
			}
		}
		cout<<fixed<<setprecision(4)<<ans_x<<endl;
		cout<<ans_y<<endl;
	}
	return 0;
} */
